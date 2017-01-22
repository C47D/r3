/*
 * https://www.kernel.org/doc/Documentation/gpio/sysfs.txt
 *
 *
 */


#include <stdint.h>
#include <stdio.h>

int main(){
    /* Reserve (export) the GPIO */
    int fd;
    char buffer[];
    int gpio = XX;

    fd = open("/sys/class/gpio/export", O_WRONLY);

    sprintf(buf, "%d", gpio);

    write(fd, buf, strlen(buf));

    close(fd);

    while ( 1 ) {
        

    }
}
