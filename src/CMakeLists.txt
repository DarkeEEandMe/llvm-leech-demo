cmake_minimum_required(VERSION 3.10)
project(LLVM_Leech)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Locate LLVM package
find_package(LLVM REQUIRED CONFIG)

# Include LLVM headers
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# LLVM pass (shared library)
add_library(inject_payload_pass MODULE inject_payload_pass.cpp)

# Link against LLVM libraries
llvm_map_components_to_libnames(llvm_libs support core irreader passes)
target_link_libraries(inject_payload_pass ${llvm_libs})
