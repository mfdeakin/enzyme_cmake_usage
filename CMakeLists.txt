cmake_minimum_required(VERSION 3.22)
project(enzyme_test)

set(CMAKE_CXX_STANDARD 14)

set(enzyme_dir "/home/michael/programming/Enzyme/enzyme/build-llvm14")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xclang -load -Xclang ${enzyme_dir}/Enzyme/ClangEnzyme-14.so -flegacy-pass-manager")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fplugin=${enzyme_dir}/Enzyme/ClangEnzyme-14.so -flegacy-pass-manager")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld -Wl,-mllvm=-load=${enzyme_dir}/Enzyme/LLDEnzyme-14.so")

add_executable(enzyme_test main.cpp)

set_property(TARGET enzyme_test PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
