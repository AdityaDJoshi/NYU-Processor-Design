#include <catch2/catch_test_macros.hpp>
#include <VExercise2.h>
#include <cstdlib> // Include the <cstdlib> header for rand() function

uint16_t fun(uint16_t curr) {
  return (curr << 1) + (((curr >> 10) & 1) ^ ((curr >> 8) & 1) ^ ((curr >> 3) & 1) ^ ((curr >> 1) & 1));
}

TEST_CASE("Testing LFSR with fun() function") {
  // Test a variety of inputs
  VExercise2 model;

  model.reset = 0;
  model.clk = 1;
  model.eval();
  uint16_t state = model.out;

  // Test a variety of inputs
  for(int i = 0; i < 420; i++) {
    // Generate a random input value, but keep it within base 16 limits (max of 65535)
    uint16_t random_input = rand() % 0xFFFF;

    model.clk = 0;
    model.eval();

    // Set the random input value
    model.init = random_input;

    // Compute the next state of the LFSR using calc_fib function
    state = fun(state);


    REQUIRE(model.out == state);
    model.clk = 1;
    model.eval();
  }
}
