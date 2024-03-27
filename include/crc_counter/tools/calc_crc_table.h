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

#endif//__CALC_CRC_TABLE_H_
