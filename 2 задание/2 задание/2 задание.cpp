#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <locale.h>

#include <iostream>

void main()
{
    setlocale(LC_CTYPE, "rus");
    while(true)
    {
        /*
        n=2     n=3     n=4  
        1) 1    1) 3    1) 4   
        2) 3    2) 8    2) 15
        3) 5    3) 22   3) 57
        4) 8    4) 60   4)
        5) 13
        6) 21
        
        
        */
        printf("\n \n \n \n \n");
        int n, k, k1 = 0, k2 = 0, buf, p = 0;
        printf("n=");
        scanf("%d", &n);
        printf("k=");
        scanf("%d", &k);
        int c = 1; // переменная для нужных вариантов
        int s = 1; // переменная для всех вариантов
        if (n > 1 && k > 0)
        {
            if (k < 3) //при k<3 смотрим только 2 варианта
            {
                for (int i = 1; i <= 3; i++)
                {
                    c = c * n;
                    if (i == 1)
                        k1 = n; //при k=1 будет 1 место и там будут помещены все числа
                    if (i == 2)
                        k2 = c - 1; //при k=2 будет 2 места и там будут помещены все числа, кроме 00
                }
                if (k == 1)
                    printf("\n Количество нужных комбинаций равно %d", k1);
                else
                    printf("\n Количество нужных комбинаций равно %d", k2);

            }
            else
            {
                for (int i = 0; i < k; i++) //подсчет всевозможных вариантов
                {
                    s = s * n;
                }
                for (int i = 1; i < k; i++)
                {
                    c = c * n;
                    if (i == 1)
                        k1 = n;
                    if (i == 2)
                        k2 = c - 1;
                }
                int p1 = k1; //запоминаем 1 число
                int p2 = k2; //запоминаем 2 число
                for (int i = 0; i < k - 2; i++)
                {
                    buf = p2;
                    p2 = (p1 + p2) * (n - 1);
                    p1 = buf;
                }
                printf("\n Количество всевозможных комбинаций равно %d", s);
                //printf("\n k1= %d", k1);
                //printf("\n k2= %d", k2);
                printf("\n Количество нужных комбинаций равно %d", p2);
            }

        }
        else
        {
            printf("\n Введиите другое число");
        }
    }
    
}
