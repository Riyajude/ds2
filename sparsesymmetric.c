#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int value;
} matrix;

int main()
{
    int n;
    printf("Enter the number of non zero elements: ");
    scanf("%d", &n);

    matrix a[n + 1];
    a[0].value = n;

    printf("\nEnter the number of rows and coloumns: ");
    scanf("%d %d", &a[0].row, &a[0].col);

    printf("\nEnter the sparse matrix representation: \n");
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);

    printf("\nSparse matrix representation\n");
    for (int i = 0; i <= n; i++)
        printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);

    if (a[0].row != a[0].col)
    {
        printf("\nMatrix is not a square matrix\n");
        return 1;
    }
    int symmetric = 0;
    for (int i = 1; i <= n; i++)
    {
        symmetric = 0;
        for (int j = 1; j <= n; j++)
            if (a[i].row == a[j].col && a[i].col == a[j].row && a[i].value == a[j].value)
                symmetric = 1;
        if (symmetric == 0)
        {
            printf("\nMatrix is not symmetric\n");
            return 1;
        }
    }
    printf("\nMatrix is sparse symmetric\n");

    return 0;
}
