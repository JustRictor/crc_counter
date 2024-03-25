cmake_minimum_required(VERSION 3.5)

project(crc_counter LANGUAGES C)

include_directories(include)

set(HEADERS_CRC_COUNTER
    include/crc_counter/crc_counter.h
    include/crc_counter/crc1.h
    )

set(SOURCES_CRC_COUNTER
    src/crc1.c
    )

add_library(crc_counter STATIC ${HEADERS_CRC_COUNTER} ${SOURCES_CRC_COUNTER})
