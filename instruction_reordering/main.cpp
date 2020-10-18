#include "lib.h"

int a, b, c;

int main()
{
    a = 5;
    int c = compute(2); // call to external library
    b = a;
    return 0;
}
