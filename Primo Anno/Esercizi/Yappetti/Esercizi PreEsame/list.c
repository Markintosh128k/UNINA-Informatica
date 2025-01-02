#include <stdio.h>
#include <stdlib.h>

// Definizione del nodo della linked list
struct Node {
    int data;
    struct Node* next;
};

// Funzioni di supporto
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Inserimento iterativo
void insertSortedIterative(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Inserimento ricorsivo
struct Node* insertSortedRecursive(struct Node* head, int data) {
    if (head == NULL || head->data >= data) {
        struct Node* newNode = createNode(data);
        newNode->next = head;
        return newNode;
    }

    head->next = insertSortedRecursive(head->next, data);
    return head;
}

int main() {
    struct Node* head = NULL;

    // Test con la versione iterativa
    printf("Inserimento iterativo:\n");
    insertSortedIterative(&head, 10);
    insertSortedIterative(&head, 5);
    insertSortedIterative(&head, 20);
    insertSortedIterative(&head, 15);
    printList(head);

    // Test con la versione ricorsiva
    printf("Inserimento ricorsivo:\n");
    head = insertSortedRecursive(head, 12);
    head = insertSortedRecursive(head, 1);
    head = insertSortedRecursive(head, 25);
    printList(head);

    return 0;
}