#ifndef __CRC1_H_
#define __CRC1_H_

#include <stdint.h>

#define CRC1_POLY_REV 0x1

/**
 * \brief crc1 algorithm with poly 0x01
 * \param data [in] data array
 * \param len  [in] array len
 * \return crc
 * \note crc1 poly specification
 *      * Name:     CRC-1
 *      * Width:    1
 *      * Poly:     0x01
 *      * Init:     0x00
 *      * RefIn:    True
 *      * RefOut:   True
 *      * XorOut:   0x00
 *      * Check:    0x01
 */
uint8_t crc1(uint8_t const* data, uint64_t len);

#endif//__CRC1_H_
