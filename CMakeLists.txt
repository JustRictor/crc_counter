cmake_minimum_required(VERSION 3.5)

option(ENABLE_TESTS "Enable testing for lib" OFF)

project(crc_counter LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(HEADERS_CRC_COUNTER
    include/crc_counter/crc_counter.h
    include/crc_counter/crc_polynomes.h
    # ----------- tools ----------- #
    include/crc_counter/tools/calc_crc_table.h
    # ----------- algs  ----------- #
    include/crc_counter/crc_alg/crc1.h
    include/crc_counter/crc_alg/crc3_rohc.h
    include/crc_counter/crc_alg/crc4_itu.h
    include/crc_counter/crc_alg/crc8.h
    )

set(SOURCES_CRC_COUNTER
    # ----------- tools ----------- #
    src/tools/calc_crc_table.c
    # ----------- algs  ----------- #
    src/crc_alg/crc1.c
    src/crc_alg/crc3_rohc.c
    src/crc_alg/crc4_itu.c
    src/crc_alg/crc8.c
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
            test/test_check_crc.cpp
            test/test_calc_crc_table.cpp
        )
    add_executable(test ${TESTS_SOURCES})
    target_link_libraries(test PRIVATE
            Catch2::Catch2WithMain
            crc_counter
        )
endif()
