cmake_minimum_required(VERSION 3.20)

project(box3cpp
    VERSION 0.1.0
    DESCRIPTION "Small C++20 RAII wrapper for Box3D"
    LANGUAGES CXX
)

add_library(box3cpp INTERFACE)
add_library(box3cpp::box3cpp ALIAS box3cpp)

target_compile_features(box3cpp INTERFACE cxx_std_20)

target_include_directories(box3cpp
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

option(BOX3CPP_BUILD_EXAMPLES "Build box3cpp examples" ON)

if(BOX3CPP_BUILD_EXAMPLES)
    add_executable(box3cpp_hello examples/hello_box3cpp.cpp)
    target_link_libraries(box3cpp_hello PRIVATE box3cpp::box3cpp)
endif()

option(BOX3CPP_BUILD_TESTS "Build box3cpp tests" ON)

if(BOX3CPP_BUILD_TESTS)
    enable_testing()

    add_executable(box3cpp_smoke_test tests/smoke_test.cpp)
    target_link_libraries(box3cpp_smoke_test PRIVATE box3cpp::box3cpp)

    add_test(NAME box3cpp_smoke_test COMMAND box3cpp_smoke_test)
endif()
