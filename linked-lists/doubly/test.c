/*
This file is used to hold and execute unit tests for the functions defined for
a Node for a DoublyLinkedList and for the functions for DoublyLinkedList.
Author: Zara Phukan.
Creation Date: April 4, 2025.
*/

/*** Dependencies ***/
#include"doubly-linked.h"
#include<stdbool.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

/*** Constants ***/
// for some later clarity
#define PASS true
#define FAIL false

// for Node functions
int8_t DANGLING_NODE_NUM_TESTS = 3;
int8_t NEXT_NODE_NUM_TESTS = 5;
int8_t PREV_NODE_NUM_TESTS = 5;
int8_t BETWEEN_NODE_NUM_TESTS = 7;

/*** Node Unit Tests */

/**
 * @brief Tests the dangling_node function
 * 
 * This function tests if the dangling_node function correctly creates a Node with:
 * 1. The data set to the provided value
 * 2. The next pointer set to NULL
 * 3. The prev pointer set to NULL
 * 
 * It allocates memory for an array of test results, which should be freed by the caller.
 * 
 * @return An array of boolean values indicating success (true) or failure (false) for each test
 */
bool* test_dangling_node() {
    bool* tests_status = (bool *) malloc(sizeof(bool) * DANGLING_NODE_NUM_TESTS);

    Node* node = dangling_node(INT64_MAX);
    // Test 1: data is set properly
    tests_status[0] = (node->data == INT64_MAX);

    // Test 2: next pointer is set to null
    tests_status[1] = (node->next == NULL);

    // Test 3: prev pointer is set to null
    tests_status[2] = (node->prev == NULL);

    free(node);

    return tests_status;
}

/**
 * @brief Tests the next_node function
 * 
 * This function tests if the next_node function correctly creates a Node with:
 * 1. The data set to the provided value
 * 2. The before node's next pointer set to the new node
 * 3. The new node's prev pointer set to the before node
 * 4. The new node's next pointer set to NULL
 * 5. The before node's prev pointer has not changed
 * 
 * It allocates memory for an array of test results, which should be freed by the caller.
 * 
 * @return An array of boolean values indicating success (true) or failure (false) for each test
 */
bool* test_next_node() {
    bool* tests_status = (bool *) malloc(sizeof(bool) * NEXT_NODE_NUM_TESTS);

    Node* before = dangling_node(1);
    Node* prev_before = before->prev;
    Node* node = next_node(2, before);

    // Test 1: data is set correctly
    tests_status[0] = (node->data == 2);

    // Test 2: before node's next pointer is set to node
    tests_status[1] = (before->next == node);

    // Test 3: node's prev pointer is set to before node
    tests_status[2] = (node->prev == before);

    // Test 4: node's next pointer is set to NULL
    tests_status[3] = (node->next == NULL);
    
    // Test 5: before's prev pointer has not changed
    tests_status[4] = (before->prev == prev_before);

    free(node);
    free(before);

    return tests_status;
}

/**
 * @brief Tests the prev_node function
 * 
 * This function tests if the prev_node function correctly creates a Node with:
 * 1. The data set to the provided value
 * 2. The new node's next pointer set to the after node
 * 3. The new node's prev pointer set to NULL
 * 4. The after node's prev pointer set to the new node
 * 5. The after node's next pointer has not changed
 * 
 * It allocates memory for an array of test results, which should be freed by the caller.
 * 
 * @return An array of boolean values indicating success (true) or failure (false) for each test
 */
bool* test_prev_node() {
    bool* tests_status = (bool *) malloc(sizeof(bool) * PREV_NODE_NUM_TESTS);

    Node* after = dangling_node(1);
    Node* next_after = after->next;
    Node* node = prev_node(2, after);

    // Test 1: node data is set correctly
    tests_status[0] = (node->data == 2);

    // Test 2: node's next pointer is set to after
    tests_status[1] = (node->next == after);

    // Test 3: node's prev pointer is set to NULL
    tests_status[2] = (node->prev == NULL);

    // Test 4: after's prev pointer is set to node
    tests_status[3] = (after->prev == node);

    // Test 5: after's next pointer has not changed
    tests_status[4] = (after->next == next_after);

    free(node);
    free(after);

    return tests_status;
}

/**
 * @brief Tests the between_nodes function
 * 
 * This function tests if the between_nodes function correctly creates a Node with:
 * 1. The data set to the provided value
 * 2. The new node's next pointer set to the after node
 * 3. The new node's prev pointer set to the before node
 * 4. The after node's prev pointer set to the new node
 * 5. The after node's next pointer unchanged
 * 6. The before node's next pointer set to the new node
 * 7. The before node's prev pointer unchanged
 * 
 * It allocates memory for an array of test results, which should be freed by the caller.
 * 
 * @return An array of boolean values indicating success (true) or failure (false) for each test
 */
bool* test_between_node() {
    bool* tests_status = (bool *) malloc(sizeof(bool) * BETWEEN_NODE_NUM_TESTS);

    Node* before = dangling_node(1);
    Node* before_prev = before->prev;
    Node* after = next_node(3, before);
    Node* after_next = after->next;
    Node* node = between_nodes(2, before, after);

    // Test 1: node's data is set correctly
    tests_status[0] = (node->data == 2);

    // Test 2: node's next pointer is set to after
    tests_status[1] = (node->next == after);

    // Test 3: node's prev pointer is set to before
    tests_status[2] = (node->prev == before);

    // Test 4: after's prev pointer is set to node
    tests_status[3] = (after->prev == node);

    // Test 5: after's next pointer has not changed
    tests_status[4] = (after->next == after_next);

    // Test 6: before's next pointer is set to node
    tests_status[5] = (before->next == node);

    // Test 7: before's prev pointer has not changed
    tests_status[6] = (before->prev == before_prev);

    free(node);
    free(before);
    free(after);

    return tests_status;
}

/*** Helper Functions */

/**
 * @brief Displays the results of unit test functions
 *
 * This function processes an array of test results and displays whether tests passed or failed.
 * It can show detailed results for each individual test when verbose mode is enabled,
 * and always displays a summary message indicating overall test success or failure.
 *
 * @param tests_status Pointer to a boolean array containing test results (PASS/FAIL)
 * @param num_tests The number of test results in the array
 * @param verbose If true, displays detailed results for each individual test
 */
void display_test_results(bool* tests_status, int8_t num_tests, bool verbose) {
    bool all_passed = true;
    for (int8_t i = 0; i < num_tests; i++) {
        if (tests_status[i] == PASS) {
            if (verbose) {
                printf("Test %d passed", i + 1);
            }
        } else {
            if (verbose) {
                printf("Test %d failed\n", i + 1);
            }
            all_passed = false;
        }
    }
    if (all_passed) {
        printf("All tests passed!\n");
    } else {
        printf("Some tests failed!\n");
    }
}

/*** Program Starting Point */
int main() {
    bool* tests_status = test_dangling_node();
    printf("Testing dangling_node function: ");
    display_test_results(tests_status, DANGLING_NODE_NUM_TESTS, false);
    free(tests_status);
    
    tests_status = test_next_node();
    printf("Testing next_node function: ");
    display_test_results(tests_status, NEXT_NODE_NUM_TESTS, false);
    free(tests_status);
    
    tests_status = test_prev_node();
    printf("Testing prev_node function: ");
    display_test_results(tests_status, PREV_NODE_NUM_TESTS, false);
    free(tests_status);

    tests_status = test_between_node();
    printf("Testing between_node function: ");
    display_test_results(tests_status, BETWEEN_NODE_NUM_TESTS, false);
    free(tests_status);
    
    return 0;
}