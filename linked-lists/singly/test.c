#include<stdio.h>
#include "singly-linked.h"

int main() {
    Node* a = create_head(12);
    printf("%lld\n", a->data);
    Node* b = next_node(14, a);
    printf("%lld\n", b->data);
    printf("%p\n", a->next);
    printf("%p\n", b);

    printf("%d\n", contains(12, a));
    printf("%d\n", contains(13, b));
}
