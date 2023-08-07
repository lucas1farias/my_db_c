

#include <stdio.h>

int main()
{
    int i, j, a, n, number[30];

    printf("\n===== Informe o valor de N =====\n");
    scanf("%d", &n);
    
    printf("===== Informe os números =====\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &number[i]);
    }

    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (number[i] > number[j])
            {
                a = number[i];
                number[i] = number[j];
                number[j] = a;
            }
        }
    }

    printf("===== Números ordenados em ordem decrescente =====\n");
    for (i = 0; i < n; ++i)
    {
        printf("%d\n", number[i]);
    }
    return 0;
}
