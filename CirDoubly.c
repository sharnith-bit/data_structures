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
            tail->next = head;
            head->prev = tail;
            count++;
        }

    } while (choice != 0);
    printf("\n%d\n", count);
}
void display()
{
    temp = head;
    if(head==NULL){
        printf("list is empty");
    }
    else{
    do
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }while (temp != head);
      printf("head(%d)\n",head->data);
    }
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
        new->prev = tail;
        new->next = head;
        tail->next=new;
        head->prev=new;
        head=new;
    }
    else if (pos > 1 && pos <= count)
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        new->prev = temp;
        temp->next->prev = new;
        temp->next= new;
    }
    else
    {
        tail->next = new;
        new->prev = tail;
        new->next = head;
        head->prev=new;
        tail = new;
        
    }
    count++;
}

void delete()
{
    int pos;
    printf("Enter the position:");
    scanf("%d", &pos);
    temp = head;
    if (pos == 1)
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
    else if (pos > 1 && pos <= count)
    {
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        free(temp);
    }
    else{
        tail->prev->next = NULL;
        free(tail);
    }
    head->prev = tail;
    tail->next = head;
    count--;

}
void search(){
    int element,found=0;
    printf("Enter the Element:");
    scanf("%d",&element);
    
    temp = head;
 do
    {
     if(temp->data == element){
            found = 1;
            break;
        }
        temp = temp->next;
    }  while (temp != head);
    
    if(found==1){
        printf("%d is found.\n",element);
    }
    else{
        printf("%d is not found \n",element);
    }
}

void main()
{
    int choice;
    printf("TO perform any operations Enter..\n 1 to create\n 2 to Insert\n 3 to Delete 4 to Search\n 5 to Display\n 0 to Exit\n");

    printf("\t__\n");
    do
    {
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
        }
    } while (choice != 0);
    printf("Exited!");
}
