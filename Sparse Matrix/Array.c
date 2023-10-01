#include <stdio.h>
int main()
{
    int sparse[4][5] = {{0, 0, 3, 0, 4}, {0, 0, 5, 7, 0}, {0, 0, 0, 0, 0}, {0, 2, 6, 0, 0}};
    int size = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparse[i][j] != 0)
            {
                size++;
            }
        }
    }
    int res[3][size];
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparse[i][j] != 0)
            {
                res[0][k] = i;
                res[1][k] = j;
                res[2][k] = sparse[i][j];
                k++;
            }
        }
    }
    // display
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}