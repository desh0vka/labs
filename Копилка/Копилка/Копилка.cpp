#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <locale.h>
#include <string>
#include <windows.h>

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true)
    {
        //10 34 4 1 4 3 6 5 2 7 3
        int E, F, Pi, Wi, N, min = 1000000, max = 0;
        printf("\n \n Введите вес пустой копилки: ");
        scanf("%d", &E);
        printf("\n Введите вес полной копилки: ");
        scanf("%d", &F);
        printf("\n Введите количество монет: ");
        scanf("%d", &N);
        int array_monet[500][2];
        int array_buf_max[500];
        int array_buf_min[500];
        for (int i = 0; i < N; i++)
        {
            printf("\n Введите ценность %d монеты: ", (i + 1));
            scanf("%d", &array_monet[i][0]);
            printf("\n Введите вес %d монеты: ", (i + 1));
            scanf("%d", &array_monet[i][1]);
        }
        int M[10000];
        int m[10000];
        for (int i = 0; i < F - E + 1; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if ((i + 1) == array_monet[j][1])
                {
                    M[i] = array_monet[j][0];
                    m[i] = array_monet[j][0];
                }
                array_buf_max[j] = M[i - array_monet[j][1]] + array_monet[j][0];
                if (array_buf_max[j] > max)
                    max = array_buf_max[j];
                array_buf_min[j] = m[i - array_monet[j][1]] + array_monet[j][0];
                if (array_buf_min[j] < min && array_buf_min[j] > 0)
                    min = array_buf_min[j];
            }
            M[i] = max;
            if (min == 1000000)
                min = 0;
            m[i] = min;
            min = 1000000;
            max = 0;
        }
        for (int i = 1; i < F - E + 1; i++)
        {
            printf("\n M[%d]=%d", i, M[i]);
        }
        printf("\n");
        for (int i = 1; i < F - E + 1; i++)
        {
            printf("\n m[%d]=%d", i, m[i]);
        }
    }
}