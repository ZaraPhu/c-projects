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


/*** Struct Definitions ***/


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
 * Contains a pointer to the head node and a 64-bit unsigned 
 * integer representing the size of the list.
 */
typedef struct {
    Node* head;
    uint64_t size;
} SinglyLinkedList;


/*** Node Functions ***/


/**
 * @brief Creates a new node with data attached but with the next Node
 *        pointer set to NULL.
 * @param data The data attached to the new node.
 */
Node* dangling_node(int64_t data);

/**
 * @brief Creates a new node with data attached and initializes the given
 *        node's next pointer to the new node.
 * @param data The data attached to the new node.
 * @param prev The previous node in the link.
 */
Node* next_node(int64_t data, Node* prev);

/**
 * @brief Creates a new node with data attached and initializes the
 *        the new node's pointer to the given node.
 * @param data The data attached to the new node.
 */
Node* prev_node(int64_t data, Node* next);

/**
 * @brief Creates a new node with data attached between the 
 *        prev and next nodes. First sets new node's next
 *        pointer to the next node, then sets the prev node's 
 *        next pointer to the new node. This is done to preserve
 *        the order of a SinglyLinkedList.
 * @param data The data attached to the new node.
 * @param prev The node to point to the new node.
 * @param next The node which the new node will point to.
 */
Node* between_node(int64_t data, Node* prev, Node* next);

/**
 * @brief Searches a chain of nodes, starting with the given head node
 *        and returns true if the provided data is equal to the data
 *        in one of the nodes in the link, returns false otherwise.
 * @param start The node to start the search.
 * @param data The data to search for.
 */
bool search_forward(Node* start, int64_t data);


/*** SinglyLinkedList Functions ***/


/**
 * @brief Returns true if linked is empty and false otherwise.
 * @param list_ptr A pointer to a SinglyLinkedList.
*/
bool is_empty(SinglyLinkedList* list_ptr);

/**
 * @brief Returns the size of the given list.
 * @param list_ptr A pointer to a SinglyLinkedList.
*/
uint64_t size(SinglyLinkedList* list_ptr);

int64_t* to_array(SinglyLinkedList* list_ptr); 

/**
 * @brief Searches the whole SinglyLinkedList to see if it contains the data.
 *        Returns true if the data is found, returns false otherwise.
 * @param list_ptr A pointer to the SinglyLinkedList to be searched.
 * @param data The data to search for.
*/
bool contains(SinglyLinkedList* list_ptr, int64_t data);

/**
 * @brief Appends a node to the end of a SinglyLinkedList with the data
 *        passed as a parameter. If the list has no head node, then 
 *        the head node is set to the new node.
 * @param list_ptr A pointer to the SinglyLinkedList to append to.
 * @param data The data attached to the new node to be appended.
 */
void append_node(SinglyLinkedList* list_ptr, int64_t data);

/**
 * @brief Prepends a node to the start of a SinglyLinkedList with the
 *        the data passed as a parameter. If the list has no head node,
 *        then the head node is set to the new node.
 * @param list_ptr A pointer to the SinglyLinkedList to modify.
 * @param data The data attach to the new node to be prepended.
 */
void prepend_node(SinglyLinkedList* list_ptr, int64_t data);

/**
 * @brief Inserts a node to the given index (if possible). If successful,
 *        returns true. If unseccessful or list is empty, returns false.
 * @param list_ptr A pointer to the SinglyLinkedList to modify.
 * @param data The data to attach to the new node.
 * @param Where to insert the 
 */
bool insert_node(SinglyLinkedList* list_ptr, int64_t data, uint64_t index);

void lazy_insert_node(SinglyLinkedList* list_ptr, int64_t data, uint64_t index);

/**
 * @brief Replaces the data for the node at the specified index of the
 *        SinglyLinkedList. Returns true if successfully replaced the data
 *        and returns false if it couldn't reach the index.
 * @param list_ptr a pointer to the SinglyLinkedList to be inserted into
 * @param data the attached to the new node to be inserted
 * @param index the index at which to insert the new node
 */
bool replace_node(SinglyLinkedList* list_ptr, int64_t data, uint64_t index);

#endif