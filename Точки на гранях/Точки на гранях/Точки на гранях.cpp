#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <locale.h>

int NOD(int n1, int n2)
{
    while (n1 != 0 && n2 != 0)
    {
        if (n1 > n2)
            n1 = n1 % n2;
        else
            n2 = n2 % n1;
    }
    return n1 + n2;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    while (true)
    {

        printf("\n\n Введите количество точек\n");
        int n, x1, y1, x2, y2, d1, d2, s = 0;
        printf("n=");
        scanf("%d", &n);
        printf("Введите точки\n");
        scanf("%d %d,", &x1, &y1);
        int x = x1;
        int y = y1;
        for (int i = 0; i < n - 1; i++)
        {
            printf("\n");
            scanf("%d %d,", &x2, &y2);
            d1 = abs(x2 - x1);
            d2 = abs(y2 - y1);
            if (d1 == 0)
                s = s + d2 - 1;
            else
                if (d2 == 0)
                    s = s + d1 - 1;
                else
                    s = s + (NOD(d1, d2) - 1);
            x1 = x2;
            y1 = y2;
        }
        d1 = abs(x1 - x);
        d2 = abs(y1 - y);
        if (d1 == 0)
            s = s + d2 - 1;
        else
            if (d2 == 0)
                s = s + d1 - 1;
            else
                s = s + NOD(d1, d2);
        printf("\nКоличество точек на гранях равно %d", s);
    }
}