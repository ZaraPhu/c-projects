#include<stdio.h>
#include<stdlib.h>
#include"singly-linked.h"

int main() {
    SinglyLinkedList* listOfNumbers = (SinglyLinkedList *) malloc(sizeof(SinglyLinkedList));
    printf("%d\n", is_empty(listOfNumbers));
    append_node(listOfNumbers, 12);
    if (get(listOfNumbers, 0) != NULL) {
        printf("%lld\n", *get(listOfNumbers, 0));
    }
}
