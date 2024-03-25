#ifndef __CRC1_H_
#define __CRC1_H_

#include "stdint.h"

#define CRC1_POLY 0x1

uint8_t crc1(uint8_t* data, uint64_t len);

#endif//__CRC1_H_
