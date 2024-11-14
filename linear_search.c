#include<stdio.h>
#define MAX 5

int linear_search(int arr[] ,int key ){
    int found=0;

   
    for(int i=0;i<MAX;i++){
        if(arr[i]==key){
            printf("Element %d was found at the location %d",key,i+1);
            found=1;
            break;
        }
    }
        if(found!=1){

            printf("Element was not found");
        }

    }



int main(){

    int arr[MAX]={10,28,0,49,55},key;

    printf("\n\nEnter the element you want to search:");
    scanf("%d",&key);

    linear_search(arr,key);


    return 0;

}