
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0xffffff64;
    int b=a>>3;
    printf("%x", b);  
    return 0;
}
