/*
 * MASTER.c
 *
 *  Created on: Sep 13, 2019
 *      Author: Ghagas
 */
#include <avr/io.h>
#include <util/delay.h>
#define DDR_SPI DDRB
#define DD_SS DDB0
#define DD_SCK DDB1
#define DD_MOSI DDB2
#define DD_MISO DDB3

int main(void) {
	/* Set MOSI and SCK output, all others input */
	DDR_SPI = (1 << DD_MOSI) | (1 << DD_SCK);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
	while (1) {
		SPDR = 0xAA;
		/* Wait for transmission complete */
		while (!(SPSR & (1 << SPIF)));
	}
}

