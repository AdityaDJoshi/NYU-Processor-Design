# NYU-Processor-Design

## Lab 1 Notes

The version of cmake running on my local environment is 3.28.3(Major: 3, Minor:28, Patch:3)

```bash
(base) MacBook-Pro:Lab1 adityajoshi$ cmake --version
cmake version 3.28.3

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```
The output of `make help` is
```zsh
(base) MacBook-Pro:build adityajoshi$ make help
The following are some of the valid targets for this Makefile:
... all (the default if no target is provided)
... clean
... depend
... edit_cache
... rebuild_cache
... hello_world
... helloWorld.o
... helloWorld.i
... helloWorld.s
```
Running `make` with all three helloWorld files gives hints to what they're used for(another easier way is to go through the )
```zsh
(base) MacBook-Pro:build adityajoshi$ make helloWorld.i
Preprocessing CXX source to CMakeFiles/hello_world.dir/helloWorld.cpp.i
(base) MacBook-Pro:build adityajoshi$ make helloWorld.s
Compiling CXX source to assembly CMakeFiles/hello_world.dir/helloWorld.cpp.s
(base) MacBook-Pro:build adityajoshi$ make helloWorld.o
```
The .i file is related to Preprocessing. In the context of C++ this encompasses things like  preprocessor directives like `#include`, `#define`, `#pragma`, `#error` and many more like conditional inclusions and line definitions.

The .s file is an assembly file from the source file. Assembly files contain low-level representations of the code, closer to machine language than high-level source code.

The .o file is an object file, these contain compiled codes, but cannot be executed directly. The .o files are linked to form executables. 

```zsh
(base) MacBook-Pro:build adityajoshi$ make all
[100%] Built target hello_world
(base) MacBook-Pro:build adityajoshi$ make clean
```

The `make clean` command put simply reverts the directory where it is run back to its state before the make command was run. It does this by removing the generated files (the .o files, executables, and  other generated files not part of the source code).

The `make all` command needs to be referred to the Makefile (lines 89-93), this is the command thats run when `make` is run without a target. 
```makefile
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/adityajoshi/Documents/NYU-Processor-Design/Lab1/build/CMakeFiles /Users/adityajoshi/Documents/NYU-Processor-Design/Lab1/build//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/adityajoshi/Documents/NYU-Processor-Design/Lab1/build/CMakeFiles 0
.PHONY : all
```

Relative Paths for target_sources and target_include_directories:
The paths are relative to the the CML file(in which they are used) and are in our case navigated from the root folder ie the Lab1 folder into the respective include and src folders. 

Cmake and Ninjas differences:
From what I understand these adjectives and their following explainations cover all the differences. So CMake is a build generator, that "generates" files that can then be built and doesn't directly execute build commands. Ninja is a build tool that directly executes build commands based on a build file. CMake is meant to promote cross platform development while allowing complex Turing Complete logics like conditions and loops. Ninja is meant to promote simplicity and quickness for large projects. It does not have a programmable/customisable build file ie as devs one must rely on CMake to accomodate these bells and whistles into a Ninja build. I referred to these to understand the differences [link1](https://www.reddit.com/r/embedded/comments/sbhg3q/can_you_help_me_understand_what_the_difference_of/), [link2](https://iq.opengenus.org/cmake-vs-ninja/) and [link3](https://www.youtube.com/watch?v=YbgH7yat-Jo)

Why run CMake in a seperate build directory? Convenience and dev friendly sums up why for me. In essence we can make minor changes and compare two build results while making changes to the CML without erroneously overwriting these two builds. Also having these build results in the same directory as source code isn't super organised and aesthetically pleasing. 