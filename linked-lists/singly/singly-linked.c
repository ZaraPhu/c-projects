/*
This document is meant to store the implementation of the single linked list
data structure. Since C does not have the ability to handle generics, the data type
of each node is a 64-bit signed integer;
Author: Zara Phukan.
Creation Date: March 29, 2025.
*/

/*** Dependencies ***/
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

bool contains(int64_t data, Node* head) {
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

Node* insert_node
