# Cosa I2C Registers

This is a wio package for Cosa that allows easy access to AVR registers over I2C bus. The package wraps all the system calls

## Usage

Define a register using `I2CRegister i2c_register{I2C_ADDRESS}`. Provide the register with I2C address.

Wriite data using:
```cpp
i2c_register.write16(REGISTER_ADDRESS, DATA);
```

Read data using:
```cpp
i2c_register.write16(REGISTER_ADDRESS);
```


## Install
```bash
wio install cosa-i2c-register
```

