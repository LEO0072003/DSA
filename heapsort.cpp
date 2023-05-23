#include<stdio.h>
#include<stdlib.h>

// Swapping two elements
void swap(int *a, int *b){
	
	int temp = *a;
	*a = *b;
	*b = temp;
	
}

void printarr(int a[],int n){
	printf("\n");
	for(int i = 0; i<n; i++){
		printf("%d ",a[i]);
	}
}

void heapify(int a[], int n, int i){
	
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	//Checking the largest value
	
	if(left<n && a[left] > a[largest]){
		largest = left;
	}
	if(right<n && a[right] > a[largest]){
		largest = right;
	}
	
	//Swapping the larger node with the root and heapifying the subtree recursively	
	
	if(largest != i){
		swap(&a[i], &a[largest]);
		heapify(a,n,largest);
	}
	
}

void heapsort(int a[], int n){
	
	// Build a max heap
	for(int i = (n / 2) -1; i>= 0; i--)	{
		heapify(a,n,i);
	}
	
	// Heap Sort
	for(int i = n-1; i>=0 ; i--){
		swap(&a[0],&a[i]);
		
		heapify(a,i,0);
		
		}
	
}



int main(){
	int n; 
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array elements : ");
	for(int i = 0; i<n; i++){
		scanf("%d",&a[i]);
	}
	heapsort(a,n);
	printarr(a,n);
	
}
