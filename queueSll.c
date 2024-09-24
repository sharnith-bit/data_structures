#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
  struct node *front=NULL,*rear=NULL;

void display(){
    if(front==NULL){
        printf("\nQueue is empty");
    }
    else{
        struct node *temp=front;
          printf("Front->");
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
          printf("Rear");
    }
}
void enqueue(){
    int value;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL){
        printf("Memory allocation is failed");
    }
        printf("Enter the value to enqueue:");
        scanf("%d",&value);

          new->data=value;
          new->next=NULL;

    if(rear==NULL){

        front=rear=new;
        display();
    }
    else{
        rear->next=new;
        rear=new;
        new->next=NULL;
        display();
    }

}

void dequeue(){
    int dequeued_val=front->data;
    if(front==NULL&& rear==NULL)
    {
        printf("Queue is empty");
    }
    else{
        struct node *temp=front;
        front=front->next;
        if(front==NULL){
            rear=NULL;
        }
        free(temp);
        display();
        printf("\n Dequeued element:%d",dequeued_val);
    }
}

int main(){
    int choice=0;

    while(choice !=3){
    printf("\n\nQueue operations \n Enter \n 1 to Enqueue \n 2 to Dequeue and \n 3 to exit");
    printf("\n Your choice:");
    scanf("%d",&choice);
    
    switch (choice){
        case 1:
          enqueue();
          break;
          
        case 2:
           dequeue();
           break;
           
        case 3:
           printf("\nExiting");
           break;
        
        default:
           printf("\nEnter the valid choice");
           break;
    };
}
  return 0;
}
