#include <stdio.h>


int main(int argc, char* argv[]){

	int number_of_nums_to_enter, number, i, j;
	int even_pos = 0, even_neg = 0, odd_pos = 0, odd_neg = 0;
	int max;
	int min;
	float average = 0;
	int sum = 0;


	printf("How many numbers would you like to provide as input: ");
	scanf("%d", &number_of_nums_to_enter);
	int arr[4][number_of_nums_to_enter];


	for(i = 0; i < number_of_nums_to_enter; i++){
		printf("Enter a number: ");
		scanf("%d", &number);

	// Check positive/negative and odd/even
		if(number % 2 == 0 && number >= 0){
			arr[0][even_pos] = number;
			even_pos++;
		}
		else if(number % 2 == 0 && number < 0){
			arr[1][even_neg] = number;
			even_neg++;
		}
		else if(number % 2 != 0 && number >= 0){
			arr[2][odd_pos] = number;
			odd_pos++;
		}
		else if (number % 2 != 0 && number < 0) {
			arr[3][odd_neg] = number;
			odd_neg++;
		}
	}

	max = arr[0][0];
	min = arr[0][0];
	sum = arr[0][0];

	for(i = 1; i < even_pos; i++){
		sum = sum + arr[0][i];

		if(arr[0][i] > max){
			max = arr[0][i];
		}
		else if(arr[0][i] < min){
			min = arr[0][i];
		}
	}
	if(even_pos == 0){
		printf("\nCannot calculate average for a row with no elements\n");
		printf("Max value not present for empty rows\n");
		printf("Min value not present for empty rows\n");
	}
	else{
		average = sum/(even_pos * 1.0);
		printf("\nLargest even positive number: %d\n", max);
		printf("Smallest even positive number: %d\n", min);
		printf("Average value of row 1: %.2f\n", average);
	}



	average = 0.0;
	max = arr[1][0];
	min = arr[1][0];
	sum = arr[1][0];


	for(i = 1; i < even_neg; i++){
		sum = sum + arr[1][i];
		if(arr[1][i] > max){
			max = arr[1][i];
		}
		else if(arr[1][i] < min){
			min = arr[1][i];
		}
	}
	if(even_neg == 0){
		printf("Cannot calculate average for a row with no elements\n");
		printf("Max value not present for empty rows\n");
		printf("Min value not present for empty rows\n");
	}
	else{
        average = sum/(even_neg * 1.0);
		printf("Largest even negative number: %d\n", max);
		printf("Smallest even negative number: %d\n", min);
		printf("Average value of row 2: %.2f\n", average);
	}


	average = 0.0;
	max = arr[2][0];
	min = arr[2][0];
	sum = arr[2][0];

	for(i = 1; i < odd_pos; i++){
		sum = sum + arr[2][i];
		if(arr[2][i] > max){
			max = arr[2][i];
		}
		else if(arr[2][i] < min){
			min = arr[2][i];
		}
	}
	if(odd_pos == 0){
		printf("Cannot calculate average for a row with no elements\n");
		printf("Max value not present for empty rows\n");
		printf("Min value not present for empty rows\n");
	}
	else{
        average = sum/(odd_pos * 1.0);
		printf("Largest odd positive number: %d\n", max);
		printf("Smallest odd positive number: %d\n", min);
		printf("Average value of row 3: %.2f\n", average);
	}


	average = 0.0;
	max = arr[3][0];
	min = arr[3][0];
	sum = arr[3][0];

	for(i = 1; i < odd_neg; i++){
		sum = sum + arr[3][i];
		printf("sum is: %d\n", sum);

		if(arr[3][i] > max){
			max = arr[3][i];
		}
		else if(arr[3][i] < min){
			min = arr[3][i];
		}
	}

	if(odd_neg == 0){
		printf("Cannot calculate average for a row with no elements\n");
		printf("Max value not present for empty rows\n");
		printf("Min value not present for empty rows\n");
	}
	else{
        average = sum/(odd_neg * 1.0);
		printf("Largest odd negative number: %d\n", max);
		printf("Smallest odd negative number: %d\n", min);
		printf("Average value of row 4: %.2f\n", average);
	}
	
	return 0;
}
