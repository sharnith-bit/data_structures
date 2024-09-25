#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void display();
void insert();
void delete();
void search();
struct node *head=NULL,*temp=NULL,*new,*tail=NULL,*prev;
int n;

void display(){
    temp = head;
    if(head==NULL){
        printf("List is empty");
    }
     do {
        printf("%d-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
      printf("head(%d)",head->data);

}
void insert(){
    int pos;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the position to insert:");
    scanf("%d",&pos);
    printf("Enter the data :");
    scanf("%d",&(new->data));
    temp = head;
    if(pos==1){
        new->next=head;
        head = new;
        tail->next=head;

    }
    else if(pos >1 && pos<=n){
        for(int i=1;i<pos-1;i++){
            temp = temp->next;
        }
        new->next=temp->next;
        temp->next = new;
    }
    else{
        tail->next = new;
        new->next = NULL;
        tail = new;
    }
    tail->next = head;
}
void delete(){
    if(head==NULL){
        printf("List is Empty! ");
    }
    else{
        int pos;
        printf("Enter the position:");
        scanf("%d",&pos);
        temp=head;
        if(pos ==1){
            if(head==tail){
                free(head);
                return;
            }
            else{
                head=temp->next;
                tail->next=head;
            }
            free(temp); 
            display();
        }
        else{
      
        for(int i=1;i<pos;i++){
            prev = temp;
            if(temp==NULL){
                printf("%d",temp->data);
            }
            temp = temp->next;   
            }
        prev->next = temp->next;
        }
        free(temp);
       display();
    }
}
void search(){
    int element,found=0;
    printf("Enter the element to search:");
    scanf("%d",&element);
    temp = head;
    do
    {
      if(temp->data == element){
            found=1;
            break;
        }
        temp = temp->next;
    }while (temp != head);
    if(found == 1){
        printf("%d is Found.\n",element);
    }
    else{
        printf("%d is not Found",element);
    }  
}

int main(){
    int i,choice;
    printf("Enter the no. of node:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data %d:",i+1);
        scanf("%d",&(new->data));
        if(head == NULL){
            head = new;
            head->next=NULL;
        }
        else{
            tail->next = new;
            new->next=NULL;

        }
        tail = new;
    }
    tail->next = head;

    printf("To perform Operations\nEnter \n 1 to Insert\n 2 to delete\n 3 to search\n 4 to display\n 0 toExit.\n");
    do{
        printf("\n Enter the choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            search();
            break;
            case 4:
            display();
            break;
        }
    }while(choice!=0);
    printf("Exited!");  
}
