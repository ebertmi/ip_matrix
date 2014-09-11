#C Library - Adafruit 8x8 LED Matrix via i2c
Simple library for education purposes with an raspberry pi and
a LED matrix

##Usage
```c
  #include "ip_matrix8x8.h"

  unsigned char arr2dim[8][8] = {{0,1,0,1,0,1,0,1},
      {1,0,1,0,1,0,1,0},
      {0,1,0,1,0,1,0,1},
      {1,0,1,0,1,0,1,0},
      {0,1,0,1,0,1,0,1},
      {1,0,1,0,1,0,1,0},
      {0,1,0,1,0,1,0,1},
      {1,0,1,0,1,0,1,0},
  };

  int fd;
  fd = initi2c(); // init communication
  printArray(fd, arr2dim);
```
