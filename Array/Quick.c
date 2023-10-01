#include <stdio.h>
void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = (p - 1);
    for (int j = p; j < r; j++)
    {
        if (arr[j] < x)
        {
            i = i + 1;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}
void quicksort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}
void sorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 15};
    int n = 6;
    quicksort(arr, 0, n - 1);
    printf("After sorted array:");
    sorted(arr, n);
}
