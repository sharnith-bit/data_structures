#include<stdio.h>
#define max 5

int queue[max];
int front = -1,rear = -1;


void display()
{
    printf("Queue elemets are:\n");
    if(front==-1){
        printf("Queue is empty");
    }
    else
      for(int i=front;i<=rear;i++){
        if(i==front && i==rear){
            printf("|%d|->Front & Rear\n",queue[i]);
            break;
        }
        else if(i==front)
        {
          printf("|%d|->Front\n",queue[i]);
        }
        else if(i==rear){
            printf("|%d|->Rear\n",queue[i]);
        }
        else{
            printf("|%d|\n",queue[i]);
        }
        }
      }

void enqueue(){
    if(rear==max-1){  
        printf(" Queue is full");
    }
    else{
        int val;
        printf(" Enter the value to enqueue:");
        scanf("%d",&val);
        if(front==-1){
            front=0;
        }
        rear+=1;
        queue[rear]=val;
        printf("Enqueued value:%d\n",val);
        display();
    }
}

void dequeue()
{
    int val;
    if(front==-1){
        printf("Queue is empty");
    }
    else{
        val=queue[front];
        if(front== rear){
            front= rear=-1;
            display();
        }
        else{
            front+=1;
        }
        printf("\nDequeued element:%d\n",val);
        display();
    }

}




int main(){
    int choice;

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
