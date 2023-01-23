#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <locale.h>

void main()
{
    setlocale(LC_CTYPE, "rus");
    while (true)
    {
        printf("\n");
        printf("\n");
        int n;
        int c = 1;
        int p0 = 2;
        int p1 = 3;
        int buf = 0;
        printf("n=");
        scanf("%d", &n);
        if (n > 1)
        {
            for (int i = 0; i < n; i++)
            {
                c = c * 2;
            }
            for (int i = 0; i < n - 2; i++)
            {
                buf = p1;
                p1 = p1 + p0;
                p0 = buf;
            }
            printf("\n Количество всевозможных комбинаций равно %d", p1);
        }
        else
        {
            printf("\n Введиите другое число");
        }


    }
}