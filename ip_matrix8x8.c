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
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>

#include "ip_matrix.h"

/*  Writes the given command to the i2c.
 *  Returns -1 when failing to write the command
 *
 */
void writeCommand (int fd, uint8_t command)
{
    int result = i2c_smbus_write_byte(fd, command);
    if (result == -1)
    {
        printf("Failed to write command to I2C.\n");
    }

    return -1;
}

void writeByte (int fd, uint8_t command, uint8_t data ) {
    int result = i2c_smbus_write_byte_data(fd, command, data);
    if (result == -1) {
        printf("Failed to write byte to I2C.\n");
    }
}

/*
 * Outputs the given array to the matrix. 1 = LED on, 0 = LED off
 * The array entries map to the matrix LEDs position
 */
void printArray(int fd, unsigned char arr8x8[8][8]){
    unsigned char i,j;
    unsigned char arr[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            if (arr8x8[i][j]!=0) {
                arr[i]|=(1<<j);
            } else {
                arr[i]&=~(1<<j);
            }
        }
    }

    for (i=0; i<16; i=i+2) {
        writeByte(fd,i,arr[i/2]);
    }
    usleep(500000);
    return;
}

/*
 * Initializes the communication via i2c.
 * Also starts the oscillator
 * Display on, blinking off
 * Full brightness
 * Start writing to address 0
 */
int initi2c(){
    int fd;
    fd = open("/dev/i2c-1", O_RDWR);
    if (fd == -1) {
        printf("Failed to open I2C device.\n");
    }

    int result = ioctl(fd, I2C_SLAVE, 0x70);

    if (result == -1) {
        printf("Failed to set address.\n");
    }

    writeCommand(fd,0x21); // Start oscillator (page 10)
    writeCommand(fd,0x81); // Display on, blinking off (page 11)
    writeCommand(fd,0xef); // Full brightness (page 15)
    writeCommand(fd,0x00); // Start writing to address 0 (page 13)
    return fd;
}
