#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

static uint8_t mode = SPI_MODE_1;
static uint8_t bits = 8;
static uint32_t speed = 10000;

static int configSPI(const char *slave);
static void pabort(const char *s);
static void transfer(int fd);

int main(int argc, char *argv[]){

    int ss0, ss1;

    const char *slave0 = "/dev/spidev0.0";
    const char *slave1 = "/dev/spidev0.1";

    /* Slave configuration */
    printf("Configuring slave0\r\n");
    ss0 = configSPI(slave0);
    printf("Configuring slave1\r\n");
    ss1 = configSPI(slave1);

    /* Start test */
    printf("Spi Mode: %d\n", mode);
    printf("Bits per word: %d\n", bits);
    printf("Max Speed: %d Hz (%d KHz)\n", speed, speed/1000);

    /* Start the transfers */
    /* Transfer using slave 0 */
    printf("\tTransfer using slave 0\r\n");
    transfer(ss0);
    close(ss0);
    
    sleep(1);

    printf("\tTransfer using slave 1\r\n");
    transfer(ss1);
    close(ss1);
        
    return 0;
}

static int configSPI(const char *slave){
    int ret, SSfd;

	/* Slave Select */
    SSfd = open(slave, O_RDWR);
    if(SSfd == -1){
        pabort("Can't open slave");
    }

    /* Set mode */
    ret = ioctl(SSfd, SPI_IOC_WR_MODE, &mode);
    if(ret == -1){
        pabort("Can't set SPI mode on ss0");
    }
    ret = ioctl(SSfd, SPI_IOC_RD_MODE, &mode);
    if(ret == -1){
        pabort("Can't set SPI mode on ss0");
    }
    /* Set bits per word */
    ret = ioctl(SSfd, SPI_IOC_WR_BITS_PER_WORD, &bits);
    if(ret == -1){
        pabort("Can't set bits per word on ss0");
    }
    ret = ioctl(SSfd, SPI_IOC_RD_BITS_PER_WORD, &bits);
    if(ret == -1){
        pabort("Can't set bits per word on ss0");
    }

    /* Set max speed */
    ret = ioctl(SSfd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
    if(ret == -1){
        pabort("Can't set max speed on ss0");
    }
    ret = ioctl(SSfd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
    if(ret == -1){
        pabort("Can't set max speed on ss0");
    }

    return SSfd;
}

static void transfer(int fd){
    int ret;
    uint8_t tx[] = {0x55, 0xc3, 0x3c, 0x01, 0x80, 0xff, 0x00};
    uint8_t rx[sizeof(tx)] = {0};
    struct spi_ioc_transfer tr = {
        .tx_buf = (unsigned long)tx,
        .rx_buf = (unsigned long)rx,
        .len = sizeof(tx),
        .delay_usecs = 50,
        .speed_hz = speed,
        .bits_per_word = bits,
        .cs_change = 0,
        .pad = 0,
    };

    ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
    if(ret < 1){
        pabort("Can't send spi message");
    }
        printf("rx:");
    for(ret = 0; ret < sizeof(tx); ret++){
        printf("%.2X,", rx[ret]);
    }
    printf("\r\n");
}

static void pabort(const char *s){
    perror(s);
    abort();
}
