#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *top=NULL,*temp=NULL;

void display(){
    temp=top;
    printf("\nStack:");
    printf("top->");
   while(temp!=NULL){
       printf("%d->",temp->data);
       temp=temp->next;
   }
     printf("NULL\n");
    
}
void push(){
  int val;
  struct node *new=(struct node*)malloc(sizeof(struct node));
  if(new==NULL ){
      printf("Memory is not allogated properly");
  }
  else{
       printf("\nEnter the value to push:");
       scanf("%d",&val);
      if(top==NULL){
          new->data=val;
          new->next=NULL;
          top=new;
         }
      else{
          new->data=val;
          new->next=top;
          top=new;
      }
    display();
  }
}
  void pop(){
      if(top==NULL){
          printf("Underflow");
      }
      else {
          int popedItem=top->data;
      temp=top;
      top=top->next;
      free(temp);
      display();
      printf("\npoped element:%d",popedItem);
  }
}
int main()
{  
    int choice;
    while(choice!=3){
        printf ("\nEnter 1 to push, 2 to pop and 3 to exit:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
              push();
              break;
              
            case 2:
              pop();
              break;
              
            case 3:
              printf("Goodbye");
              break;
            
            default:
              printf("Enter valid number");
        };
    }
  return 0;
}
