cmake_minimum_required(VERSION 3.5)

option(ENABLE_TESTS "Enable testing for lib" OFF)

if(ENABLE_TESTS)
    project(crc_counter LANGUAGES CXX C)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
else()
    project(crc_counter LANGUAGES C)
endif()

include_directories(include)

set(HEADERS_CRC_COUNTER
    include/crc_counter/crc_counter.h
    include/crc_counter/crc1.h
    )

set(SOURCES_CRC_COUNTER
    src/crc1.c
    )

add_library(crc_counter STATIC ${HEADERS_CRC_COUNTER} ${SOURCES_CRC_COUNTER})

if(ENABLE_TESTS)
    Include(FetchContent)

    FetchContent_Declare(
      Catch2
      GIT_REPOSITORY https://github.com/catchorg/Catch2.git
      GIT_TAG        v3.4.0
    )
    FetchContent_MakeAvailable(Catch2)

    set(TESTS_SOURCES
            test/check_crc_test.cpp
        )
    add_executable(test ${TESTS_SOURCES})
    target_link_libraries(test PRIVATE
            Catch2::Catch2WithMain
            crc_counter
        )
endif()
