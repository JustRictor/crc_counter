#ifndef __CRC5_USB_H_
#define __CRC5_USB_H_

#include <stdint.h>

/**
 * \brief crc5 algorithm with poly 0x05
 * \param data [in] data array
 * \param len  [in] array len
 * \return crc
 * \note crc specification
 *      * Name:     CRC-5/USB
 *      * Width:    5
 *      * Poly:     0x05
 *      * Init:     0x1F
 *      * RefIn:    True
 *      * RefOut:   True
 *      * XorOut:   0x1F
 *      * Check:    0x19
 */
uint8_t crc5_usb(uint8_t const* data, uint64_t len);

#endif//__CRC5_USB_H_
