#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *prev;
};
int count= 0;
struct node *head = NULL, *temp = NULL, *new, *tail;

void createNode()
{
    new = (struct node *)malloc(sizeof(struct node));
}

void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void create()
{
     int data, choice;
     do
    {
        printf("Do you want to add node 1 or 0:");
        scanf("%d", &choice);
        createNode();
        if (choice == 1)
        {
            printf("Enter the data:");
            scanf("%d", &(new->data));
            if (head == NULL)
            {
                head = new;
                new->next = NULL;
                new->prev = NULL;
                temp = head;
            }
            else
            {
                temp->next = new;
                new->next = NULL;
                new->prev = temp;
                temp = temp->next;
            }
            tail = temp;
            count++;
        }

    } while (choice != 0);
      display();
}

void insert()
{

    int pos;
    createNode();
    printf("Enter the data :");
    scanf("%d", &(new->data));
    printf("Enter the position to insert:");
    scanf("%d", &pos);
    temp = head;
    if (pos == 1)
    {
        new->prev = NULL;
        new->next = head;
        if (head != NULL)
        {
            head->prev = new;
        }
        head = new;
    }
    else if (pos > 1 && pos <= count)
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        new->prev = temp;
        temp->next = new;
        new->next->prev = new;
    }
    else
    {
        tail->next = new;
        new->prev = tail;
        new->next = NULL;
        tail = new;
    }
    count++;
    display();
}

void delete()
{
    int pos;
    printf("Enter the position:");
    scanf("%d", &pos);
    temp = head;
    if (pos == 1)
    {
        head = temp->next;
    }
    else if (pos > 1 && pos <= count)
    {
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
    }
    else{
        tail->prev->next = NULL;
    }
    count--;
    display();
}
void search(){
    int element,found=0;
    printf("Enter the Element:");
    scanf("%d",&element);
    temp = head;
    while(temp != NULL){
        if(temp->data == element){
            found++;
        }
        else{
            found == 0;
        }
        
        temp = temp->next;
    }
    if(found == 0){
        printf("%d is not found.\n",element);
    }
    else{
        printf("%d is found \n",element);
    }
}
void main()
{
    int choice;
    
    while(choice!=6){
       printf("TO perform any operations Enter..\n 1 to create\n 2 to Insert\n 3 to Delete\n 4 to Search\n 5 to Display\n 6 to Exit\n");

       printf("\t__\n");
    
        printf("\nEnter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete ();
            break;
        case 4:
            search();
            break;
        case 5:
            display();
            break; 

        case 6:
            printf("\n Exiting");
            break;

        default:
            printf("\nInvalid choice");
            break;   
        };
    } 
}
