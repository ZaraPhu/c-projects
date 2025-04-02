/*
This document is meant to store the implementation of the single linked list
data structure. Since C does not have the ability to handle generics, the data type
of each node is a 64-bit signed integer;
Author: Zara Phukan.
Creation Date: March 29, 2025.
*/

/*** Dependencies ***/
#include <stdbool.h>
#include <stdint.h>
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

Node* between_node(int64_t data, Node* prev, Node* next) {
    Node* new = prev_node(data, next);
    prev->next = new;
    return new;
}

bool search_forward(Node* start, int64_t data) {
    Node* node = start;
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

uint64_t size(SinglyLinkedList* list_ptr) {
    return list_ptr->size;
}

int64_t* to_array(SinglyLinkedList* list_ptr) {
    if(is_empty(list_ptr)) {
        return NULL;
    }
    uint64_t size = list_ptr->size;
    // needs to be heap-allocated so it doesn't get freed when
    // the function is popped off the stack
    int64_t* arr = (int64_t *) malloc(sizeof(int64_t) * list_ptr->size);
    Node* node = list_ptr->head;
    for (int i = 0; i < size; i++) {
        arr[i] = node->data;
        node = node->next;
    }
    return arr;
}

bool contains(SinglyLinkedList* list_ptr, int64_t data) {
    return search_forward(list_ptr->head, data);
}

int64_t* get(SinglyLinkedList* list_ptr, uint64_t index) {
    if (is_empty(list_ptr)) {
        return NULL;
    } else {
        int64_t counter = 0;
        Node* node = list_ptr->head;
        while(node->next != NULL) {
            if (counter == index) {
                return &(node->data);
            }
            node = node->next;
            counter++;
        }
        return NULL;
    }
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

bool insert_node(SinglyLinkedList* list_ptr, int64_t data, uint64_t index) {
    if (is_empty(list_ptr)) {
        return false;
    } else if (index == 0) {
        list_ptr->head = (Node *) dangling_node(data);
        return true;
    } else {
        int64_t counter = 0;
        Node* prev_node = list_ptr->head;
        Node* node = list_ptr->head;
        while(node->next != NULL) {
            node = node->next;
            if (counter == index) {
                between_node(data, prev_node, node);
                list_ptr->size++;
                return true;
            }
            prev_node = prev_node->next;
        }
        return false;
    }
}

void lazy_insert_node(SinglyLinkedList *list_ptr, int64_t data, uint64_t index) {
    if (is_empty(list_ptr) || (index == 0)) {
        list_ptr->head = dangling_node(data);
    } else {
        int64_t counter = 0;
        Node* prev_node = list_ptr->head;
        Node* node = list_ptr->head;
        while(node->next != NULL) {
            node = node->next;
            if (counter == index) {
                between_node(data, prev_node, node);
            } else {
                prev_node = prev_node->next;
            }
        }
        node->next = dangling_node(data);
        list_ptr->size++;
    }
}

bool replace_node(SinglyLinkedList* list_ptr, int64_t data, uint64_t index) {
    if (is_empty(list_ptr)) {
        return false;
    } else if (index == 0) {
        list_ptr->head = (Node *) dangling_node(data);
        return true;
    } else {
        int64_t counter = 0;
        Node* node = list_ptr->head;
        while(node->next != NULL) {
            if (counter == index) {
                node->data = data;
                return true;
            }
            node = node->next;
            counter++;
        }
        return false;
    }
}

bool delete_first(SinglyLinkedList* list_ptr) {
    if (is_empty(list_ptr)) {
        return false;
    } else {
        Node* node = list_ptr->head;
        list_ptr->head = node->next;
        free(node); // make sure to free the node
        // to prevent memory leaks
        list_ptr->size--;
        return true;
    }
}

bool delete_last(SinglyLinkedList* list_ptr) {
    if (is_empty(list_ptr)) {
        return false;
    } else {
        Node* node = list_ptr->head;
        Node* prev_node = list_ptr->head;
        while(node->next != NULL) {
            node = node->next;
            if (node->next == NULL) {
                prev_node->next = NULL;
            } else {
                prev_node = prev_node->next;
            }
        }
        free(node);
        list_ptr->size--;
        return true;
    }
}

bool delete_node(SinglyLinkedList *list_ptr, int64_t index) {
    if (is_empty(list_ptr)) {
        return false;
    } else if (index == 0) {
        Node* node = list_ptr->head;
        list_ptr->head = NULL;
        free(node);
        list_ptr->size--;
        return true;
    } else {
        int64_t counter = 0;
        Node* node = list_ptr->head;
        Node* prev_node = list_ptr->head;
        while(node->next != NULL) {
            node = node->next;
            if (counter == index) {
                prev_node->next = node->next;
                free(node);
                list_ptr->size--;
                return true;
            }
            prev_node = prev_node->next;
        }
        return false;
    }
}