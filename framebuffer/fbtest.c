#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <errno.h>

#define RED_COLOR332    0xE0
#define GREEN_COLOR332  0x1C
#define BLUE_COLOR332   0x03

#define RED_COLOR565    0x0F100
#define GREEN_COLOR565  0x007E0
#define BLUE_COLOR565   0x0001F

/*
 * framebuffer application code, the start code of Linux GUI application
 * compile :
 *          $/usr/local/arm/2.95.3/bin/arm-linux-gcc -o fbtest fbtest.c
 *          $cp fbtest /tftpboot/examples
 * run in target:
 *          #mount 192.168.1.180:/tftpboot/ /mnt/nfs
 *          #cd /mnt/nfs/examples
 *          #./fbtest
 */
int main(int argc, char **argv)
{
    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    short *fbp565 = 0;
    char *fbp332 = 0;

    int x = 0, y = 0;
    long int location = 0;

    // Open the file for reading and writing
    fbfd = open("/dev/fb0", O_RDWR);
    if (!fbfd) {
        printf("Error: cannot open framebuffer device.\n");
        exit(1);
    }
    printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo)) {
        printf("Error reading fixed information.\n");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
        printf("Error reading variable information.\n");
        exit(3);
    }

    // Figure out the size of the screen in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    printf("%dx%d, %dbpp, screensize = %d\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel, screensize );

    // Map the device to memory
    fbp332 = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED,
                       fbfd, 0);
    fbp565 = (short*)fbp332;

    if ((int)fbp332 == -1) {
        printf("Error: failed to map framebuffer device to memory.\n");
        exit(4);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

    x = 100; y = 100;       // Where we are going to put the pixel

    if(vinfo.bits_per_pixel == 16)  // 8bpp only
    {
        // 8bpp framebuffer test
        printf("16 bpp framebuffer test\n");
        printf("a byte in fbp is a pixel of LCD, just set the value of fbp to put color to LCD\n");
        printf("byte format:\n");
        printf("  bit:| 7  6  5 |  4  3  2 | 1  0 |\n");
        printf("      |  red    |   green  | blue |\n");

        // Red Screen
        printf("Red Screen\n");
        for(y = 0; y < vinfo.yres/3;  y++)
        {
            for(x = 0; x < vinfo.xres ; x++)
            {
                *(fbp565 + y * vinfo.xres + x) = 0;
            }
        }

        // Green Screen
        printf("Green Screen\n");
        for(y = vinfo.yres/3; y < (vinfo.yres*2)/3; y++)
        {
            for(x = 0; x < vinfo.xres/2 - 59; x++)
            {
                *(fbp565 + y * vinfo.xres + x) =GREEN_COLOR565/2;
            }
        }

        // Blue Screen
        printf("Blue Screen\n");
        for(y = (vinfo.yres*2)/3; y < vinfo.yres; y++)
        {
            for(x = 0; x < vinfo.xres; x++)
            {
                *(fbp565 + y * vinfo.xres + x) = BLUE_COLOR565;
            }
        }
    }
    else if(vinfo.bits_per_pixel == 8)
    {
        // 8bpp framebuffer test
        printf("8bpp framebuffer test\n");
        printf("a byte in fbp is a pixel of LCD, just set the value of fbp to put color to LCD\n");
        printf("byte format:\n");
        printf("  bit:| 7  6  5 |  4  3  2 | 1  0 |\n");
        printf("      |  red    |   green  | blue |\n");

        // Red Screen
        printf("Red Screen\n");
        for(y = 0; y < vinfo.yres/3;  y++)
        {
            for(x = 0; x < vinfo.xres/2-100; x++)
            {
                *(fbp332 + y * vinfo.xres + x) = RED_COLOR332;
            }
        }

        // Green Screen
        printf("Green Screen\n");
        for(y = vinfo.yres/3; y < (vinfo.yres*2)/3; y++)
        {
            for(x = 0; x < vinfo.xres/2-50; x++)
            {
                *(fbp332 + y * vinfo.xres + x) = GREEN_COLOR332;
            }
        }

        // Blue Screen
        printf("Blue Screen\n");
        for(y = (vinfo.yres*2)/3; y < vinfo.yres; y++)
        {
            for(x = 0; x < vinfo.xres-10; x++)
            {
                *(fbp332 + y * vinfo.xres + x) = BLUE_COLOR332;
            }
        }
    }
    else
        printf("8/16 bits only!\n");

    munmap(fbp332, screensize);
    close(fbfd);
    return 0;
}
