
#include <stdio.h>

int uadd_ok(unsigned x, unsigned y)
{
    unsigned s = x + y;
    return s >= x;
}

int main(int argc, char const *argv[])
{
    printf("%d", uadd_ok(0xffffffffU, 0u));
    return 0;
}
