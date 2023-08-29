// Quadratic equation

#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    printf("Enter coefficient of x², x and a constant: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a != 0)
    {
        float x1, x2;
        float d = b * b - 4 * a * c;

        if (d > 0)
        {
            printf("Roots are real and different:\n");
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            printf("x1: %f, x2: %f\n", x1, x2);
        }
        else if (d == 0)
        {
            printf("Roots are real and equal:\n");
            x1 = -b / (2 * a);
            printf("x1 = x2 = %f\n", x1);
        }
        else
        {
            printf("Roots are imaginary:\n");
            float realPart = -b / (2 * a);
            float imgPart = sqrt(-d) / (2 * a);
            printf("x1: %f+%fi, x2: %f-%fi\n", realPart, imgPart, realPart, imgPart);
        }
    }
    else
    {
        printf("Equation is not quadratic.\n");
    }

    return 0;
}
