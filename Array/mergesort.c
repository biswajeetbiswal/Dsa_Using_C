#include <stdio.h>
void concure(int arr[], int si, int mid, int ei)
{
    int merged[ei - si + 1];
    int x = si;
    int y = mid + 1;
    int k = 0;
    while (x <= mid && y <= ei)
    {
        if (arr[x] <= arr[y])
        {
            merged[k] = arr[x];
            x++;
            k++;
        }
        else
        {
            merged[k] = arr[y];
            y++;
            k++;
        }
    }
    while (x <= mid)
    {
        merged[k] = arr[x];
        x++;
        k++;
    }
    while (y <= ei)
    {
        merged[k] = arr[y];
        k++;
        y++;
    }
    int n = sizeof(merged) / sizeof(merged[0]);
    for (int i = 0, j = si; i < n; i++, j++)
    {
        arr[j] = merged[i];
    }
}
void divide(int arr[], int si, int ei)
{
    if (si < ei)
    {
        int mid = (si + ei) / 2;
        divide(arr, si, mid);
        divide(arr, mid + 1, ei);
        concure(arr, si, mid, ei);
    }
}
int main()
{
    int arr[] = {15, 12, 1, 3, 25, 65, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    divide(arr, 0, n - 1);
    printf("After sorting :");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}