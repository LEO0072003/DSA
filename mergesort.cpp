#include<stdio.h>
#include<stdlib.h>

void printArray(int a[], int n){
	printf("\n");
	for(int i =0; i<n; i++){
		printf("%d ", a[i]);
	}
}

void merge(int start,int mid, int end, int a[]){
	
	int n1=mid-start+1,n2=end-mid;
	int l[n1],r[n2];
	
	for(int i = 0; i<n1; i++){
		l[i] = a[start+i];
	}
	for(int i = 0 ; i< n2; i++){
		r[i] = a[mid+i+1];
	}
	
	int k = start,i=0,j=0;
	while(i<n1 && j<n2){
		if(l[i]<r[j]){
			a[k++] = r[j++];
		}
		else{
			a[k++] = l[i++];
		}
	}
	
	while(i<n1){
		a[k++] = l[i++];
	}
	while(j<n2){
		a[k++] = r[j++];
	}
	
}



void msort(int i, int j, int a[]){
	if(i<j){
		int mid = (i+j)/2;
		msort(i,mid,a);
		msort(mid+1,j,a);
		merge(i,mid,j,a);
	}
}

int main(){
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int a[n];
	
	printf("Enter the elements of the array: ");
	for(int i =0; i<n; i++){
		scanf("%d ", &a[i]);
	}
	
	msort(0,n,a);
	printArray(a, n);
}
