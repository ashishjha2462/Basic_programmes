#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int RANGE=100; 

void Insertion_Sort(int *arr, int n)
{
    printf("insertion sort, it is then!\n");
    for(int x=1;x<n;x++)
    {
        int c=x;
        for(int y=x-1;y>=0;y--)
        {
            if(arr[y]>arr[c])
            {
                int temp=arr[c];
                arr[c]=arr[y];
                arr[y]=temp;
            }
            c--;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void selection_Sort(int *arr, int n)
{
    printf("selection sort, it is then!\n");
    int c=0;
    for(int x=c;x<n-1;x++)
    {
        int i=c;
        int min_num=arr[c];
        for(int y=x;y<n;y++)
        {
            if(arr[y]<min_num)
            {
                min_num=arr[y];
                i=y;
            }
        }
        int temp=arr[i];
        arr[i]=arr[c];
        arr[c]=temp;
        c++;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int* merge_Sort(int *A, int start, int end, int n)
{
    if(end-start==0)
    {
        return A;
    }
    else
    {
        int half=start+(int)((end-start)/2);
        int *a= merge_Sort(A,start,half,n);
        int *b= merge_Sort(A,half+1,end,n);
        int lea=start, leb=half+1,k=0;
        int c[(end-start)+1];
        while(lea<half+1 || leb<end+1)
        {
            if(lea<half+1)
            {
                if(leb<end+1)
                {
                    if(A[lea]<A[leb])
                    {
                        c[k]=A[lea];k++;lea++;
                    }
                    else{
                        c[k]=A[leb];k++;leb++;
                    }
                }
                else
                {
                    c[k]=A[lea];k++;lea++;
                }
            }
            else if(leb<end+1)
            {
                c[k]=A[leb];k++;leb++;
            }
            else{
                break;
            }
        }
        for(int x=0;x<(end-start)+1;x++)
        {
            A[start+x]=c[x];
        }
        return A;
    }
    
}

/* selection sort*/
void swap(int arr[], int i, int j) {
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

void quicksort0(int arr[], int a, int b) {
    if (a >= b)
        return;

    int key = arr[a];
    int i = a + 1, j = b;
    while (i < j) {
        while (i < j && arr[j] >= key)
            --j;
        while (i < j && arr[i] <= key)
            ++i;
        if (i < j)
            swap(arr, i, j);
    }
    if (arr[a] > arr[i]) {
        swap(arr, a, i);
        quicksort0(arr, a, i - 1);
        quicksort0(arr, i + 1, b);
    } else { // there is no left-hand-side
        quicksort0(arr, a + 1, b);
    }
}

void quick_Sort(int arr[], int len) {
    quicksort0(arr, 0, len - 1);
}
/* selection sort*/

void bubble_Sort(int *arr, int n)
{
    printf("bubble sort, it is then!\n");
    for(int x=0;x<n-1;x++)
    {
        for(int y=0;y<n-1;y++)
        {
            if(arr[y+1]<arr[y])
            {
                int temp=arr[y];
                arr[y]=arr[y+1];
                arr[y+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void counting_Sort(int numbers[], int size)
{
    int count[RANGE];
    for (int i=0; i<RANGE; i++)
        count[i] = 0;

    for (int i=0; i<size; i++)
        count[numbers[i]]++;

    int index = 0;
    for (int i=0; i<RANGE; i++)
    {
        while (count[i] > 0)
        {
            numbers[index] = i;
            index++;
            count[i]--;
        }
    }
}

int main()
{
    int n,c1=0,c2=0;
    printf("SORTING\n");
    printf("1.linear\n");
    printf("2.comparison\n");
    printf("ENTER A CHOICE\n");
    while(c1!=1 && c1!=2)
    {
        scanf("%d",&c1);
        if (c1!=1 && c1!=2)
        {
            printf("INVALID CHOICE\nRE-ENTER\n");
        }
    }
    if (c1==1)
    {
        printf("Enter size of the array:\n");
        scanf("%d",&n);
        int arr[n];
        int x;
        printf("Enter array elements:\n");
        for(x=0 ; x<n ; x++)
        {
            scanf("%d",&arr[x]);
        }
        printf("1.Insertion Sort\n");
        printf("2.selection Sort\n");
        printf("3.merge Sort\n");
        printf("4.quick Sort\n");
        printf("5.bubble Sort\n");
        printf("ENTER A CHOICE\n");
        while(c2<1 || c2>5)
        {
            scanf("%d",&c2);
            if (c2<1 || c2>5)
            {
                printf("INVALID CHOICE\nRE-ENTER\n");
            }
        }
        switch (c2)
        {
        case 1:
            /* code */
            Insertion_Sort(arr,n);
            break;
        case 2:
            /* code */
            selection_Sort(arr,n);
            break;
        case 3:
            /* code */
            printf("merge sort, it is then!\n");
            int *p=(int*)merge_Sort(arr,0,n-1,n);
            for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
            break;
        case 4:
            /* code */
            quick_Sort(arr,n);
            printf("quick sort, it is then!\n");
            for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
            break;
        case 5:
            bubble_Sort(arr,n);
            break;
        
        default:
            break;
        }
    }
    else if (c1==2)
    {
        printf("Enter size of the array:\n");
        scanf("%d",&n);
        int arr[n];
        int x;
        printf("Enter array elements:\n");
        for(x=0 ; x<n ; x++)
        {
            scanf("%d",&arr[x]);
        }
        printf("1.counting Sort\n");
        printf("ENTER A CHOICE\n");
        while(c2<1 || c2>1)
        {
            scanf("%d",&c2);
            if (c2<1 || c2>1)
            {
                printf("INVALID CHOICE\nRE-ENTER\n");
            }
        }
        switch (c2)
        {
        case 1:
            /* code */
            counting_Sort(arr,n);
            printf("counting sort, it is then!\n");
            for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
            break;
        }
    }
}
