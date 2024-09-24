#include <stdio.h>
#define max 5
int a[max]={10,20,30,40};
int element,pos,i,current_size=4;

int display(int a[])
{
    for (i=0;i<max;i++){
        printf("%d",a[i]);
        printf("\n");
    }
}


int insert_at_front(int a[])
{   
    if(current_size==max){
      printf("Array is full delete an element to  insert \n");
    }
    else{
    printf("Enter the element you want to insert:");
    scanf("%d",&element);
    for(int i=current_size;i>0;i--){
        a[i]=a[i-1];
    }
      current_size+=1;
      a[0]=element;
      printf("aftet insertion\n");
      display(a);
    }
}
int insert_at_end(int a[]){
  if(current_size==max){
    printf("array is full");
  }
  else{
    printf("Enter the element:");
    scanf("%d",&element);
    a[max-1]=element;
    display(a);
 }
}
int insert_at_middle(int a[]){
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos<0||pos>current_size){
        printf("invalid position");
    }
    else{
    printf("Enter the element:");
    scanf("%d",&element);
    for(int i=current_size;i>=pos;i--){
        a[i]=a[i-1];
    }
      a[pos-1]=element;
      current_size++;
      display(a);
  }
}
int deletion(int a[]){
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos<0||pos>max){
        printf("invalid position");
    }

    else if(pos==1){
    for(i=0;i<max;i++){
     a[i]=a[i+1];
    }
      current_size--;
      display(a);
    }
    else{
    for(i=pos-1;i<current_size;i++){
     a[i]=a[i+1];
    }
    current_size--;
    display(a);
  }
}
int search(int a[]){
    int found;
    printf("Enter the element:");
    scanf("%d",&element);
    for(i=0;i<max;i++){
    if(a[i]==element){
       printf("The element %d was found in index [%d]",element,i);
       found=1;
       break;
    }
    }
    if(found!=1){
        printf("The element was not found");
    }
}
void sorting(int a[]) {
    int temp;
    for (i=0; i<max; i++) {
        for (int j=0; j<max; j++) {
          if(a[i]<a[j]){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
          }
        }
    }
    printf("After sorting\n");
     display(a);
}
 int main()
 {  
     int choice;
  
    printf("\nEnter a number\n 1 to display\n 2 to insert at front \n 3 to insert at end \n 4 to insert at middle\n 5 to delete an element\n 6 to search\n 7 to sort");
    printf("\nYour choice:");
    scanf("%d",&choice);
    
     switch(choice){
        
        case 1:
          display(a);
          break;
        case 2:
         insert_at_front(a);
         break;
        case 3:
         insert_at_end(a);
         break;
        case 4:
         insert_at_middle(a);
         break;
        case 5:
         deletion(a);
         break;
        case 6:
         search(a);
         break;
        case 7:
         sorting(a);
         break;

        default:
         printf("Enter valid choice");
         break;
         
    };

return 0;
}
