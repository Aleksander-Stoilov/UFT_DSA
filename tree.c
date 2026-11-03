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
    if (*tree_root == NULL){
        *tree_root = malloc(sizeof(tree));
        if(*tree_root == NULL){
        printf("faield to allocate memory");
        return;
        }
        (*tree_root)->data = symbol;
        (*tree_root)->left = NULL;
        (*tree_root)->right = NULL;
        (*tree_root)->count = 1;
        return;
    }
    else{
        if(symbol < (*tree_root)->data){
            insert_in_tree(&((*tree_root)->left), symbol);
        }
        else if(symbol > (*tree_root)->data){
            insert_in_tree(&((*tree_root)->right), symbol);
        }
        else{
           (*tree_root)->count++;
        }
    }
}

void insert_iteratively(tree **tree_root, char symbol){
    if(*tree_root == NULL){
        *tree_root = malloc(sizeof(tree));
        if(*tree_root == NULL) {
            printf("Failed memory allocation");
            return;
        }
        (*tree_root)->data = symbol;
        (*tree_root)->left = NULL;
        (*tree_root)->right = NULL;
        (*tree_root)->count = 1;
        return;
    }
    tree *iterator = *tree_root;

    while(true){
        if (symbol > iterator->data){
            tree *new_node = malloc(sizeof(tree));
            if (iterator->right == NULL){
                if(new_node == NULL){
                    printf("failed memory allocation");
                    return;
                }
                new_node->data = symbol;
                new_node->left = NULL;
                new_node->right = NULL;
                new_node->count = 1;

                iterator->right = new_node;
                break;
            }
            iterator = iterator->right;
        }
        else if(symbol < iterator->data){
            if(iterator->right == NULL){
                tree *new_node = malloc(sizeof(tree));
                if(new_node == NULL){
                    printf("failed memory allocation");
                    return;
                }
                new_node->data = symbol;
                new_node->left = NULL;
                new_node->right = NULL;
                new_node->count = 1;

                iterator->left = new_node;
                break;
            }
            iterator = iterator->left;
        }
        else{
            iterator->count++;
            break;
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

    tree *root_tree1 = NULL;

    char input[20];
    while(true){
        scanf("%s", input);
        if(!strcmp(input, "#")) break;
        for(int i = 0; input[i] != '\0'; i++){
            insert_iteratively(&root_tree1, input[i]);
        }
    }

    PrintTree(root_tree1, 0);


    return 0;
}
