#include <stdio.h>
#include <math.h>
typedef struct point{
    int x;
    int y;
} POINT;

double dist(POINT p1, POINT p2)
{
    return sqrt(pow((p2.x - p1.x), 2) +  pow((p2.y - p1.y), 2));
}
int main()
{
    POINT p1 = {10, 20};
    POINT p2;
    
    p1.x = 20;
    p2.x = 30;
    p2.y = 40;
    printf("p1.x = %d, p1.y = %d\n", p1.x, p1.y);
    printf("p2.x = %d, p2.y = %d\n", p2.x, p2.y);
    printf("distance of p1, p2 = %lf", dist(p1, p2));
    return 0;
}
