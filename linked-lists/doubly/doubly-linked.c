/*
This document is meant to store the implementation of the doubly linked list
data structure. Since C does not have the ability to handle generics, the data type
of each node is a 64-bit signed integer;
Author: Zara Phukan.
Creation Date: April 4, 2025.
*/

/*** Depedencies ***/
#include"doubly-linked.h"

/*** Node Functions ***/

Node* dangling_node(int64_t data) {
    Node* node = (Node *) malloc(sizeof(Node));
    node->data = data;
    return node;
}

Node* next_node(int64_t data, Node* prev) {
    Node* node = dangling_node(data);
    prev->next = node;
    node->prev = prev;
    return node;
}

Node* prev_node(int64_t data, Node* next) {
    Node* node = dangling_node(data);
    next->prev = node;
    node->next = next;
    return node;
}

Node* between_nodes(int64_t data, Node* prev, Node* next) {
    Node* node = dangling_node(data);
    next->prev = node;
    node->next = next;
    prev->next = node;
    node->prev = prev;
    return node;
}

/*** DoublyLinkedList Functions ***/

bool is_empty(DoublyLinkedList* list_ptr) {
    return (list_ptr->size == 0);
}

int64_t forward_find(DoublyLinkedList* list_ptr, int64_t data) {
    if (is_empty(list_ptr)) {
        return -1;
    } else {
        int64_t index = 0;
        Node* node = list_ptr->head;
        while (node != NULL) {
            if (node->data == data) {
                return index;
            }
            node = node->next;
            index++;
        }
        return -1;
    }
}

int64_t backward_find(DoublyLinkedList* list_ptr, int64_t data) {
    if (is_empty(list_ptr)) {
        return -1;
    } else {
        int64_t index = 0;
        Node* node = list_ptr->tail;
        while (node != NULL) {
            if (node->data == data) {
                return index;
            }
            node = node->prev;
            index++;
        }
        return -1;
    }
}

void append_node(DoublyLinkedList* list_ptr, int64_t data) {
    if (list_ptr->size == 0) {
        Node* node = dangling_node(data);
        list_ptr->head = node;
        list_ptr->tail = node;
    } else {
        Node* node = next_node(data, list_ptr->tail);
        list_ptr->tail = node;
    }
    list_ptr->size++;
}

void prepend_node(DoublyLinkedList* list_ptr, int64_t data) {
    if (list_ptr->size == 0) {
        Node* node = dangling_node(data);
        list_ptr->head = node;
        list_ptr->tail = node;
    } else {
        Node* node = prev_node(data, list_ptr->head);
        list_ptr->head = node;
    }
    list_ptr->size++;
}
