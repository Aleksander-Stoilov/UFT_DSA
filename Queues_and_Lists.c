#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define n 30
#define true 1
#define false 0

typedef struct node node;

struct node{
	char data;
	node* next;
};

node* List;

node* Find(int value){
	node* p;
	int found = 0;
	p = List;
	while(p != NULL && !found){
		if(p->data == value) found = 1;
		else p = p->next;
	}
	return p;
}

node* FindPrev(int value){
	node *p;
	p = List;
	while (p != NULL && p->next->data != value){
		p = p->next;
	}
	return p;
}

void Delete(char c){
	node *p, *t;

	p = FindPrev(c);

	if(p == NULL) printf("The list is empty!");
	else {
		if(p == List){
			List = p->next;
			free(p);
		}
		else {
			t = p->next;
			p->next = t->next;
			free(p);
		}
	}
}

void Add(node *p, char c){
	node* q;
	q = malloc(sizeof(node));
	if(q == NULL) printf("Not enough memory!");
	else {
		q->data = c;
		if(List == p){
			q->next = List;
			List = q;
		}
		else{
			q->next = p->next;
			p->next = q;
		}
	}	
}

char queue[n][15];
int begin = -1, end = -1;

char* Read(){

	if(end == -1){
		printf("Queue is empty");
		return "";
	}
	else{
		if(end == begin){
			end = 0;
		}
		else{
			begin = (begin % n) + 1;
		}
		return queue[begin];
	}
}

void Write(char c[]){
	if(end == -1){
		end = 0;
		strcpy(queue[end], c);
	}
	else{
		end = (end % n) + 1;
		
		if(end == begin){
			printf("Queue is full");
			end = end - 1;
		}
		else{
			strcpy(queue[end], c);
		}
	}
}

int main(){
	int count = 0;
	char input[30];

	while(true){
		scanf("%s", input);
		if(!strcmp(input, "exit")) break;
		Write(input);
		count++;
	}

	for(int i = 0; i < count; i++)
	printf("String from read: %s\n", Read());
}
