// All linked list related operated in c
#include<stdio.h>
#include<stdlib.h>

struct node* createLinkedList(int arr[], int size);
void searchLinkedList(struct node *head, int value);
struct node* reverseLinkedList(struct node *head);
struct node* insertBeginning(struct node *head, int data);
void printLinkedList(struct node *head);
void insertEnd(struct node *head, int value);
void insertMiddle(struct node *head, int value, int p);
struct node* deleteFromAny(struct node *head, int value);


struct node{
int data;
struct node *next;
};


int main()
{
    //Creating a linked list from an array
    int a[] = {3, 13, 33, 15, 30, 45, 60, 200};
    struct node *head=NULL;

    head = createLinkedList(a, 8);
    printLinkedList(head);

    //Searching value in a linked list
    int value = 100;

    printf("Searching %d in the array\n", value);
    searchLinkedList(head, value);


    //Reversing a linked list
    head = reverseLinkedList(head);
    printf("Reversed Linked list is: \n");
    printLinkedList(head);

    //Inserting a value into beginning of a linked list
    head = insertBeginning(head, 500);
    printf("\nAfter insert at beginning, the linked list is: \n");
    //printf("test: %d\n", head->data);
    printLinkedList(head);

    //Inserting a value at End of linked list
    insertEnd(head, 1000);
    printf("\nAfter insert at end, linked list is: \n");
    printLinkedList(head);

    //Inserting a value at middle of linked list
    insertMiddle(head, 555, 3);
    printf("\nAfter insert at middle, linked list is: \n");
    printLinkedList(head);

    //deleting a node from anywhere in the list
    head = deleteFromAny(head, 555);
    printf("\nAfter deleting, list is: \n");
    printLinkedList(head);


    return 0;

}

struct node* deleteFromAny(struct node *head, int value)
{
    struct node *tempHead = (struct node*)malloc(sizeof(struct node));
    tempHead->next = head;
    struct node *temp = tempHead;
    while(temp->next != NULL)
    {
        if(temp->next->data == value)
        {
            temp->next = temp->next->next;
            break;
        }
        else
            temp = temp->next;
    }

    return tempHead->next;
}


void insertMiddle(struct node *head, int value, int p)
{
    struct node *curr = head;
    int counter = 0;
    while(curr != NULL)
    {
        counter++;
        if(counter == p)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->data = value;
            temp->next = curr->next;
            curr->next = temp;
        }

        curr = curr->next;

    }
}


void insertEnd(struct node *head, int value)
{
    struct node *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    curr->next = temp;
}


void printLinkedList(struct node *head)
{
    struct node *curr = head;
    while(curr != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
    free(curr);
}


struct node* insertBeginning(struct node *head, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;

}


struct node* reverseLinkedList(struct node *head)
{
    struct node *current = head, *prev = NULL, *next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}


void searchLinkedList(struct node *head, int value)
{
    int nodeCount = 1;

    //printf("test\n");
    struct node *curr = head;
    while(curr != NULL)
    {

        if(curr->data == value)
        {
            printf("%d is found at node no: %d\n", value, nodeCount);
            break;
        }
        curr = curr->next;
        nodeCount++;
    }
    printf("Sorry, %d is not found in the linked list\n", value);
}


struct node* createLinkedList(int arr[], int size)
{
    struct node *head= NULL, *temp= NULL, *current = NULL;

    for(int i=0; i<size; i++)
    {

        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->next = NULL;
        if(head==NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->next = temp;
            current = temp;
        }
    }

    return head;

}
