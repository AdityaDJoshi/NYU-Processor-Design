#include <VExercise3.h>
#include <cstdlib> 
#include <catch2/catch_test_macros.hpp>

uint8_t Mystery1(uint8_t a, uint8_t b, uint8_t c) {
  uint8_t result=0;
  switch(a) {
    case 0: result=((b & 0b111) << 3) + (c & 0b111);
            break;

    case 1: result=(0b01000000) + ((c & 0b111) << 3) + (b & 0b111);
            break;

    case 2: result=b;
            break;

    case 3: result=c;
            break;

  }
  return result;
}

uint16_t Mystery2(uint8_t a, uint8_t b, bool reset) {
  static uint8_t state;
  static uint16_t out;
  if (reset) {
    state = 0;
    out = (b << 8) | a; 
    return out;
  }
  else {
    switch(state) {
      case 0: {
        out = (a << 8) | (out & 0xFF);
        state++;
        return out; }
      case 1: {
        out = (out & (0xFF00)) | b; 
        state++;
        return out; }
      case 2: {
        out = (out << 8) | (out >> 8); 
        state++;
        return out; }
      case 3: {
        out = ((out << 12) & 0xF000) | ((out & (0xF0)) << 4) | ((out & (0xF00)) >> 4) | ((out & (0xF000)) >> 12);
        state++;
        return out;}
      case 4: {
        bool out_xor = out & 1;
        for (int k = 1; k < 16; k++) {
          out_xor ^= (out >> k) & 1;
        }
        out = out_xor;
        state = 0;
        return out; }
      default: return 0;
    }
  }
}


TEST_CASE("Testing mysteries"){
  // Test a variety of inputs
  VExercise3 model;
  bool reset;
  bool clk;
  uint8_t a;
  uint16_t b, c, result, num_iter=100;
  
  for (int i = 0; i < num_iter; i++) {
    
    //initalizing random numbers for inputs
    a = rand() % 0b1111;
    b = rand() % 0b1111111111111111; //FFFF we need 16 bit random numbers for b and c 
    c = rand() % 0b1111111111111111;


    model.clk = 1;
    model.reset = 0;
    model.eval();

    model.clk = 0;
    model.reset = 1;
    model.a = a;
    model.b = b;
    model.c = c;
    model.eval();
  

    uint8_t Alpha=Mystery1((a & 3), (b & 255), (c & 255));
    uint8_t Beta=Mystery1((a >> 2), (b >> 8), (c >> 8));

    result = Mystery2(Alpha, Beta, 1);
    REQUIRE(model.out == result);



    for (int j = 0; j < 6; j++) {
      model.clk = 1;
      model.reset = 0;
      model.eval();

      model.clk = 0;
      model.reset = 0;
      model.a = a;
      model.b = b;
      model.c = c;
      model.eval();

      Alpha=Mystery1((a & 3), (b & 255), (c & 255));
      Beta= Mystery1((a >> 2), (b >> 8), (c >> 8));
      result = Mystery2(Alpha,Beta, 0);
      REQUIRE(model.out == result);

    }
  }

}
