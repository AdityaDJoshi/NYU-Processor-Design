find_package(Catch2 3 REQUIRED CONFIG)
add_executable(tests)
target_sources(exercise1.cpp exercise2.cpp exercise3.cpp exercise4.cpp)
# target_include_directories(hello_world PRIVATE include)
nyu_link_sv(tests PRIVATE lab4)
nyu_target_verilate(tests
  TOP_MODULES Exercise1 Exercise2 Exercise3 Exercise4
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
include(Catch)
catch_discover_tests(tests)