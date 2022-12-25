/*super set program*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int x,y,i,n,h=0;
    printf("Enter The Size of the array:\n");
    scanf("%d",&n);
    char a[n];
    printf("Enter elements:\n");
    scanf("%s", &a);
    
    
    printf("\n");
    i=(int)pow(2,n);
    for(x=0;x<i;x++)
    {
        printf("{");
        for(y=0;y<n;y++)
        {
            if(x&(1<<y))
            {
                printf("%c, ",a[y]);
                h++;
            }
        }
        if(h!=0)
        {
            printf("\b\b");
        }
        printf("}");
        printf("\n");
    }
}
