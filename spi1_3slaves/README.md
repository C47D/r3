## Enable SPI interface
From the awesome [Raspberry Pi Arch Linux Wiki]
(https://wiki.archlinux.org/index.php/Raspberry_Pi#SPI):

And Raspberry Pi Device Tree Overlay README

> To enable the /dev/spidev* devices, add (or uncomment) the following line on 
> /boot/config.txt:
>
> ```bash
> dtparam=spi=on
> dtoverlay=spi1-3cs
> ```

dtparam=spi=on will enable the SPI peripheral.
dtoverlay=spi1-3cs will enable the spi1 device and 3 chip select (slave select)
lines, this lines are by default at pin# , and .

Then reboot the rpi3 and check if spi1 is sucesfully enabled with the following
command:
```bash
$ ls /dev/spi*
/dev/spidev1.0 /dev/spidev1.1 /dev/spidev1.2
```
The SPI is enumerated as following:

spidev**B**.**C** where:

B: SPI Device.

C: Slave

If you see the previous response spi1 device was successfully enabled,
now you can continue to build and test the 
project.

## Build and test it:

|**SPI Line**  | **GPIO Name** | **Pin#** |
|:---------:|:---------:|:-----:|
| MOSI      | GPIO10    | 19    |
| MISO      | GPIO09    | 21    |
| SCLK      | GPIO11    | 23    |
| SS0       | GPIO08    | 24    |
| SS1       | GPIO07    | 26    |

Go to the project directory and type:
```bash
$ make clean
$ make
$ ./spi1_3slaves
```
If you have MISO pin not connected you should get as result:
```bash
Configuring slave0
Configuring slave1
Configuring slave2


Spi Mode: 1
Bits per word: 8
Max Speed: 10000 Hz (10 KHz)
    Transfer using slave 0
rx:00,00,00,00,00,00,00,
    Transfer using slave 1
rx:00,00,00,00,00,00,00,
    Transfer using slave 2
rx:00,00,00,00,00,00,00,
```
If you connect MOSI <----> MISO pins with a external wire you should get as 
result:
```bash
Configuring slave0
Configuring slave1
Configuring slave2


Spi Mode: 1
Bits per word: 8
Max Speed: 10000 Hz (10 KHz)
    Transfer using slave 0
rx:0x55,0xc3,0x3c,0x01,0x80,0xff,0x00,
    Transfer using slave 1
rx:0x55,0xc3,0x3c,0x01,0x80,0xff,0x00,
    Transfer using slave 2
rx:0x55,0xc3,0x3c,0x01,0x80,0xff,0x00,
```

## TODO

- [ ] Improve makefile.
- [ ] Add LA capture pictures. 
