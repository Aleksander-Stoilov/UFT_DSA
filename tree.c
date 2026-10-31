#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

typedef struct tree tree;

struct tree{
    int count;
    char data;
    tree* left;
    tree* right;
};

void insert_in_tree(tree **tree_root, char symbol){
    tree *new_node = malloc(sizeof(tree));
    tree *iterator = *tree_root;
    new_node->data = symbol;
    new_node->left = NULL;
    new_node->right = NULL;
    if (*tree_root == NULL){
        *tree_root = new_node;
        (*tree_root)->count++;
    }
    else{
        if(iterator->data > new_node->data){
            if(iterator->left != NULL){
                iterator = iterator->left;
                insert_in_tree(&iterator, new_node->data);
            }
            else iterator->left = new_node;
        }
        else if(iterator->data < new_node->data){
            if(iterator->right != NULL){
                iterator = iterator->right;
                insert_in_tree(&iterator, new_node->data);
            }
            else iterator->right = new_node;
        }
        else{
           iterator->count++; 
        }
    }
}

void PrintTree(tree *p, int delta){
    int i;
    if(p != NULL){
        PrintTree(p->left, delta+1);
        for(i=1; i<=delta; i++) printf("\t");
        printf("%d", p->data);
        printf("\n");
        PrintTree(p->right, delta+1);
    }
}

int main(int argc, char* argv[]){
    printf("Enter your full name and faculty number (enter '#' to exit)\n");

    tree *root = NULL;

    char input[20];
    while(true){
        scanf("%s", input);
        if(!strcmp(input, "#")) break;
        for(int i = 0; input[i] != '\0'; i++){
            insert_in_tree(&root, input[i]);
        }
    }

    PrintTree(root, 0);

    return 0;
}
