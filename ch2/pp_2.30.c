#include <stdio.h>

int tadd_ok(int x, int y)
{
    int sum = x + y;
    if (x > 0 && y > 0)
    {
        return sum > 0;
    }
    else if (x < 0 && y < 0)
    {
        return sum < 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    printf("%d", tadd_ok(0xffffffff, 0u));
    return 0;
}
