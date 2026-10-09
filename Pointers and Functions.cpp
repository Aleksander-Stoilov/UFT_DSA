#include <stdio.h>

// Faculty number sum: 15, 124017

int custom_NGOD(int m, int n){
	int remainder;
	
	if(m > n){
		remainder = 
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
	
	int a;
	
	a = euclid_GCD(8, 12);
	
	printf("a = %d, and 8%%12 is %d", a, 8%12);
	
	return 0;
}