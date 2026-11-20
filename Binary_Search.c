#include <stdio.h>
#include <stdlib.h>

void BinSearch(int value_to_be_found, int arr[], int max_size_of_arr){
	int isr, b=0, e=max_size_of_arr;
	while(b<=e) {
		isr=(b+e)/2;
		if(arr[isr]==value_to_be_found) {
		printf("The value you wanted is in position %d.", isr);
		return;
		}
		if(value_to_be_found<arr[isr])
			e=isr-1;
		else
			b=isr+1;
		}
	printf("x not found in the arry!");
}

int main(){

	int arr_size;
	int value_to_find;
	printf("Please provide a size for an array: ");
	scanf("%d", &arr_size);
	
	int arr[arr_size];
	
	for(int i = 0; i < arr_size; i++){
		arr[i] = rand();
	}
	
	for(int i = 0; i < arr_size; i++){
		for(int j = i; j < arr_size - 1; j++){
			int temp;
			if(arr[i] > arr[j+1]){
				temp = arr[i];
				arr[i] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	printf("\nSorted array: ");
	for(int i = 0; i < arr_size; i++){
		printf("%d ", arr[i]);
	}
	
	printf("\nWhat value would you like to find: ");
	scanf("%d", &value_to_find);
	
	BinSearch(value_to_find, arr, arr_size);
	
	return 0;
}