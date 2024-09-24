#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head,*temp=NULL;

void display(){
        temp=head;
    printf("\nLINKED LIST : ");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
       printf("NULL->\n"); 

    }


void insert_at_end(){
    int element;

    struct node *new=(struct node*)malloc(sizeof(struct node));
    
    if(new==NULL){
        printf("The memory is not allocated properly");
    }
    
    printf("\nEnter the element to insert:");
    scanf("%d",&element);
  
    new->data=element;
    new->next=NULL;
    if(head==NULL){
        head=new;
    }
    else{
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
      temp->next=new;
      new->next=NULL;
    }
    display(); 
} 


void insert_at_front(){
    printf("INSERTING AT THE FRONT\n");
    int element;

    struct node *new=(struct node*)malloc(sizeof(struct node));
    
    if(new==NULL){
        printf("The memory is not allocated properly");
    }
    
    printf("\nEnter the element to insert:");
    scanf("%d",&element);
  
    new->data=element;
    new->next=NULL;
    if(head==NULL){
        head=new;
    }
    else{
        new->next=head;
        head=new;
    }
    display();

}


void insert_at_middle(){
    printf("INSERTING AT THE MIDDLE\n");
    int element,pos;

    struct node *new=(struct node*)malloc(sizeof(struct node));
    
    if(new==NULL){
        printf("The memory is not allocated properly");
    }
    printf("Enter the position:");
    scanf("%d",&pos);
    printf("\nEnter the element to insert:");
    scanf("%d",&element);
  
    new->data=element;
    new->next=NULL;
    temp=head;
    for(int i=0;i<pos-1&&temp==NULL;i++){
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
    display();
   }

    void delete(){
        printf("DELETING\n");
        int pos;

        printf("\nEnter the position:");
        scanf("%d",&pos);
         if (head == NULL) {
        printf("The list is empty\n");
    }
    else{
    temp = head;
    if (pos == 1) {
        head = head->next; 
        free(temp); 
        display();
    }
    else{
        struct node *prev = NULL;
    for (int i = 1; i < pos; i++) {
        prev=temp;
        temp=temp->next;
          if(prev->next==NULL){
            printf("%d",prev->data);
          }
        }
      prev->next=temp->next;

   display();
    }

    }
    } 
 void search(){
    printf("SEARCHING\n");
    int element,found=0;
    printf("Enter the element to search:" );
    scanf("%d",&element);
    temp=head;
    while(temp!=NULL){
        if(temp->data==element){
            found=1;
         }
        temp=temp->next;
    }
    if(found==1){
        printf("\nElement was found in the list");
    }
    else{
    printf("\nElement was not present in the list");
 }
 } 

    
void main(){
    int nodes,choice;
    printf("CREATING NODES\n");
    printf("Enter the number of nodes: ");
    scanf("%d",&nodes);

    for(int i=0;i<nodes;i++){
    insert_at_end();
    }
    while(choice!=6){
    printf("\n\nEnter 1 to insert at front \n 2 to insert at end \n 3 to insert at middle \n 4 to delete \n 5 to search \n 6 to exit \n your choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        insert_at_front();
        break;
    case 2:
        insert_at_end();
        break;
    case 3:
        insert_at_middle();
        break;
    case 4:
        delete();
        break;
    case 5:
       search();
       break;
    
    case 6:
       printf("\nExiting..Goodbye");
       break;
    
    default:
        break;
    };
}
   
}
