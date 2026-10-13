#include <stdio.h>

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int a[100], n, key, i, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in ascending order: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    pos = binarySearch(a, n, key);

    if (pos == -1)
        printf("Element not found");
    else
        printf("Element found at position %d", pos + 1);

    return 0;
}