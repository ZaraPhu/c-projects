/*
This header file is used to declare the Node struct, and the
functions used to manage a singly linked list of Nodes.
Author: Zara Phukan.
Creation Date: March 30, 2025.
*/
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

/*** Dependencies ***/
#include<stdint.h>
#include<stdbool.h>

/**
 * @brief A structure representing a node in a singly linked list.
 * Contains the data for the Node, and a pointer to the next Node.
 */
typedef struct Node {
    int64_t data;
    struct Node* next;
} Node;

/**
 * @brief A structure representing a singly linked list. It only
 *        stores the head node of the list since it can only
 *        traverses from head to tail.
 * Contains a pointer to the head node.
 */
typedef struct {
    Node* head;
} SinglyLinkedList;

/**
 * @brief Creates a new node with data attached but with the next Node
 *        pointer set to NULL.
 * @param data The data attached to the new node.
 */
Node* create_head(int64_t data);

/**
 * @brief Creates a new node with data attached and initializes the given
 *        node's next pointer to the new node.
 * @param data The data attached to the new node.
 * @param prev The previous node in the link.
 */
Node* next_node(int64_t data, Node* prev);

/**
 * @brief Searches a chain of nodes, starting with the given head node
 *        and returns true if the provided data is equal to the data
 *        in one of the nodes in the link, returns false otherwise,
 */
bool search_forward(Node* head, int64_t data);

/**
 * @brief Creates a pointer to a new SinglyLinkedList with a head node
 *        created using the data passed as the parameter.
 * @param data the data attached to the head node of the new SinglyLinkedList
 */
SinglyLinkedList* create_singly_linked_list(int64_t data);

/**
 * @brief Searches the whole SinglyLinkedList to see if it contains the data.
 *        Returns true if the data is found, returns false otherwise.
 * @param list_ptr a pointer to the SinglyLinkedList to be searched
 * @param data the data to search for
*/
bool contains(SinglyLinkedList* list_ptr, int64_t data);

/**
 * @brief Appends a node to the end of a SinglyLinkedList with the data
 *        passed as a parameter.
 * @param list_ptr a pointer to the SinglyLinkedList to append to
 * @param data the data attached to the new node to be appended
 */
void append_node(SinglyLinkedList* list_ptr, int64_t data);

bool insert_node(SinglyLinkedList* list_ptr, int64_t data, int64_t index);

#endif
