## Enable SPI interface
From the awesome [Raspberry Pi Arch Linux Wiki]
(https://wiki.archlinux.org/index.php/Raspberry_Pi#SPI):

> To enable the /dev/spidev* devices, add (or uncomment) the following line on 
> /boot/config.txt:
>
> ```bash
> dtparam=spi=on
> ```

This will enable the spi0 device used in this example, then reboot the rpi3 and
check if spi0 is successfuly enabled with the following command:
```bash
$ ls /dev/spi*
/dev/spidev0.0 /dev/spidev0.1
```
Both devices are enumerated as following:

spidev**B**.**C** where:

B: SPI Device.

C: Slave

If you see the previous response spi0 device was successfuly enabled,
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
$ ./spi2ss
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

- [ ] Improve makefile.
- [ ] Add LA capture pictures. 
