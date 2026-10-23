#include <stdio.h>
#include <string.h>

#define n 30

char queue[n][10];
int begin = -1, end = -1;

char Read(){

	if(end == -1){
		printf("Queue is empty");
		return '';
	}
	else{
		if(end == begin){
			end = 0;
		}
		else{
			begin = (begin % n) + 1;
		}
		return *queue[end];
	}
}

void Write(char* c[]){
	if(end == -1){
		begin = 0;
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

	char input[30];
	char my_str[] = "Hello World";

	scanf("%c", input);
	while(!strcmp(input, "exit")){
		scanf("%c", input);
		Write(input);
	}

	for(int i = 0; i < n; i++)
	printf("String from read: %s", Read());
}
