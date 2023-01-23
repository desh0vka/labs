#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <locale.h>
#include <windows.h>

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    {
        int c = 0, i_int = 0, j_int = 0;
        float d = 0.1;
        char arr_char[100][100];
        int arr_int[100][100];
        char st1[100];
        char st2[100];
        FILE* fin;

        fin = fopen("D:\\data.txt", "r");
        for (int i = 0; NULL != fgets(arr_char[i], 100, fin);i++)
        {
            d = 0.1;
            c = 0;
            j_int = 0;
            for (int j = 0; arr_char[i][j] != '\0';j++)
            {
                if (arr_char[i][j + 1] == '\0' && arr_char[i][j] != '\n')
                {
                    arr_char[i][j + 1] = '\n';
                    arr_char[i][j + 2] = '\0';
                }
            }
            for (int j = 0; arr_char[i][j] != '\0';j++)
            {
                if (arr_char[i][j] == ' ' || arr_char[i][j + 2] == '\0')
                {
                    if (arr_char[i][j + 2] == '\0')
                        d = d * 10;
                    arr_int[i][j_int] = 0;
                    while (c != 0)
                    {
                        c--;
                        int buf = ((int)arr_char[i][j - 1 - c] - 48) * d;
                        arr_int[i][j_int] = arr_int[i][j_int] + buf;
                        d = d / 10;
                    }
                    if (arr_char[i][j + 2] == '\0')
                    {
                        c--;
                        int buf = ((int)arr_char[i][j - 1 - c] - 48);
                        arr_int[i][j_int] = arr_int[i][j_int] + buf;
                    }
                    j_int++;
                }
                else
                {
                    c++;
                    d = d * 10;
                }
            }
            i_int++;
        }
        int arr_int_def[100][100];
        for (int i = i_int - 2; i >= 0;i--)
        {
            arr_int[i][0] = arr_int[i + 1][0] + arr_int[i][0];
        }
        for (int j = 1; j < j_int;j++)
        {
            arr_int[i_int - 1][j] = arr_int[i_int - 1][j - 1] + arr_int[i_int - 1][j];
        }
        for (int i = i_int - 2; i >= 0;i--)
        {
            for (int j = 1; j < j_int;j++)
            {
                if (arr_int[i][j - 1] > arr_int[i + 1][j])
                    arr_int[i][j] = arr_int[i][j] + arr_int[i + 1][j];
                else
                    arr_int[i][j] = arr_int[i][j] + arr_int[i][j - 1];
            }
        }
        printf("\nМинимальная сумма шагов: %d", arr_int[0][j_int - 1]);
        printf("\nСам путь:");
        printf("\na[%d,1], ", i_int);
        int i = i_int - 1;
        int j = 0;
        while (j != j_int - 1 && i != 0)
        {
            if (arr_int[i][j + 1] < arr_int[i - 1][j])
                j++;
            else
                i--;
            printf("a[%d,%d], ", i+1, j+1);
        }
        printf("a[1,%d]", j_int);
        fclose(fin);
    }
}
