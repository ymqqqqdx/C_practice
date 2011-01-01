#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
int main(int argc, const char *argv[])
{
    struct fb_var_screeninfo fb_var;
    int fd=open("/dev/fb0",O_RDWR);
    ioctl(fd,FBIOGET_VSCREENINFO,&fb_var);
    printf("width : %d\n",fb_var.xres);
    printf("high : %d\n",fb_var.yres);
    printf("bpp : %d\n",fb_var.bits_per_pixel);
    close(fd);
    return 0;
}
