#include <stdio.h>

int main(int argc, char const *argv[])
{
    int answerInt = 200 * 300 * 400 * 500;
    printf("the int multiplication answerInt is %d \n", answerInt);

    double answerFloat = (3.14 + 1e20) - 1e20;
    printf("the float add answerFloat is %f \n", answerFloat);

    double answerFloat2 = 3.14 + (1e20 - 1e20);
    printf("the float add answerFloat2 is %f \n", answerFloat2);

    return 0;
}
