/****************************************************************************
 * ip_matrix library for Informatik und Programmieren I course at the
 * university of coburg.
 *
 * @author Peter Emmerling (main)
 * @author Michael Ebert
 * Provides simple functions to control an adafruit 8x8 led matrix via i2c.
 *
 *
 *******************************************************************************/

#ifndef _IP_MATRIX8X8_H
#define _IP_MATRIX8X8_H

int writeCommand (int fd, uint8_t command);
int writeByte (int fd, uint8_t command, uint8_t data );
void printArray(int fd, unsigned char arr8x8[8][8]);
int initi2c();

#endif
