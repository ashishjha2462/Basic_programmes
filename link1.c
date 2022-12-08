#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void insertatstart(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));// creating new node
    temp->data = x;// storing data
    temp->next = head;// attaching new node to previous linked list
    head = temp; //reinitialising the head of the linked list
}

void insertatend(int x)
{
    struct node *temp1 = (struct node *)malloc(sizeof(struct node));// creating new node
    temp1->data = x;// storing data
    temp1->next = NULL;// NULL is stored as next as it will be the last node
    struct node *temp2 = head;
    while (temp2->next != NULL)// traversing to the end of the list
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;// attaching new node to previous linked list
    temp2->next = temp1;
}

static void reverse(struct node **head_ref)
{
    struct node *prev = NULL;
    struct node *current = *head_ref;
    struct node *next = NULL;
    while (current != NULL)
    {
        
        next = current->next;// Store next

        
        current->next = prev;// Reverse current node's pointer

        
        prev = current;// Move pointers one position ahead.
        current = next;
    }
    *head_ref = prev;
}

void print()
{
    struct node *temp = head;
    printf("The List Is:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    printf("How Many Numbers:\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter a Number:\n");
        scanf("%d", &x);
        insertatstart(x);
        print();
    }
    reverse(&head);
    print();
    return 0;
}
