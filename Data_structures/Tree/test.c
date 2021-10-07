#include <stdio.h>

int test_me(int a)
{
    if(a<5)
    {
        a++;
    }

    return a;
}

int main()
{
    printf("%d",test_me(3));
    return 0;
}