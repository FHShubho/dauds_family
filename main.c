#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void sumOfDistance(int arr[],int n)
{
    int sum=0,i,temp;
    int k=n/2;
    int m=arr[k];
    for(i=0;i<n;i++)
    {
        temp= m - arr[i];
        if(temp<0)
        {
            temp= temp * (-1);
        }
        sum +=temp;
    }
    printf("%d\n",sum);
}

int main()
{
    int testCase;
    printf("Enter number of test case: ");
    scanf("%d",&testCase);
    //printf("%d\n", testCase);
    int i;
    for(i=0;i<testCase;i++)
    {
        int numberOfRelatives;
        printf("Enter number of relatives: ");
        scanf("%d",&numberOfRelatives);

        int streetNumbers[numberOfRelatives];
        int count;

        printf("Enter street numbers: ");
        for(count=0;count<numberOfRelatives;count++)
        {
            scanf("%d",&streetNumbers[count]);
        }

        mergeSort(streetNumbers, 0, numberOfRelatives-1);
        sumOfDistance(streetNumbers,numberOfRelatives);
    }

    return 0;
}

