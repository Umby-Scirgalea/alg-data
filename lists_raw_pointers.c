#include <stdio.h>
#include <stdlib.h>

// Definizione strutture dati
typedef char element_type;

typedef struct list_element{
    element_type value;
    struct list_element *next;
}item;

typedef item *list;

// Print Iterativa
void showListIT(list l){
    // Parentesi
    printf("[");
    // Ciclo
    while(l != NULL){
        putchar(l->value);
        l = l->next;
        if(l != NULL){
            printf(",");
        }
    }
    // Parentesi
    printf("]\n");
}

// Print Ricorsiva
void showListREC_p(list l){
    if(l == NULL){
        return;
    }
    putchar(l->value);
    if(l->next != NULL){
        printf(",");
        l = l->next;
        showListREC_p(l);
    }
    
}

void showListREC(list l){
    printf("[");
    showListREC_p(l);
    printf("]\n");
}

// Inserisci davanti
void inserisciDavanti(){
    list root = NULL, aux;
    char n;

    while((n=getchar()) != '\n'){
        aux = (list)malloc(sizeof(struct list_element));
        aux->value = n;
        aux->next = root;
        root = aux;
    }
    showListIT(root);
    showListREC(root);

}

// Inserisci dietro
void inserisciDietro(){
    list root = NULL, aux;
    char n;

    while((n = getchar()) != '\n'){
        if(root == NULL){
            root = (list)malloc(sizeof(struct list_element));
            aux = root;
        }else{
            aux->next=(list)malloc(sizeof(struct list_element));
            aux=aux->next;
        }
        aux->value=n;
        aux->next=NULL;
    }
    showListIT(root);
    showListREC(root);
}


// Ricerca nella lista
int ricercaInLIsta(list l,char c){
    while(l != NULL){
        if(l->value == c){
            return 1;
        }
        l = l->next;
    }
    return 0;
}

// Inserisci dietro con return Lista
list inserisciDietro_return(){
    list root = NULL, aux;
    char n;

    while((n = getchar()) != '\n'){
        if(root == NULL){
            root = (list)malloc(sizeof(struct list_element));
            aux = root;
        }else{
            aux->next=(list)malloc(sizeof(struct list_element));
            aux=aux->next;
        }
        aux->value=n;
        aux->next=NULL;
    }
    return root;
}


int main(){
    
    list l = inserisciDietro_return();

    printf("%d\n",ricercaInLIsta(l,'j'));

}