#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()

//calculo da area de um circulo considerando a formula e o valor de PI

{
    double x,Area;
    //Area = n.R^2  n = 3.14159
    scanf("%lf", &x);
    Area = 3.14159 * pow(x,2);
                    //potencia = x^2
    printf("A=%.2lf\n", Area);
    return 0;
}
