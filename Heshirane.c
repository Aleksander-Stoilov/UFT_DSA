#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define s 32
const int n=20011;
//const int s=32;
const int arrmax=1000;

typedef char ElementType[s];
typedef struct vyzel vyzel;

struct vyzel { 
	ElementType kliuch;
	vyzel *sledvasht;
};

int hash1(char kliuch[], int l) { 
	int i, p;
	p=kliuch[0];
	for (i=1; i<l; i++)
		p=p+kliuch[i];
	return (p%n);
}
int hash2(char kliuch[], int l){ 
	int i, p;
	p=kliuch[0];
	for(i=1; i<l; i++)
		p=(p*s+kliuch[i])%n;
	return p;
}

void inicializacia(vyzel * H[], int n){ 
	int i;
	for (i=n-1; i>=0; i--)
		H[i]=NULL;
}

vyzel * tyrsene(char x[], vyzel * H[]){ 
	vyzel * p;
	printf("\nStarting hashing...");
	int k=hash2(x,strlen(x));
	printf("\nHashing Complete!");
	if (H[k]==NULL)
		p=NULL;
	p=H[k];
	while(p!=NULL)
		p=p->sledvasht;
	return p;
}

void zapis(ElementType x, vyzel * H[]){ 
	vyzel * p, *p1;
	p=tyrsene(x,H);
	printf("\nTyrsene Complete!");
	if (p==NULL){ 
 		p=malloc(sizeof(vyzel));
 		if(p==NULL) printf("Greshka - nedostig na pamet!!");
		else{ 
			p1=H[hash1(x,strlen(x))];
			p->sledvasht=p1;
			strcpy(p->kliuch,x);
			H[hash2(x,strlen(x))]=p;
 		}
 	}
}


int main(int argc, char* argv[]){
	
	vyzel* my_arr[20011];
	printf("Starting init");
	inicializacia(my_arr, 20011);
	printf("\nInit complete!");
	ElementType my_str = "Hello";
	
	zapis(my_str, my_arr);
	printf("\nWrite complete!");
	//zapis("Goodbye", my_arr);
	//zapis("See you later", my_arr);
	vyzel *capture = tyrsene("Hello", my_arr);

	if(capture == NULL) printf("\nError, capture is NULL");

	printf("\nResult from search: %s ", capture->kliuch);
	return 0;
}