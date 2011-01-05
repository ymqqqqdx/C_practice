/*现有苹果、桔子、香蕉、菠萝、梨 5 种水果用来做水果拼盘,每个水果拼盘一定有 3
 * 个水果,
 * 且这 3 个水果的种类不同,问可以制作出多少种水果拼盘?本实例使用 C
 * 语言中的“枚举类型”
 * 来解决水果拼盘问题。程序运行后显示出可能的拼盘类型
 * */
#include <stdio.h>

int main(int argc, const char *argv[])
{
    enum fruit {apple,orange,banana,pineapple,pear};
    enum fruit x,y,z;
    char *a[5] = {"apple","orange","banana","pineapple","pear"};
    int n = 0;
    for(x = apple;x <= pear;x++)
        for(y = apple;y <= pear;y++)
            for(z = apple;z <= pear;z++)
            {
                if(x != y && x != z && y != z)
                    printf("%d:\t%-11s%-11s%-11s\n",++n,a[x],a[y],a[z]);
            }
    return 0;
}
