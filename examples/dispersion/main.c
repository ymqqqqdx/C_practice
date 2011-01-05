#include <stdio.h>
#include <math.h>
double fun(double *x,int size)
{
    double s = 0,x0 = 0;;
    int i;
    for (i = 0; i < size; i++) 
        x0 += x[i];
    x0 /= 10;
    for (i = 0; i < size; i++) 
        s += (x[i] - x0) * (x[i] - x0);
    s /= 10;
    s = sqrt(s);
    return s;
}
int main(int argc, const char *argv[])
{
    double x[10] = {95.0,89.0,76.0,65.0,88.0,72.0,85.0,81.0,90.0,56.0};
    double x1 = fun(x,10);
    printf("%f\n",x1);
    return 0;
}
