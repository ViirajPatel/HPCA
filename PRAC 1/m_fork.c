#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void fun1(int arr[], int size)
{
    printf("\n");
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j >= i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
        printf("%d, ",arr[i]);
    }
}

int main()
{

    int size = 5;
    int arr[4][size], temp;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < size; j++)
        {
            arr[i][size - 1 - j] = j;
        }
    int x = 0;
    fork();
    fork();
    fun1(arr[x], size);
    x++;

    return 0;
}
