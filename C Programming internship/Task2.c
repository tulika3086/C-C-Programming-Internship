#include <stdio.h>

// Function for Matrix Addition
void matrixAddition(int a[10][10], int b[10][10], int r, int c)
{
    int sum[10][10];

    printf("\nMatrix Addition Result:\n");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
}

// Function for Matrix Multiplication
void matrixMultiplication(int a[10][10], int b[10][10], int r1, int c1, int c2)
{
    int mul[10][10];

    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            mul[i][j] = 0;
            for(int k = 0; k < c1; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nMatrix Multiplication Result:\n");
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            printf("%d\t", mul[i][j]);
        }
        printf("\n");
    }
}

// Function for Transpose
void transposeMatrix(int a[10][10], int r, int c)
{
    printf("\nTranspose of Matrix:\n");
    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < r; j++)
        {
            printf("%d\t", a[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    int a[10][10], b[10][10];
    int r, c;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("\nEnter elements of First Matrix:\n");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of Second Matrix:\n");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    matrixAddition(a, b, r, c);
    matrixMultiplication(a, b, r, c, c);
    transposeMatrix(a, r, c);

    return 0;
}