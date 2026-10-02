#include <stdio.h>


int main(int argc, char* argv[]){
		
	int number_of_nums_to_enter, number, i, j;
	int even_pos = 0, even_neg = 0, odd_pos = 0, odd_neg = 0;
	int max;
	int min;
	int average = 0;
	int sum = 0;
	
	
	printf("How many numbers would you like to provide as input: ");
	scanf("%d", &number_of_nums_to_enter);
	int arr[4][number_of_nums_to_enter];
	

	for(i = 0; i < number_of_nums_to_enter; i++){
		printf("Enter a number: ");
		scanf("%d", &number);
		
	// Check positive/negative and odd/even
		if(number % 2 == 0 && number >= 0){
			arr[0][i] = number;
			even_pos++;
		}	
		else if(number % 2 == 0 && number < 0){
			arr[1][i] = number;
			even_neg++;
		}
		else if(number % 2 != 0 && number >= 0){
			arr[2][i] = number;
			odd_pos++;
		}
		else if (number % 2 != 0 && number < 0) {
			arr[3][i] = number;
			odd_neg++;
		}
	}
	
	for(i = 0; i < 4; i++){
		for(j = 0; j < number_of_nums_to_enter; j++){
			printf("The number at array[%d][%d] is %d\n", i, j, arr[i][j]);
		}
	}
	
	
	max = arr[0][0];
	min = arr[0][0];
	sum = arr[0][0];
	
	for(i = 1; i < even_pos; i++){
		sum = sum + arr[0][i];
		average = sum/even_pos;
		
		if(arr[0][i] > max){
			max = arr[0][i];
		}
		else if(arr[0][i] < min){
			min = arr[0][i];
		}
	}
	

	printf("\nLargest even positive number: %d\n", max);
	printf("Smallest even positive number: %d\n", min);
	printf("Average value of row 1: %d\n", average);
	

	average = 0;
	max = arr[1][0];
	min = arr[1][0];
	sum = arr[1][0];
	
	
	for(i = 1; i < even_neg; i++){
		sum = sum + arr[1][i];
		average = sum/even_neg;
		
		if(arr[1][i] > max){
			max = arr[1][i];
		}
		else if(arr[1][i] < min){
			min = arr[1][i];
		}
	}

	printf("Largest even negative number: %d\n", max);
	printf("Smallest even negative number: %d\n", min);
	printf("Average value of row 2: %d\n", average);
	
	average = 0;
	max = arr[2][0];
	min = arr[2][0];
	sum = arr[2][0];
	
	for(i = 1; i < odd_pos; i++){
		sum = sum + arr[2][i];
		average = sum/odd_pos;
		
		if(arr[2][i] > max){
			max = arr[2][i];
		}
		else if(arr[2][i] < min){
			min = arr[2][i];
		}
	}

	printf("Largest odd positive number: %d\n", max);
	printf("Smallest odd positive number: %d\n", min);
	printf("Average value of row 3: %d\n", average);

	average = 0;
	max = arr[3][0];
	min = arr[3][0];
	sum = arr[3][0];
	
	for(i = 1; i < odd_neg; i++){
		sum = sum + arr[3][i];
		average = sum/odd_neg;
		
		if(arr[3][i] > max){
			max = arr[3][i];
		}
		else if(arr[3][i] < min){
			min = arr[3][i];
		}
	}

	printf("Largest odd negative number: %d\n", max);
	printf("Smallest odd negative number: %d\n", min);
	printf("Average value of row 4: %d\n", average);

	return 0;
}