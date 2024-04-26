#include "dict.h"
#include "transformation.h"
#include <stdio.h>
#include <stdlib.h>


dictionary* init_dict() {
    dictionary *new_dict = malloc(sizeof(dictionary));
    new_dict->head = NULL;
    new_dict->tail =  NULL;
    new_dict->nb_keys = 0;
    return new_dict;
}


void detruire_dict(dictionary *D) {

    if (D->head == NULL) {
        printf("Nothing to free\n");
        return;
    } 

    cell_dict *curr = D->head;
    while (curr != NULL) {
        cell_dict *tmp = curr;
        curr = curr->next;
        free(tmp->c);
        free(tmp); 
    }
    D->head = NULL;
}


cell_dict* find_relation(dictionary *D, int key) {

    cell_dict *new_cell = D->head;

    if (D->head == NULL) {
       // printf("Error, the dictionary is empty\n");
        return new_cell;

    }
    for (int i = 0; i < D->nb_keys && new_cell != NULL; i++) {
        if (new_cell->key == key) {
            return new_cell;
        } else {
            new_cell = new_cell->next;
        }
    }
    return new_cell;
}

Cellule_D* get_value(dictionary *D, int key) {

    if (D->head == NULL) {
        printf("Error, the dictionary is empty\n");
        return NULL;
    }
    cell_dict *cell = find_relation(D, key);
    return cell->c;
}

void add_key(dictionary *D, int key, Cellule_D *Value) {

    cell_dict *new_cell = malloc(sizeof(cell_dict));
    new_cell->c = Value;
    new_cell->key = key;
    new_cell->next = NULL;

    if (D->head == NULL) {
        D->head = new_cell;
        D->nb_keys = 1;
        D->tail = new_cell;        
    } else {
        cell_dict *cell = find_relation(D,key);
        if (cell == NULL) {
            D->tail->next = new_cell;
            D->tail = D->tail->next;
            D->nb_keys++;
        } else {
            cell->c = Value;
        }
    }
}