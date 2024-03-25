#include "crc_counter/crc1.h"

uint8_t crc1(uint8_t* data, uint64_t len)
{
    uint8_t crc = 0x00;
    while(len--)
    {
        crc ^= *data++;
        for(uint8_t i = 0; i < 8; i++)
        {
            crc = crc & 0x01 ? ( crc << 1 ) ^ CRC1_POLY
                             :   crc << 1 ;
        }
    }
    return crc;
}
