/*
    list.c
*/
#include <string.h>  

#ifdef _WIN32
#include <malloc.h>  
#define strdup _strdup
#endif

#include "list.h"

/* Initialize list */
void list_init(List *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
}

/* Destroy list */
void list_destroy(List *list) {
    void *data;
    while (list_size(list) > 0) {
        if (list_rem_next(list, NULL, (void**)&data) == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }
    /* Clear the structure */
    list->head = NULL;
    list->tail = NULL;
    list->destroy = NULL;
    list->size = 0;
}

/* Insert after node. If node is NULL, insert at head */
int list_ins_next(List *list, ListNode *node, const void *data) {
    ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
    if (new_node == NULL) return -1;

    new_node->data = (void*)data;

    if (node == NULL) {
        /* Insert at head */
        new_node->next = list->head;
        list->head = new_node;
        if (list_size(list) == 0)
            list->tail = new_node;
    } else {
        new_node->next = node->next;
        node->next = new_node;
        if (node == list->tail)
            list->tail = new_node;
    }

    list->size++;
    return 0;
}

/* Remove node after given node. If node is NULL, remove head */
int list_rem_next(List *list, ListNode *node, void **data) {
    if (list_size(list) == 0) return -1;

    ListNode *old_node;
    if (node == NULL) {
        old_node = list->head;
        *data = old_node->data;
        list->head = old_node->next;
        if (list_size(list) == 1)
            list->tail = NULL;
    } else {
        if (node->next == NULL) return -1;
        old_node = node->next;
        *data = old_node->data;
        node->next = old_node->next;
        if (old_node == list->tail)
            list->tail = node;
    }

    free(old_node);
    list->size--;
    return 0;
}

/* Find previous node of a given node. Returns NULL if node is head or not found */
ListNode *list_prev(List *list, ListNode *node) {
    if (node == list->head || list_size(list) == 0) return NULL;

    ListNode *current = list->head;
    while (current != NULL && current->next != node) {
        current = current->next;
    }
    return current;  /* Will be NULL if node not found */
}

