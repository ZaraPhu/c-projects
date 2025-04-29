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
    Node* tail;
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
 * @brief Creates an empty SinglyLinkedList with no nodes.
 *        Returns a pointer to the newly created SinglyLinkedList.
 *        Note: The user must manually free this list pointer when
 *        it is no longer needed to prevent memory leaks.
 * @return A pointer to a new empty SinglyLinkedList.
 */
SinglyLinkedList* create_empty_list();

/**
 * @brief Creates a SinglyLinkedList from the provided array.
 *        Returns a pointer to the newly created SinglyLinkedList.
 *        Returns an empty list if the array length is 0.
 *        Note: The user must manually free this list pointer when
 *        it is no longer needed to prevent memory leaks.
 * @param arr A pointer to the array of 64-bit integers.
 * @param arr_length The length of the array.
 * @return A pointer to a new SinglyLinkedList containing the array elements.
 */
SinglyLinkedList* list_from_array(int64_t* arr, uint64_t arr_length);

/**
 * @brief Creates a deep copy of the provided SinglyLinkedList.
 *        Returns a pointer to a new SinglyLinkedList with identical data
 *        but completely separate memory allocations.
 *        Returns an empty list if the source list is empty.
 *        Note: The user must manually free this list pointer when
 *        it is no longer needed to prevent memory leaks.
 * @param list_ptr A pointer to the SinglyLinkedList to be copied.
 * @return A pointer to a new SinglyLinkedList containing copies of all nodes.
 */
SinglyLinkedList* copy(SinglyLinkedList* list_ptr);

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

/**
 * @brief Converts the SinglyLinkedList to an array of 64-bit integers.
 *        Returns a pointer to the array of integers, allocated on the heap.
 *        This must be freed by the user to prevent memory leaks.
 *        Returns NULL if the list is empty.
 * @param list_ptr A pointer to the SinglyLinkedList to convert.
*/
int64_t* list_to_array(SinglyLinkedList* list_ptr); 

void concat(SinglyLinkedList* src, SinglyLinkedList* dest);

/**
 * @brief Returns a pointer to the data at the specified index of the SinglyLinkedList.
 *        The data is returns as a pointer, and the user must handle dereferencing 
 *        the pointer and prevent unwanted modifications to the data.
 *        Returns NULL if the list is empty or the index is out of bounds.
 * @param list_ptr A pointer to the SinglyLinkedList to get from.
 * @param index The index of the node to get the data from.
 */
int64_t* get(SinglyLinkedList* list_ptr, uint64_t index);

/**
 * @brief Searches the whole SinglyLinkedList to see if it contains the data.
 *        Returns true if the data is found, returns false otherwise.
 * @param list_ptr A pointer to the SinglyLinkedList to be searched.
 * @param data The data to search for.
*/
bool contains(SinglyLinkedList* list_ptr, int64_t data);

/**
 * @brief Searches the whole SinglyLinkedList to find the index of the node
 *        containing the data passed as a parameter. Returns the index of the
 *        node if the data is found, returns UINT64_MAX otherwise.
 * @param list_ptr A pointer to the SinglyLinkedList to be searched.
 * @param data The data to search for.
*/
uint64_t find(SinglyLinkedList* list_ptr, int64_t data);

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

/**
 * @brief Inserts a node to the given index (if possible). If the end of the 
 *        list is reached, the new node is appended to the end of the list. If
 *        the list is empty, the new node is set as the head node. 
 * @param list_ptr A pointer to the SinglyLinkedList to modify.
 * @param data The data to attach to the new node.
 * @param index The index at which to insert the new node.
 */
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

/**
 * @brief Deletes the first node in the SinglyLinkedList.
 *        If the list is empty, no action is performed.
 * @param list_ptr A pointer to the SinglyLinkedList to modify.
 */
void delete_first(SinglyLinkedList* list_ptr);

/**
 * @brief Deletes the last node in the SinglyLinkedList.
 *        If the list is empty, no action is performed.
 * @param list_ptr A pointer to the SinglyLinkedList to modify.
 */
void delete_last(SinglyLinkedList* list_ptr);

/**
 * @brief Deletes the node at the specified index in the SinglyLinkedList.
 *        If the list is empty or the index is out of bounds, no action is performed.
 * @param list_ptr A pointer to the SinglyLinkedList to modify.
 * @param index The index of the node to delete.
 */
void delete_node(SinglyLinkedList* list_ptr, int64_t index);

/**
 * @brief Clears the SinglyLinkedList by freeing all nodes and setting the
 *        head node to NULL.
 * @param list_ptr A pointer to the SinglyLinkedList to clear.
*/
void clear(SinglyLinkedList* list_ptr);

/**
 * @brief Reverses the order of nodes in the SinglyLinkedList.
 *        After calling this function, the last node becomes the first node,
 *        the second-to-last node becomes the second node, and so on.
 *        If the list is empty or contains only one node, it remains unchanged.
 * @param list_ptr A pointer to the SinglyLinkedList to reverse.
 */
void reverse_list(SinglyLinkedList* list_ptr);

/**
 * @brief Checks if the SinglyLinkedList is circular.
 *        A circular list has at least one node whose next pointer points to a previous node
 *        in the list, forming a cycle. This function uses Floyd's Cycle-Finding Algorithm 
 *        (also known as "tortoise and hare" algorithm) to detect cycles efficiently.
 * @param list_ptr A pointer to the SinglyLinkedList to check.
 * @return Returns true if the list is circular (contains a cycle), and false if the list
 *         is not circular or if the list is empty.
 */
bool check_circular(SinglyLinkedList* list_ptr);
#endif