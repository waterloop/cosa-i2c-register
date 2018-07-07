/**
 * @file i2c_register.cpp
 * @brief Provides access to hardware registers over I2C
 *
 * This file contains implementation for for the I2C Register.
 *
 * @author Jeff Niu
 * @author Deep Dhillon
 * @date July 6, 2018
 * @bug No known bugs
 */


#include "wloop/i2c_register.hh"

using namespace wlp;

I2CRegister::I2CRegister(uint8_t i2c_addr)
        : m_driver(i2c_addr) {}

void I2CRegister::write8(uint8_t reg_addr, uint8_t data) {
    write_bytes<uint8_t>(reg_addr, data);
}

void I2CRegister::write16(uint8_t reg_addr, uint16_t data) {
    write_bytes<uint16_t>(reg_addr, data);
}

void I2CRegister::write32(uint8_t reg_addr, uint32_t data) {
    write_bytes<uint32_t>(reg_addr, data);
}

void I2CRegister::write64(uint8_t reg_addr, uint64_t data) {
    write_bytes<uint64_t>(reg_addr, data);
}

uint8_t I2CRegister::read8(uint8_t reg_addr) {
    return read_bytes<uint8_t>(reg_addr);
}

uint16_t I2CRegister::read16(uint8_t reg_addr) {
    return read_bytes<uint16_t>(reg_addr);
}

uint32_t I2CRegister::read32(uint8_t reg_addr) {
    return read_bytes<uint32_t>(reg_addr);
}

uint64_t I2CRegister::read64(uint8_t reg_addr) {
    return read_bytes<uint64_t>(reg_addr);
}
