#include <VExercise4.h>
#include <cstdlib> 
#include <catch2/catch_test_macros.hpp>

uint8_t cases(uint8_t alpha, uint8_t beta, uint8_t gamma, bool cs, uint8_t sel) {
uint8_t result=0;
  if (cs) {
    switch(sel) {
      
      case 0: result= alpha;
              break;

      case 1: result= beta;
              break;

      case 2: result= gamma;
              break;

      case 3: result= alpha & (beta | gamma);
              break;


    }
  }
return result;
}


TEST_CASE("DC is not detective comics"){

  VExercise4 model;
  uint8_t alpha,beta, gamma, result, cs;

  cs=0;
  model.cs = cs;


    alpha = rand();
    beta = rand();
    gamma = rand();

      for (int sel = 0; sel < 4; sel++) {
        model.alpha = alpha;
        model.beta = beta;
        model.gamma = gamma;
        model.sel = sel;
        model.eval();

        result = cases(alpha, beta, gamma, cs, sel);
        printf("The values in the dont care case is model's result:%d function's result:%d\n", model.out, result);
        REQUIRE(model.out == result);

      }

  
  cs=1;


    alpha = rand();
    beta = rand();
    gamma = rand();

      for (int sel = 0; sel < 4; sel++) {
        model.alpha = alpha;
        model.beta = beta;
        model.gamma = gamma;
        model.cs = cs;
        model.sel = sel;
        model.eval();

        result = cases(alpha, beta, gamma, cs, sel);

        REQUIRE(model.out == result);

      }



}
