#ifndef INCLUDE_DRIVER_MAX7219_H_
#define INCLUDE_DRIVER_MAX7219_H_

#define MAX7219_MODE_DECODE       0x09
#define MAX7219_MODE_INTENSITY    0x0A
#define MAX7219_MODE_SCAN_LIMIT   0x0B
#define MAX7219_MODE_POWER        0x0C
#define MAX7219_MODE_TEST         0x0F

#define MAX7219_DIGIT0            0x01
#define MAX7219_DIGIT1            0x02
#define MAX7219_DIGIT2            0x03
#define MAX7219_DIGIT3            0x04
#define MAX7219_DIGIT4            0x05
#define MAX7219_DIGIT5            0x06
#define MAX7219_DIGIT6            0x07
#define MAX7219_DIGIT7            0x08

void max7219_init();
void max7219_write(uint8_t reg, uint8_t value);
void max7219_clearDisplay();
void max7219_writeInt(uint16_t num);
void max7219_writeFirst(uint16_t num);
void max7219_writeName();
//void max7219_clearDisplay();

#endif /* INCLUDE_DRIVER_MAX7219_H_ */
