#ifndef _CALULATOR_H
#define _CALULATOR_H

int add(int a, int b)
{
    return a+b;
}
int sub(int a, int b)
{
    return a-b;
}
int multi(int a, int b)
{
    return a*b;
}
int printAdd(int a, int b)
{
    int sum;
    sum = 0;
    for(int i=a; i<b; i++) sum +=i;
    return sum;
}

#endif