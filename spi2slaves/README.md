## Build and test it:
        Pin:
MOSI:
MISO:
SCLK:
SS0:
SS1:

Go to the project directory and type:
```bash
make clean
make
./spi2ss.out
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

- []Improve makefile.
- []Add LA capture pictures. 
