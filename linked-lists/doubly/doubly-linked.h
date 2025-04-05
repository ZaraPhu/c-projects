/*
This header file is used to declare the Node struct, and the
functions used to manage a doubly linked list of Nodes.
Author: Zara Phukan.
Creation Date: April 4, 2025.
*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

/*** Dependencies ***/
#include<stdint.h>
#include<stdlib.h>
#include<stdbool.h>


/*** Struct Defintiions */


/**
 * @struct Node
 * @brief A structure representing a node in a doubly linked list.
 *
 * This structure contains the data stored in the node and pointers
 * to the previous and next nodes in the list.
 */
typedef struct Node {
    int64_t data;     /**< The data stored in this node */
    struct Node* prev;       /**< Pointer to the previous node in the list, or NULL if this is the first node */
    struct Node* next;       /**< Pointer to the next node in the list, or NULL if this is the last node */
} Node;

/**
 * @struct DoublyLinkedList
 * @brief A structure representing a doubly linked list.
 *
 * This structure maintains pointers to the head and tail of the list,
 * and keeps track of the size of the list.
 */
typedef struct {
    Node* head;       /**< Pointer to the first node in the list, or NULL if the list is empty */
    Node* tail;       /**< Pointer to the last node in the list, or NULL if the list is empty */
    int64_t size;     /**< The number of nodes in the list */
} DoublyLinkedList;


/*** Node Functions ***/

/**
 * @brief Creates a new Node with the specified data and uninitialized pointers.
 *
 * This function allocates memory for a new Node structure and initializes
 * its data field with the provided value. The previous and next pointers
 * are not initialized and the caller is responsible for setting them appropriately.
 *
 * @param data The value to store in the new node
 * @return Pointer to a newly allocated Node, or NULL if memory allocation fails.
 * @note The caller is responsible for freeing the memory when done.
 */
Node* dangling_node(int64_t data);

/**
 * @brief Creates a new Node and appends it after the specified previous node.
 *
 * This function creates a new Node with the given data and links it as the next node
 * after the provided previous node. It establishes both the forward and backward
 * connections between the two nodes in the doubly linked list.
 *
 * @param data The value to store in the new node
 * @param prev Pointer to the node that should precede the new node
 * @return Pointer to the newly created and linked Node
 * @note The caller is responsible for ensuring prev is not NULL
 * @note The new node's next pointer will be uninitialized
 */
Node* next_node(int64_t data, Node* prev);

/**
 * @brief Creates a new Node and inserts it before the specified next node.
 *
 * This function creates a new Node with the given data and links it as the previous node
 * before the provided next node. It establishes both the forward and backward
 * connections between the two nodes in the doubly linked list.
 *
 * @param data The value to store in the new node
 * @param next Pointer to the node that should follow the new node
 * @return Pointer to the newly created and linked Node
 * @note The caller is responsible for ensuring next is not NULL
 * @note The new node's prev pointer will be uninitialized
 */
Node* prev_node(int64_t data, Node* next);

/**
 * @brief Creates a new Node and inserts it between two existing nodes.
 *
 * This function creates a new Node with the given data and links it between
 * the provided previous and next nodes. It establishes both the forward and backward
 * connections between all three nodes, maintaining the integrity of the doubly linked list.
 *
 * @param data The value to store in the new node
 * @param prev Pointer to the node that should precede the new node
 * @param next Pointer to the node that should follow the new node
 * @return Pointer to the newly created and linked Node
 * @note The caller is responsible for ensuring prev and next are not NULL
 * @note prev and next should be adjacent nodes in the list for proper linking
 */
Node* between_nodes(int64_t data, Node* prev, Node* next);

/*** DoublyLinkedList Functions */

/**
 * @brief Checks if the doubly linked list is empty.
 *
 * This function determines whether the specified doubly linked list contains any nodes.
 * A list is considered empty if its size field is equal to zero.
 *
 * @param list_ptr Pointer to the DoublyLinkedList to check
 * @return true if the list is empty (contains no nodes), false otherwise
 * @note A NULL list_ptr will cause undefined behavior
 */
bool is_empty(DoublyLinkedList *list_ptr);

/**
 * @brief Searches for a specific data value by iterating from the head to the tail of the list.
 * 
 * This function traverses the doubly linked list in a forward direction (head -> tail)
 * searching for the first occurrence of the specified data value. If the value is found,
 * the function returns the index (0-based) of the node containing the value.
 * 
 * @param list_ptr Pointer to the DoublyLinkedList to search within
 * @param data The integer value to search for in the list
 * @return int64_t The 0-based index of the found node, or -1 if the value was not found
 *         or if the list is empty.
 */
int64_t forward_find(DoublyLinkedList *list_ptr, int64_t data);


/**
 * @brief Searches for a specific data value by iterating from the tail to the head of the list.
 * 
 * This function traverses the doubly linked list in a backward direction (tail -> head)
 * searching for the first occurrence of the specified data value. If the value is found,
 * the function returns the index (0-based) of the node containing the value.
 * 
 * @param list_ptr Pointer to the DoublyLinkedList to search within
 * @param data The integer value to search for in the list
 * @return int64_t The 0-based index of the found node, or -1 if the value was not found
 *         or if the list is empty.
 */
int64_t backward_find(DoublyLinkedList *list_ptr, int64_t data);

/**
 * @brief Appends a new node with the specified data to the end of the doubly linked list.
 *
 * This function creates a new node containing the provided data value and adds it
 * to the end of the list. If the list is empty, the new node becomes both the head
 * and tail of the list. The size of the list is incremented.
 *
 * @param list_ptr Pointer to the DoublyLinkedList to append to
 * @param data The value to store in the new node
 * @note If memory allocation fails during node creation, the list remains unchanged
 */
void append_node(DoublyLinkedList* list_ptr, int64_t data);


/**
 * @brief Inserts a new node with the specified data at the beginning of the doubly linked list.
 *
 * This function creates a new node containing the provided data value and adds it
 * to the beginning of the list. If the list is empty, the new node becomes both the head
 * and tail of the list. The size of the list is incremented.
 *
 * @param list_ptr Pointer to the DoublyLinkedList to prepend to
 * @param data The value to store in the new node
 * @note If memory allocation fails during node creation, the list remains unchanged
 */
void prepend_node(DoublyLinkedList* list_ptr, int64_t data);

#endif