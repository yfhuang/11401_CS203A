#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node with given value
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Traverse and print memory information
void traverseList(Node* head) {
    Node* current = head;
    int index = 0;

    while (current != NULL) {
        printf("Node %d: Value = %d, Address = %p, Next = %p\n", 
               index, current->data, (void*)current, (void*)current->next);
        current = current->next;
        index++;
    }
}

int main() {
    // Create linked list: 10 -> 20 -> 30 -> NULL
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    // Traverse and print
    printf("Traversing the linked list:\n");
    traverseList(head);
    
    // Free memory
    Node* current = head;
    
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
