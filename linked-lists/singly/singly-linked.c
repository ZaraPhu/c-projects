/*
This document is meant to store the implementation of the single linked list
data structure. Since C does not have the ability to handle generics, the data type
of each node is a 64-bit signed integer;
Author: Zara Phukan.
Creation Date: March 29, 2025.
*/

/*** Dependencies ***/
#include <stdint.h>
#include<stdlib.h>
#include "singly-linked.h"

/*** Functions ****/
Node* create_head(int64_t data) {
    Node* new = (Node *) malloc(sizeof(Node));
    new->data = data;
    return new;
}

Node* next_node(int64_t data, Node* prev) {
    Node* new = (Node *) malloc(sizeof(Node));
    new->data = data;
    prev->next = new;
    return new;
}

bool search_forward(Node* head, int64_t data) {
    Node* node = head;
    if (node->data == data) {
        return true;
    }
    while(node->next != NULL) {
        node = node->next;
        if (node->data == data) {
            return true;
        }
    }
    return false;
}

SinglyLinkedList* create_singly_linked_list(int64_t data) {
    Node* head = (Node *) create_head(data);
    SinglyLinkedList* list_ptr = (SinglyLinkedList *) malloc(sizeof(SinglyLinkedList));
    list_ptr->head = head;
    return list_ptr;
}

bool contains(SinglyLinkedList* list_ptr, int64_t data) {
    return search_forward(list_ptr->head, data);
}

void append_node(SinglyLinkedList* list_ptr, int64_t data) {
    Node* node = list_ptr->head;
    while(node->next != NULL) {
        node = node->next;
    }
    next_node(data, node);
}

bool insert_node(SinglyLinkedList* list_ptr, int64_t data, int64_t index) {
    int64_t counter = 0;
    Node* node = list_ptr->head;
    while(node->next != NULL) {
        node = node->next;
        counter++;
        if (counter == index) {
            node->data = data;
            return true;
        }
    }
    return false;
}
