#ifndef __CRC3_ROHC_H_
#define __CRC3_ROHC_H_

#include <stdint.h>

#define CRC3_ROHC_POLY_REV 0x6

/**
 * \brief crc1 algorithm with poly 0x01
 * \param data [in] data array
 * \param len  [in] array len
 * \return crc
 * \note crc1 poly specification
 *      * Name:     CRC-3/ROHC
 *      * Width:    3
 *      * Poly:     0x03
 *      * Init:     0x07
 *      * RefIn:    True
 *      * RefOut:   True
 *      * XorOut:   0x00
 *      * Check:    0x06
 */
uint8_t crc3_rohc(uint8_t const* data, uint64_t len);

#endif//__CRC3_ROHC_H_
