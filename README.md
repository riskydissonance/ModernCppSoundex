# Soundex

A structured implementation of the first **Soundex** example from Chapter 2 of **Modern C++ Programming with Test-Driven Development**.

This was developed on **Windows** and includes some details to make that work.

## Building

We use [CMake](https://cmake.org/):

```
mkdir build
cd build
cmake ..
```

Then you can use the build/soundex.sln file in Visual Studio.

## Google Test

[Google test](https://github.com/google/googletest) is downloaded and built as part of this project, the details are in **test/CMakeLists.txt**.