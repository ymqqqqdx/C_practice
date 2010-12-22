
char * mystrcpy(char *a,const char *b)
{
    int i=0;
    while(a[i++] = b[i]);
    return a;
}
int mystrlen(const char *a)
{
    int i = 0;
    while( a[i++] );
    return i - 1;
}
int mystrlen2(char *a)
{
    char *bak = a;
    while(*a++);
        return a - bak - 1;
}

    printf("%s\n",mystrcpy(buf,"Hello world!"));
    printf("length: %d\n",mystrlen("Hello world!"));
    printf("length: %d\n",mystrlen2("Hello world!"));
