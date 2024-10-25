#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *parent;
    struct node **children;
    int children_count;
};

struct node *root = NULL;

void insertChild(struct node *parent, struct node *child){
    child->parent = parent;
    parent->children_count++;
    parent->children = realloc(
        parent->children,
        sizeof(struct node*) * parent->children_count);
    parent->children[parent->children_count - 1] = child;
}


struct node *insert_node(struct node *root, int value){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    new_node->value = value;
    new_node->children_count = 0;
    new_node->children = NULL;
    new_node->parent = NULL;

    if(root == NULL){
        root = new_node;
    }else{
        insertChild(root, new_node);
    }
    return root;
}

