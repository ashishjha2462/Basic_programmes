#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void linear(int *arr, int k, int n)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==k)
        {
            printf("%d was found at %d position",arr[i],i+1);
            break;
        }
    }
}

void binary(int *arr, int k, int n)
{
    int start=0,end=n,found=0;
    while(start<=end)
    {
        int in=(int)((start+end)/2);
        if(arr[in]==k)
        {
            printf("%d was found at %d position",arr[in],in+1);
            found=1;break;
        }
        else if(arr[in]>k)
        {
            end=in;
        }
        else if(arr[in]<k)
        {
            start=in;
        }
    }
    if(!found)
    {
        printf("%d was not found",k);
    }
}

int main()
{
    int n,k,c1=0;
    printf("Enter size of the array:\n");
    scanf("%d",&n);
    int arr[n];
    int x,c2=0;
    printf("Enter array elements:\n");
    for(x=0 ; x<n ; x++)
    {
        scanf("%d",&arr[x]);
    }
    printf("Enter number to searched:\n");
    scanf("%d",&k);
    printf("1. Linear\n");
    printf("2. Binary\n");
    printf("Choose one method:\n");
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
        linear(arr,k,n);
    }
    if (c1==2)
    {
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                c2++;break;
            }
        }
        if(c2==0)
            binary(arr,k,n);
        else
            printf("Invalid array for binary sort");
    }
}
