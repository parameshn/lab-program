// Electricity bill

#include <stdio.h>

int main()
{
    int meterNumber;
    float units, totalAmount = 100;
    printf("Enter meter number and number of units consumed: ");
    scanf("%d %f", &meterNumber, &units);

    if (units <= 200)
    {
        totalAmount += units * 0.8;
    }
    else if (units <= 200 + 100)
    {
        totalAmount += 200 * 0.8;
        totalAmount += (units - 200) * 0.9;
    }
    else
    {
        totalAmount += 200 * 0.8;
        totalAmount += 100 * 0.9;
        totalAmount += (units - 300) * 1;
    }

    if (totalAmount > 400)
    {
        totalAmount += totalAmount * 0.15;
    }

    printf("Total totalAmount for Meter-%d is: RS %.2f\n", meterNumber, totalAmount);

    return 0;
}
