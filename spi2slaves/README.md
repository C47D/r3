## Build and test it:

| SPI Line  | GPIO Name | Pin#  |
| --------- |:---------:| -----:|
| MOSI      | GPIO10    | 19    |
| MISO      | GPIO09    | 21    |
| SCLK      | GPIO11    | 23    |
| SS0       | GPIO08    | 24    |
| SS1       | GPIO07    | 26    |

Go to the project directory and type:
```bash
$ make clean
$ make
$ ./spi2ss.out
```
If you have MISO pin not connected you should get as result:
```bash
Configuring slave0
Configuring slave1
Spi Mode: 1
Bits per word: 8
Max Speed: 10000 Hz (10 KHz)
    Transfer using slave 0
rx:00,00,00,00,00,00,00,
    Transfer using slave 1
rx:00,00,00,00,00,00,00,
```
If you connect MOSI <----> MISO pins with a external wire you should get as 
result:
```bash
Configuring slave0
Configuring slave1
Spi Mode: 1
Bits per word: 8
Max Speed: 10000 Hz (10 KHz)
    Transfer using slave 0
rx:0x55,0xc3,0x3c,0x01,0x80,0xff,0x00,
    Transfer using slave 1
rx:0x55,0xc3,0x3c,0x01,0x80,0xff,0x00,
```

## TODO

- [ ]Improve makefile.
- [ ]Add LA capture pictures. 
