#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef int (*rm_fn)(Node const *);

int rm_even(Node const * n) {
    return !(n->data % 2);
}

void rm_if(Node** head, rm_fn rm)
{
    for (Node** curr = head; *curr != NULL;) {
        Node* entry = *curr;
        if (rm(entry)) {
            *curr = entry->next;
            free(entry);
        } else {
            curr = &(entry->next);
        }
    }
}

void insert_node(Node** head, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    return;
}

void rm_all(Node* head) {
    if (head == NULL) {
        return;
    } else {
        Node* p = head->next;
        free(head);
        rm_all(p);
    }
}

int main(void)
{
    Node* head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    for (Node* p = head; p != NULL; p = p->next) {
        printf("%d\n", p->data);
    }
    rm_if(&head, rm_even);
    for (Node* p = head; p != NULL; p = p->next) {
        printf("%d\n", p->data);
    }
    rm_all(head);
    head = NULL;
    return 0;
}
