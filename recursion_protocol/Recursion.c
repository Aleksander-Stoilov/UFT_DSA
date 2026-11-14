#include <stdio.h>
#include <time.h>
#include <math.h>
#define LAST_3_DIGITS_OF_FK_NUM_SUM 8

long long iterative_fibonacci(int n){
    long long elem_0 = 1, elem_1 = 1, next_elem;
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        for (int i = 0; i < n; i++){
            next_elem = elem_0 + elem_1;
            elem_0 = elem_1;
            elem_1 = next_elem;
        }
        return next_elem;
    }		
}
long long recursive_fibonacci(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        long long r = 1;
        if(n > 2)
            r = recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
    }
}

int main(){

    FILE *file = fopen("time_measurements.txt", "w");
    if(file == NULL){
        return 1;
    }
    int X1 = LAST_3_DIGITS_OF_FK_NUM_SUM;
    int X2 = LAST_3_DIGITS_OF_FK_NUM_SUM + 1;
    int X3 = LAST_3_DIGITS_OF_FK_NUM_SUM + 2;
    int X4 = LAST_3_DIGITS_OF_FK_NUM_SUM + 3;
    int X5 = LAST_3_DIGITS_OF_FK_NUM_SUM + 4;
    int X6 = LAST_3_DIGITS_OF_FK_NUM_SUM + 5;

    int Xs[6] = {X1, X2, X3, X4, X5, X6};
    clock_t t1, t2;

    fprintf(file, "Fibbonaci_Number,Measured Time,Method\n");

    long long fib_number;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 10; j++){

            t1 = clock(); // t1
            for(int k = 0; k<1000; k++){
                fib_number = iterative_fibonacci(Xs[i]);
            } 
            t2 = clock(); // t2
            double measured_time = (double)(t2-t1)/CLOCKS_PER_SEC;
            fprintf(file, "%d,%lf,Iterative\n", fib_number, measured_time);
            // printf("Measured_time = %lf, Iterative Method\n", measured_time);
        }                  
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 10; j++){
            t1 = clock(); // t1
            for(int k = 0; k < 1000; k++){
            fib_number = recursive_fibonacci(Xs[i]);
            }
            t2 = clock(); // t2
            double measured_time = (double)(t2-t1)/CLOCKS_PER_SEC;
            fprintf(file, "%d,%lf,Recursive\n", fib_number, measured_time);
            // printf("Measured_time = %lf, Recursive Method\n", measured_time);
        }                  
    }
    fclose(file);
    
    return 0;
}
