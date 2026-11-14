#include <stdio.h>
//#include <cstdlib>
#include <stdlib.h>

struct element {
    double data;
    struct element* next;
};

struct element *top = NULL;

double Pop();
void Push(double a);

int main(int argc, char* argv[]){

    double input;
    double result;

    printf("Please enter a real number within the range [-124017:0]: ");

    while (true) {
        scanf("%lf", &input);
        if(input == 999.0){
            break;
        }
        if(input < -124017.0 || input > 0.0){
            printf("Invalid data\n");
        }
        else{
            Push(input);
        }
    }

    while (true) {
        result = Pop();
        if(result == 1.00){
            break;
        }
        else{
            printf("%f, ", result);
        }
    }
}

double Pop(){
    double x = 0;
    if(top == NULL){
        printf("Stack is empty!");
        // return a value outside of our range.
        return 1.00;
    }
    else {
        struct element *p;
        x = top->data;
        p = top;
        top = top->next;
        free(p);
    }
    return x;
}

void Push(double a){
    struct element *p;
    p = (struct element*) malloc(sizeof(struct element));

    if(p != NULL){
        p->data = a;
        p->next = top;
        top = p;
    }
    else{
        printf("Not enough memory!");
    }
}
