#include <stdio.h>
int stack[100],max,i,top=-1;

void display(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("|%d|->top\n",stack[top]);    //to indicate top element
        for(i=top-1;i>=0;i--){
            printf("|%d|\n",stack[i]);
        }
    }
}

int push(){
    int val;
    if(top==max-1){
        printf("Overflow..\n");
    }
    else{
      printf("\nEnter the value to push:");
      scanf("%d",&val);
      top+=1;
      stack[top]=val;
      printf("Stack elements\n");
      display();
    }
}
int pop(){
    if(top==-1){
        printf("Underflow");
    }
    else{
        top-=1;
        printf("\n After poping..\n");
        display();
    }
}

int main() {
    int choice;
    printf("Enter the maximum number of  elements in the stack:");
    scanf("%d",&max);
    while(choice !=3){
    printf("\nEnter 1 to push,2 to pop and 3 to exit:");
    scanf("%d",&choice);
    
    switch (choice){
        case 1:
          push();
          break;
          
        case 2:
           pop();
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
