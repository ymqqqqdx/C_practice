#C Source
##Function Pointer
    #include <stdio.h>
    int addtwo(int,int);
    int main(int argc, const char *argv[])
    {
        int result;
        int (* fun1) (int,int);
        fun1 = addtwo;
        result = (*fun1)(3,5);
        printf("%d\n",result);
        return 0;
    }

    int addtwo(int i,int j)
    {
        return i + j;
    }
    //function pointer is static,no matter whether add * or not,the effect is
    the same
##typedef a Function Pointer
    typedef int (* fun)(void);

    typedef void (*fun_t)(void);
    ((fun_t)0x800)(); //jump to 0x800 and run there
##union
    union day{
        int a;
        char b;
    };
##pointer array
    int main(int argc, const char *argv[])
    {
        int *p[4];
        int bb[20];
        p[1]=bb;
        bb[0]=123;
        printf("%d\n",*( p[1] ));
        printf("%d\n",**( p+1));
        return 0;
    }
