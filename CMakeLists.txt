cmake_minimum_required(VERSION 3.24)
project(MMGC VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(MMGC_BUILD_TESTS "Build MMGC tests" ON)
option(MMGC_ENABLE_LUAU "Build Luau runtime" OFF)
option(MMGC_ENABLE_8086TINY "Enable 8086tiny integration layer" OFF)

add_library(mmgc_core
    src/math/Vector3.cpp
    src/math/Matrix.cpp
    src/math/Expression.cpp
    src/physics/OrbitalMechanics.cpp
    src/navigation/StateVector.cpp
    src/guidance/GuidanceComputer.cpp
    src/cpu/Cpu8086.cpp
    src/machine/Machine.cpp
)

target_include_directories(mmgc_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(mmgc_core PUBLIC cxx_std_23)

add_executable(mmgc src/main.cpp)
target_link_libraries(mmgc PRIVATE mmgc_core)

if(MMGC_ENABLE_LUAU)
    include(FetchContent)
    FetchContent_Declare(luau
        GIT_REPOSITORY https://github.com/luau-lang/luau.git
        GIT_TAG master
        GIT_SHALLOW TRUE
    )
    set(LUAU_BUILD_CLI OFF CACHE BOOL "" FORCE)
    set(LUAU_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(LUAU_BUILD_WEB OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(luau)
    target_link_libraries(mmgc_core PUBLIC Luau.VM Luau.Compiler Luau.Bytecode)
    target_compile_definitions(mmgc_core PUBLIC MMGC_HAS_LUAU=1)
endif()

if(MMGC_ENABLE_8086TINY)
    message(STATUS "8086tiny integration is enabled as an MMGC adapter layer.")
    target_compile_definitions(mmgc_core PUBLIC MMGC_HAS_8086TINY=1)
endif()

if(MMGC_BUILD_TESTS)
    enable_testing()
    add_executable(mmgc_smoke tests/smoke.cpp)
    target_link_libraries(mmgc_smoke PRIVATE mmgc_core)
    add_test(NAME mmgc_smoke COMMAND mmgc_smoke)
endif()
