#include<stdio.h>
 

 void bubble_sort(int arr[],int n ){
    for(int i=0; i<n-1; i++){

        for(int j=0; j<n ; j++){

            if(arr[j]>arr[j+1]){

                int temp =arr[j];

                arr[j]=arr[j+1];

                arr[j+1]=temp;
            }
        }
    }

    printf("\nAfter sorting\n");

      for(int i=0;i<n;i++){

        printf("%d",arr[i]);

        printf("\n");
      }

 }

 int main(){
    int n;

    printf("\n\nEnter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr,n);

    return 0;

 }