/*要求根据输入的字符方程求出未知字符,即“97ab=8ab×cd+1”
 * ,其中 a、b 代表 0~9 的数字,
 * cd 为两位数,8×cd 的结果为两位数,9×cd 的结果为 3 位
 * 数,求 a、b、cd 代表的数,及 8ab×cd 的结果。程序可以
 * 利用 i 来表示 cd(10≤i<100)
 * ,再根据 8×cd 为两位数和
 * 9×cd 为 3 位数来进行限定,求出 cd 的值。
 * */
#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a,b,c;
    for(a = 0;a < 10;a++)
        for(b = 0;b < 10;b++)
            for(c = 10;c < 100;c++)
                if(9 * c < 1000)
                    if(9700 + a * 10 + b == (800 + a * 10 + b) * c + 1)
                    {
                        printf("a = %d\nb = %d\ncd = %d\n",a,b,c);
                        break;
                    }
    return 0;
}
