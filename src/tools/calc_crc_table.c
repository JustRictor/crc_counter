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

bool calc_crc16_table(uint16_t *crcTable,
                     uint16_t crcPolynom,
                     bool refIn,
                     uint8_t polyBitLen
        )
{
    if(crcTable == NULL
            || polyBitLen < 9
            || polyBitLen > 16
            )
    {
        return false;
    }

    for(uint16_t x = 0; x < 256; x++)
    {
        uint16_t crc = ( x << (polyBitLen - 8) );
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

bool calc_crc32_table(uint32_t *crcTable,
                     uint32_t crcPolynom,
                     bool refIn,
                     uint8_t polyBitLen
        )
{
    if(crcTable == NULL
            || polyBitLen < 17
            || polyBitLen > 32
            )
    {
        return false;
    }

    for(uint16_t x = 0; x < 256; x++)
    {
        uint32_t crc = ( x << (polyBitLen - 8) );
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

bool calc_crc64_table(uint64_t *crcTable,
                     uint64_t crcPolynom,
                     bool refIn,
                     uint8_t polyBitLen
        )
{
    if(crcTable == NULL
            || polyBitLen < 33
            || polyBitLen > 64
            )
    {
        return false;
    }

    for(uint16_t x = 0; x < 256; x++)
    {
        uint64_t crc = ( x << (polyBitLen - 8) );
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
