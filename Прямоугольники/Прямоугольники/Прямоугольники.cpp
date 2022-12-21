#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <locale.h>
#include <string>
#include <windows.h>
using std::string;

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true)
    {
        int m, n, c = 0;
        printf("\n \n");
        printf("\n Введите количество строк: ");
        scanf("%d",&m);
        printf("\n Введите количество столбцов: ");
        scanf("%d", &n);
        printf("\n Матрица: \n");
        int array[100][100];
        int array1[101][101];
        for (int i = 0; i < m;i++)
        {
            for (int j = 0; j < n;j++)
            {
                scanf("%d", &array[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < 1;i++)
        {
            for (int j = 0; j < 101;j++)
            {
                array1[i][j] = 0;
            }
        }
        for (int i = 0; i < 101;i++)
        {
            for (int j = 0; j < 1;j++)
            {
                array1[i][j] = 0;
            }
        }
        for (int i = 0; i < m;i++)
        {
            for (int j = 0; j < n;j++)
            {
                array1[i + 1][j + 1] = array[i][j];
            }
        }
        for (int i = 1; i < m+1;i++)
        {
            for (int j = 1; j < n+1;j++)
            {
                if (array1[i][j] == 1 && array1[i - 1][j] == 0 && array1[i][j - 1] == 0)
                {
                    c++;
                }
            }
        }
        printf("\n Количество прямоугольников в матрице равно %d", c);
    }
}