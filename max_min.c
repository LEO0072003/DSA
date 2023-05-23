#include<stdio.h>
#include<stdlib.h>

void max_min(int i, int j,int a[], int *max, int *min){
	int max2,min2;
	
	if(i==j){
		*max = a[i];
		*min = a[i];
	}
	
	else if(i == j-1){
		
		*max = (a[i]>a[j])?a[i]:a[j];
		*min = (a[i]<a[j])?a[i]:a[j];
	}
	
	else{
		int mid = (i+j)/2;
		max_min(i,mid,a,max,min);
		max2 = *max;
		min2 = *min;
		max_min(mid+1,j,a,max,min);
		
		*max = (max2>*max)?max2:*max;
		*min = (min2<*min)?min2:*min;
	}
	
}

int main(){
	int a[] = {3,93,10,7,3,9,7,2,1,0,78,5,1,4};
	
	int max= -100000, min = 1000000;
	max_min(0,13,a,&max,&min);
	printf("%d   %d", max,min);
		
}
