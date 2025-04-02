/*
This document is meant to store the implementation of the single linked list
data structure. Since C does not have the ability to handle generics, the data type
of each node is a 64-bit signed integer;
Author: Zara Phukan.
Creation Date: March 29, 2025.
*/

/*** Dependencies ***/
#include<stdlib.h>
#include"singly-linked.h"

/*** Node Function Implementations ***/
Node* dangling_node(int64_t data) {
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

Node* prev_node(int64_t data, Node* next) {
    Node* new = (Node *) malloc(sizeof(Node));
    new->data = data;
    new->next = next;
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

/*** SinglyLinkedList Function Implementations */

bool is_empty(SinglyLinkedList* list_ptr) {
    return (list_ptr->head == NULL);
}

bool contains(SinglyLinkedList* list_ptr, int64_t data) {
    return search_forward(list_ptr->head, data);
}

void append_node(SinglyLinkedList* list_ptr, int64_t data) {
    if (is_empty(list_ptr)) {
        list_ptr->head = dangling_node(data);
    } else {
        Node* node = list_ptr->head;
        while(node->next != NULL) {
            node = node->next;
        }
        next_node(data, node);
    }
    list_ptr->size++;
}

void prepend_node(SinglyLinkedList* list_ptr, int64_t data) {
    if (is_empty(list_ptr)) {
        list_ptr->head = (Node *) dangling_node(data);
    } else {
        Node* head = prev_node(data, list_ptr->head);
        list_ptr->head = head;
    }
    list_ptr->size++;
}

bool replace_node(SinglyLinkedList* list_ptr, int64_t data, int64_t index) {
    if (is_empty(list_ptr)) {
        return false;
    } else {
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
}
