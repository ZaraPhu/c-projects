/*
This document is meant to store the implementation of the single linked list
data structure. Since C does not have the ability to handle generics, the data type
of each node is a 64-bit signed integer;
Author: Zara Phukan.
Creation Date: March 29, 2025.
*/

/*** Dependencies ***/
#include<stdint.h>
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

SinglyLinkedList* create_empty_list() {
    return (SinglyLinkedList *) malloc(sizeof(SinglyLinkedList));
}

SinglyLinkedList* list_from_array(int64_t* arr, uint64_t arr_length) {
    SinglyLinkedList* list_ptr = create_empty_list();
    if (arr_length == 0) {
        return list_ptr;
    }
    for (int i = 0; i < arr_length; i++) {
        append_node(list_ptr, arr[i]);
    }
    return list_ptr;
}

SinglyLinkedList* copy(SinglyLinkedList* list_ptr) {
    SinglyLinkedList* new_list = create_empty_list();
    Node* curr_node = list_ptr->head;
    while(curr_node != NULL) {
        append_node(new_list, curr_node->data);
        curr_node = curr_node->next;
    }
    return new_list;
}

bool is_empty(SinglyLinkedList* list_ptr) {
    return (list_ptr->head == NULL);
}

uint64_t size(SinglyLinkedList* list_ptr) {
    return list_ptr->size;
}

int64_t* list_to_array(SinglyLinkedList* list_ptr) {
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

// TODO: finish this
void concat(SinglyLinkedList* src, SinglyLinkedList* dest) {
    
}

bool contains(SinglyLinkedList* list_ptr, int64_t data) {
    return search_forward(list_ptr->head, data);
}

uint64_t find(SinglyLinkedList* list_ptr, int64_t data) {
    if(is_empty(list_ptr)) {
        return UINT64_MAX;
    } else {
        uint64_t index = 0;
        Node* node = list_ptr->head;
        while(node != NULL) {
            if(node->data == data) {
                break;
            }
            node = node->next;
            index++;
        }
        return index;
    }
}

int64_t* get(SinglyLinkedList* list_ptr, uint64_t index) {
    if (is_empty(list_ptr)) {
        return NULL;
    } else {
        int64_t counter = 0;
        Node* node = list_ptr->head;
        while(node != NULL) {
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

void delete_first(SinglyLinkedList* list_ptr) {
    if (list_ptr->size == 1) {
        free(list_ptr->head);
        list_ptr->head = NULL;
        list_ptr->size = 0;
    } else {
        Node* node = list_ptr->head;
        list_ptr->head = node->next;
        free(node); // make sure to free the node
        // to prevent memory leaks
        list_ptr->size--;
    }
}

void delete_last(SinglyLinkedList* list_ptr) {
    if(list_ptr->size == 1) {
        free(list_ptr->head);
        list_ptr->head = NULL;
        list_ptr->size = 0;
    } else {
        Node* prev_node = list_ptr->head;
        Node* node = prev_node->next;
        while(node != NULL) {
            if (node->next == NULL) {
                prev_node->next = NULL;
                break;
            }
            prev_node = node;
            node = node->next;
        }
        free(node);
        list_ptr->size--;
    }
}

void delete_node(SinglyLinkedList *list_ptr, int64_t index) {
    // needs to be rewritten, it was NOT GOOD before
}

void clear(SinglyLinkedList* list_ptr) {
    if (!(is_empty(list_ptr))) {
        while(list_ptr->head!= NULL) {
            delete_first(list_ptr);
        }
    }
}

void reverse_list(SinglyLinkedList* list_ptr) {
    if (list_ptr->size >= 2) {
        Node* prev = NULL;
        Node* curr = list_ptr->head;
        Node* position = curr->next;
        while (position != NULL) {
            curr->next = prev;
            prev = curr;
            curr = position;
            position = position->next;
        }
        curr->next = prev;
        list_ptr->head = curr;
    }
}

bool check_circular(SinglyLinkedList* list_ptr) {
    if (is_empty(list_ptr)) {
        return false;
    } else {
        Node* t = list_ptr->head; // tortoise pointer
        Node* h = list_ptr->head; // hare pointer
        while ((h != NULL) && (h->next != NULL)) {
            t = t->next;
            h = h->next->next;
            if (t == h) {
                return true;
            }
        }
        return false;
    }
}
