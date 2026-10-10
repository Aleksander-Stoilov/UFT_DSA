#include <stdio.h>
#define FK_SUM 15 // sum of digits in faculty number

void custom_GCD(int m, int n, int* result){
    int remainder;
    int temp;

    while (m != n){
        if(m > n){
            temp = n;
            remainder = m % n;
            n = m - n;
            m = temp;
            *result = m;
        }
        else if(n > m){
            temp = m;
            remainder = n % m;
            m = n - m;
            n = temp;
            *result = n;
        }
        else {
            *result = m;
            break;
        }
    }  
}
int euclid_GCD(int m, int n){
	int r;
        while (n != 0){
            r = m % n;
            m = n;
            n = r;
        }
	return m;
}

int main(int argc, char *argv[]){
    int x, y;
    int results[2][FK_SUM];

    for (int i = 0; i < FK_SUM; i++){
        printf("Enter numbers for which you would like to find the GCD: ");
        scanf("%d %d", &x, &y);
        custom_GCD(x, y, &results[0][i]);
        results[1][i] = euclid_GCD(x, y);
    }

    printf("Results from Custom GCD function: ");
    for (int i = 0; i < FK_SUM; i++){
        printf("%d, ", results[0][i]);
    }

    printf("\nResults from Euclid GCD function: ");
    for (int i = 0; i < FK_SUM; i++){
        printf("%d, ", results[1][i]);
    }

    return 0;
}
