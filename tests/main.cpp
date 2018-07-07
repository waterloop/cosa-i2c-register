#include <Cosa/UART.hh>
#include <Cosa/Trace.hh>

#include <wloop/i2c_register.h>

#define I2C_ADDR 0x40

using namespace wlp;

enum {
    CONFIG = 0x02,
    TAMB = 0x03,
} __attribute__((packed));


I2CRegister i2c_register{I2C_ADDR};

void setup() {
    uart.begin(9600);

    trace.begin(&uart);

    // write starting bit
    i2c_register.write16(CONFIG, 234);
}

void loop() {
    // read data
    auto rawData = i2c_register.read16(TAMB);

    trace << rawData << endl;
}
