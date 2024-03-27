#include "crc_counter/tools/calc_crc_table.h"

bool calc_crc8_table(uint8_t *crcTable,
                     uint8_t crcPolynom,
                     bool refIn,
                     uint8_t polyBitLen
        )
{
    if(crcTable == NULL
            || polyBitLen < 1
            || polyBitLen > 8
            )
    {
        return false;
    }

    for(uint16_t x = 0; x < 256; x++)
    {
        uint8_t crc = x;
        for(uint8_t i = 0; i < 8; i++)
        {
            if (refIn == true)
            {
                crc = (crc & 1) ? ( crc >> 1 ) ^ crcPolynom
                                :   crc >> 1 ;
            }
            else//refIn == false
            {
                crc = (crc & (1 << (polyBitLen - 1))) ? ( crc << 1 ) ^ crcPolynom
                                                      :   crc << 1 ;
            }
        *crcTable++ = crc;
        }
    }
    return true;
}
