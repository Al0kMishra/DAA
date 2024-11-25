//Q 5) Write a program to delete a linked list using recursion. Write recurrence relation for the function and perform time and space complexity analysis.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteList(struct Node* head) {
    if (head == NULL)
        return;

    deleteList(head->next);
    printf("Deleting node with data: %d\n", head->data);
    free(head);
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    deleteList(head);
    head = NULL; // Important to avoid dangling pointer
    printf("Linked list deleted.\n");
    return 0;
}

