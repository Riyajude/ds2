#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct
{
            int row;
            int col;
            int val;
}sparse;




void fast_transpose(sparse a[],  sparse b[])
{
            int row_terms[100],  start_pos[100];
            int i,  j,  p;       

            int numTerms = a[0].val;
            int numCols = a[0].col;
             
            b[0].row = numCols;
            b[0].col = a[0].row;
            b[0].val = numTerms;
            if(numTerms>0)
            {
                        for(i =0; i<numCols;  i++)
                                                row_terms[i] = 0;

                        for(i=1; i<=numTerms; i++)
                                                row_terms[a[i].col]++;

                        start_pos[0]=1;

                        for(i=1; i<numCols; i++)
                                                start_pos[i] = start_pos[i-1] + row_terms[i-1];

                        for(i=1; i<=numTerms; i++)
                        {
                                                j = start_pos[a[i].col]++;
                                                b[j].row = a[i].col;
                                                b[j].col = a[i].row;
                                                b[j].val = a[i].val;
                        }
             }
            printf("\n\nThe Fast Transpose sparse matrix is:\n");
            printf("\nRow\tColumn\tValue\n");
            for(p=0; p<=a[0].val; p++)
            {
                        printf("%d\t", b[p].row);
                        printf("%d\t", b[p].col);
                        printf("%d\n", b[p].val);
            }
}
void main()
{
           sparse b[MAX]; 
            int n;
    printf("Enter the no: of non zero elements: ");
    scanf("%d", &n);

    sparse a[n + 1];
    a[0].val = n;

    printf("\nEnter the no: of rows and columns: ");
    scanf("%d %d", &a[0].row, &a[0].col);

    printf("\nEnter the sparse matrix representation: \n");
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].val);

    printf("\nSparse matrix representation\n");
    for (int i = 0; i <= n; i++)
        printf("%d %d %d\n", a[i].row, a[i].col, a[i].val);

            
            fast_transpose(a, b);
}
