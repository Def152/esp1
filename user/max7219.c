#include "spi.h"
#include "max7219.h"

#define SPI_DEV HSPI


void max7219_init(){
	//init SPI bus
	spi_init_gpio(SPI_DEV, SPI_CLK_USE_DIV);
	spi_clock(SPI_DEV, 10, 2); //10MHz
	spi_tx_byte_order(SPI_DEV, SPI_BYTE_ORDER_HIGH_TO_LOW);
	spi_rx_byte_order(SPI_DEV, SPI_BYTE_ORDER_HIGH_TO_LOW);

	SET_PERI_REG_MASK(SPI_USER(SPI_DEV), SPI_CS_SETUP|SPI_CS_HOLD);
	CLEAR_PERI_REG_MASK(SPI_USER(SPI_DEV), SPI_FLASH_MODE);

	//Enable hardware addressing & sequential addressing on all devices
	max7219_write(MAX7219_MODE_DECODE, 0xFF); // decode all digits

	max7219_write(MAX7219_MODE_SCAN_LIMIT, 7);
	max7219_write(MAX7219_MODE_INTENSITY, 0x08);
	max7219_write(MAX7219_MODE_POWER, 1);

}

void max7219_write(uint8 reg, uint8 value){
	spi_transaction(SPI_DEV, 0, 0, 8, reg, 8, value, 0, 0);
}

void max7219_clearDisplay(){
	uint8_t i;
	    for(i = 0; i < 8; i++){
	    	max7219_write(i, 0xF);
	    }
}

void max7219_writeInt(uint16_t num){
	uint8_t i = 0;
	while(num){
		max7219_write(++i, num % 10);
        // Actually divide by 10 now.
    	num /= 10;
	}
}

void max7219_writeName(){
	max7219_write(MAX7219_MODE_DECODE, 0x00); // turn off decode
	max7219_write(8, 0x67); // letter U
	max7219_write(MAX7219_MODE_DECODE, 0xFF); // turn off decode
	max7219_write(7, 5); // letter S

}

void max7219_writeFirst(uint16_t num){
	uint8_t i = 5;
	max7219_write(i, num|0x80);
}
