#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define n 10
#define true 1
#define string_length 15
#define false 0

char queue[n][string_length];
int begin = -1, end = -1, first_pass = 1;

typedef struct node{
	char data;
	node* next;
} node;

node* List = NULL;

node* Find(char value){
	node* p;
	int found = 0;
	p = List;
	while(p != NULL && !found){
		if(p->data == value) found = 1;
		else p = p->next;
	}
	return p;
}

node* FindPrev(char value){
	node *p;
	p = List;
	while (p != NULL && p->next->data != value)	p = p->next;
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
    node* q = malloc(sizeof(node));

	if (q == NULL) printf("Not enough memory!");
	q->data = c;
	q->next = NULL;

    if (List == NULL || q->data > List->data){
		q->next = List;
		List = q;
    }
    else{
		while(p->next != NULL && p->next->data > q->data) p = p->next;
        q->next = p->next;
        p->next = q;
    }
}

char* Read(){
	if(end == -1){
		printf("Queue is empty");
		return "";
	}
	else{
		if(end == begin) end = 0;
		else begin = (begin % n) + 1;
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
	
    for (int i = 0; i < count; i++) {
        for(int j = 0; j < string_length; j++){
            if(queue[i][j] == '\0') break;
			Add(List, queue[i][j]);
        }
    }

	for(int i = 0; i < count; i++) printf("String from read: %s\n", Read());

    node* start;
    start = malloc(sizeof(node));
    start = List;
	printf("Data inside the linked list: ");

    while(start != NULL){
        printf("%c, ", start->data);
		start = start->next;
    }

	start = List;
	printf("\n");

	while(start != NULL){
		printf("%c - %p\n", start->data, start->next);
		start = start->next;
	}

}
