#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int value;
} matrix;

int main()
{
    matrix smatrix[100];
    int m, n;

    printf("Enter the no: of rows and coloumns: \n");
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    printf("\nEnter elements of the matrix: \n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    int nze = 0;
    smatrix[0].row = m;
    smatrix[0].col = n;
    for (int i = 0, z = 1; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                nze++;
                smatrix[z].row = i;
                smatrix[z].col = j;
                smatrix[z].value = matrix[i][j];
                z++;
            }
        }
      smatrix[0].value = nze;

    printf("\nSparse matrix representation\n");
    for (int i = 0; i <= nze; i++)
        printf("%d %d %d\n", smatrix[i].row, smatrix[i].col, smatrix[i].value);
        
    float sparsity = (float)(smatrix[0].row * smatrix[0].col - smatrix[0].value) / (smatrix[0].row * smatrix[0].col);
    printf("\nSparsity = %0.5f\n", sparsity);

}
