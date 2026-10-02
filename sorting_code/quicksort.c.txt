
#include <stdio.h>

int partition(int a[], int low, int high)
{
    int pivot, i, j, temp;

    pivot = a[low];
    i = low + 1;
    j = high;

    while (i <= j)
    {
        while (i <= high && a[i] <= pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int a[], int low, int high)
{
    int p;

    if (low < high)
    {
        p = partition(a, low, high);

        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter the no of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, n - 1);

    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    return 0;
}