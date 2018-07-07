/**
 * @file i2c_register.hh
 * @brief Provides access to hardware registers over I2C
 *
 * This file contains interface for the I2C Register. It is used for reading and writing registers over
 * I2C from various sensors.
 *
 * @author Jeff Niu
 * @author Deep Dhillon
 * @date July 6, 2018
 * @bug No known bugs
 */

#ifndef I2CREGISTER_HH
#define I2CREGISTER_HH

#include <Cosa/TWI.hh>

namespace wlp {

    class I2CRegister {
    public:
        explicit I2CRegister(uint8_t i2c_addr);

        /**
         * Read 8 bit data from register address provided
         *
         * @param reg_addr the register address on the I2C device
         * @return data read from register encoded encoded in 8 bit integer
         */
        uint8_t read8(uint8_t reg_addr);

        /**
         * Read 16 bit data from register address provided
         *
         * @param reg_addr the register address on the I2C device
         * @return data read from register encoded encoded in 16 bit integer
         */
        uint16_t read16(uint8_t reg_addr);

        /**
         * Read 32 bit data from register address provided
         *
         * @param reg_addr the register address on the I2C device
         * @return data read from register encoded encoded in 32 bit integer
         */
        uint32_t read32(uint8_t reg_addr);

        /**
         * Read 64 bit data from register address provided
         *
         * @param reg_addr the register address on the I2C device
         * @return data read from register encoded encoded in 64 bit integer
         */
        uint64_t read64(uint8_t reg_addr);

        /**
         * Write 8 bit data to register address provided
         *
         * @param reg_addr the register address on the I2C device
         * @param data the write data encoded in 8 bit integer
         */
        void write8(uint8_t reg_addr, uint8_t data);

        /**
         * Write 16 bit data to register address provided
         *
         * @param reg_addr the register address on the I2C device
         * @param data the write data encoded in 16 bit integer
         */
        void write16(uint8_t reg_addr, uint16_t data);

        /**
         * Write 32 bit data to register address provided
         *
         * @param reg_addr the register address on the I2C device
         * @param data the write data encoded in 32 bit integer
         */
        void write32(uint8_t reg_addr, uint32_t data);

        /**
         * Write 64 bit data to register address provided
         *
         * @param reg_addr the register address on the I2C device
         * @param data the write data encoded in 64 bit integer
         */
        void write64(uint8_t reg_addr, uint64_t data);

        /**
         * Read up to 8 bytes from a register.
         *
         * @tparam Integer integer type that contains the bytes
         * @param reg_addr the register address on the I2C device
         * @return the read data encoded in an integer
         */
        template<typename Integer>
        Integer read_bytes(uint8_t reg_addr);

        /**
         * Write up to 8 bytes to a register.
         *
         * @tparam Integer integer type that contains the bytes
         * @param reg_addr the register address on the I2C device
         * @param data     the data encoded in an integer
         */
        template<typename Integer>
        void write_bytes(uint8_t reg_addr, Integer data);

        /**
         * Read the number of bytes from a register.
         *
         * @tparam count    number of bytes to read
         * @param reg_addr  the register address on the I2C device
         * @param dest      buffer to store data into
         * @return          true or false based on if data has been read
         */
        template<uint8_t count>
        bool read_bytes(uint8_t reg_addr, uint8_t *dest);

    private:
        TWI::Driver m_driver;
    };

    template<typename Integer>
    Integer I2CRegister::read_bytes(uint8_t reg_addr) {
        constexpr auto bytes = static_cast<uint8_t>(sizeof(Integer));
        auto ret = static_cast<Integer>(0);
        twi.acquire(&m_driver);
        twi.write(&reg_addr, 1);
        twi.read(&ret, bytes);
        twi.release();
        return ret;
    }

    template<typename Integer>
    void I2CRegister::write_bytes(uint8_t reg_addr, Integer data) {
        constexpr auto bytes = static_cast<uint8_t>(sizeof(Integer));
        twi.acquire(&m_driver);
        twi.write(&reg_addr, 1);
        twi.write(&data, bytes);
        twi.release();
    }

    template<uint8_t count>
    bool I2CRegister::read_bytes(uint8_t reg_addr, uint8_t *dest) {
        twi.acquire(&m_driver);
        if (twi.write(&reg_addr, 1) < 0 || twi.read(dest, count) < 0) {
            return false;
        }
        twi.release();
        return true;
    }
}

#endif //I2CREGISTER_HH
