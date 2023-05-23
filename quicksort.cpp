#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
	
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	
}

void printArray(int a[], int n){
	printf("\n");
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}

int partition(int a[],int l, int r){
	int pivot = a[l];
		int i = l, j = r;
		while(i<j){
			
			while(a[i]<=pivot){
				i++;
			}
			while(a[j]>pivot){
				j--;
			}
			if(i<j){
				
				swap(&a[i], &a[j]);
			}
		}
		swap(&a[l],&a[j]);
		
		return j;
}

void quicksort(int a[],int l, int r){
	if(l<r){
		int part = partition(a,l,r);
		quicksort(a,l,part-1);
		quicksort(a,part+1,r);
	}		
	
}


int main(){
//	int n; 
//	printf("Enter the number of elements in the array : ");
//	scanf("%d",&n);
//	int a[n];
//	printf("Enter the array elements : ");
//	for(int i = 0; i<n; i++){
//		scanf("%d",&a[i]);
//	}
	int a[] = {7,9,3,2,11,5,8};
	
	quicksort(a,0,6);
	printArray(a,7);
}
