#C Library for Adafruit 8x8 LED Matrix via i2c

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
