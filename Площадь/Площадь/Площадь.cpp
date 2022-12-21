#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <locale.h>

void main()
{
    setlocale(LC_CTYPE, "rus");
    while (true)
    {
        printf("\n\n Введите количество точек\n");
        int n, x1, y1, x2, y2;
        float s = 0, res;
        printf("n=");
        scanf("%d", &n);
        printf("Введите точки\n");
        scanf("%d %d,", &x1, &y1);
        for (int i = 0; i < n - 1; i++)
        {
            printf("\n");
            scanf("%d %d,", &x2, &y2);
            s = s + (y1 + y2) * (x2 - x1);
            x1 = x2;
            y1 = y2;
        }
        res = abs(s)/2;
        printf("\nПлощадь равна %f", res);
    }
}