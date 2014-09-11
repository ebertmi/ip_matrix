/*
 * main.c
 *
 *  Created on: 03.09.2014
 *      Author: Peter Emmerling
 */

#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>
#include "ip_matrix8x8.h"

int main(int argc, char* argv[]) {
	int fd;

	unsigned char arr2dim[8][8] = {{0,1,0,1,0,1,0,1},
			{1,0,1,0,1,0,1,0},
			{0,1,0,1,0,1,0,1},
			{1,0,1,0,1,0,1,0},
			{0,1,0,1,0,1,0,1},
			{1,0,1,0,1,0,1,0},
			{0,1,0,1,0,1,0,1},
			{1,0,1,0,1,0,1,0},
	};
	unsigned char arr2dim2[8][8] = {{1,0,1,0,1,0,1,0},
			{0,1,0,1,0,1,0,1},
			{1,0,1,0,1,0,1,0},
			{0,1,0,1,0,1,0,1},
			{1,0,1,0,1,0,1,0},
			{0,1,0,1,0,1,0,1},
			{1,0,1,0,1,0,1,0},
			{0,1,0,1,0,1,0,1},
	};

	fd = initi2c(); // init communication

	while (1) {
			printArray(fd,arr2dim);
			usleep(10000);
			printArray(fd,arr2dim2);
			usleep(10000);
	}

	return 0;
}
