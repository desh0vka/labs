#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <locale.h>
#include <windows.h>
using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N, c = 0, res = 0;
    printf("\n \n Введите количество чисел: ");
    scanf("%d", &N);
    printf("\n Введите числа через пробел: ");
    int array_num[500];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array_num[i]);
        c++;
    }
    int M[50000];
    M[0] = 1;
    for (int i = 0; i < c; i++)
    {
        for (int j = 50000; j >= 0; j--)
        {
            if (M[j] == 1)
                M[j + array_num[i]] = 1;
        }
    }
    for (int i = 0; i < 50000; i++)
    {
        if (M[i] > 0)
        {
            printf("\n M[%d]=%d", i, M[i]);
            res++;
        }
    }
    printf("\n Ответ:%d", res);
}
