#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct node *root = NULL;

struct node* create_node(int data, struct node *parent)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = parent;

    return new_node;
};


void insert(struct node **root, int data){
    if(*root == NULL){
        *root = create_node(data,NULL);
    }else{
        struct node *temp = *root;
        if(data <= temp->data){
            if(temp->left == NULL){
                temp->left = create_node(data,temp);
            }else{
                insert(&temp->left,data);
            }
        }else{
            if(temp->right == NULL){
                temp->right = create_node(data,temp);
            }else{
                insert(&temp->right,data);
            }
        }
    }
}

void insertLeft(struct node *parent, int value){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    parent->left = newNode;
}

void insertRight(struct node *parent, int value){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    parent->right = newNode;
}


// Visite DFS

// RICORSIVE

// PRE-ORDINE

void preOrder(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    inOrder(root->left);
    inOrder(root->right);
}

// IN ORDINE

void inOrder(struct node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// POST-ORDINE

void postOrder(struct node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    inOrder(root->right);
    printf("%d ", root->data);
}

// ITERATIVE con stack


// Contare i nodi

int contaNodi(struct node *root){
    if(root == NULL){
        return 0;
    }else{
        int C1 = contaNodi(root->left);
        int C2 = contaNodi(root->right);

        return C1 + C2 + 1;
    }
}

// Visita BFS

void BFS(struct node *root){
    if(root == NULL){
        return;
    }

    struct node* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;

    while(front != rear){
        struct node *temp = queue[front++];
        printf("%d ", temp->data);

        if(temp->left != NULL) queue[rear++] = temp->left;
        if(temp->right != NULL) queue[rear++] = temp->right;
    }
}