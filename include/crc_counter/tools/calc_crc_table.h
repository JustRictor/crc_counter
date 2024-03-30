#ifndef __CALC_CRC_TABLE_H_
#define __CALC_CRC_TABLE_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

bool calc_crc8_table(uint8_t* crcTable,
                     uint8_t crcPolynom,
                     bool refIn,
                     uint8_t polyBitLen
        );

bool calc_crc16_table(uint16_t* crcTable,
                     uint16_t crcPolynom,
                     bool refIn,
                     uint8_t polyBitLen
        );

bool calc_crc32_table(uint32_t* crcTable,
                     uint32_t crcPolynom,
                     bool refIn,
                     uint8_t polyBitLen
        );

bool calc_crc64_table(uint64_t* crcTable,
                     uint64_t crcPolynom,
                     bool refIn,
                     uint8_t polyBitLen
        );

#endif//__CALC_CRC_TABLE_H_
