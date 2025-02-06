cmake_minimum_required(VERSION 3.13.4)
project(clang_compiler CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(LLVM 18.1.8 REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${CLANG_INCLUDE_DIRS})

add_definitions(${LLVM_DEFINITIONS})
add_executable(compiler main.cpp)

execute_process(
  COMMAND llvm-config-18 --libs lto
  OUTPUT_VARIABLE LLVM_LTO_LIBS
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

llvm_map_components_to_libnames(llvm_libs core CodeGen)

target_link_libraries(compiler
    PRIVATE
    clang-cpp
    ${llvm_libs}
    LLVM
    ${LLD_ELF_LIB}
    ${LLD_COMMON_LIB}
)

