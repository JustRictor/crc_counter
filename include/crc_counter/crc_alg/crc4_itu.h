#ifndef __CRC4_ITU_H_
#define __CRC4_ITU_H_

#include <stdint.h>

#define CRC4_ITU_POLY_REV 0xC

/**
 * \brief crc4 algorithm with poly 0x03
 * \param data [in] data array
 * \param len  [in] array len
 * \return crc
 * \note poly specification
 *      * Name:     CRC-4/ITU
 *      * Width:    4
 *      * Poly:     0x03
 *      * Init:     0x00
 *      * RefIn:    True
 *      * RefOut:   True
 *      * XorOut:   0x00
 *      * Check:    0x07
 */
uint8_t crc4_itu(uint8_t const* data, uint64_t len);

#endif//__CRC4_ITU_H_
