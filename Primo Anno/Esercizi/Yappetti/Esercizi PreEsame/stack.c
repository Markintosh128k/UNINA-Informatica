#include <stdio.h>
#include <stdlib.h>

// Struttura per rappresentare un nodo dello stack
struct Node {
    int info;
    struct Node* next;
};

// Funzione per creare un nuovo nodo
struct Node* createNode(int info) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->next = NULL;
    return newNode;
}

// Funzione per aggiungere un elemento allo stack (push)
void push(struct Node** top, int info) {
    struct Node* newNode = createNode(info);
    newNode->next = *top;
    *top = newNode;
    printf("%d è stato aggiunto allo stack.\n", info);
}

// Funzione per rimuovere un elemento dallo stack (pop)
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Lo stack è vuoto, impossibile eseguire il pop.\n");
        return -1; // Valore indicativo
    }

    struct Node* temp = *top;
    int poppedValue = temp->info;
    *top = temp->next;
    free(temp);
    printf("%d è stato rimosso dallo stack.\n", poppedValue);
    return poppedValue;
}

// Funzione per visualizzare i campi info dello stack
void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Lo stack è vuoto.\n");
        return;
    }

    printf("Contenuto dello stack:\n");
    struct Node* current = top;
    while (current != NULL) {
        printf("%d -> ", current->info);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stack = NULL;

    // Operazioni di esempio
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Visualizzazione dello stack
    displayStack(stack);

    // Rimozione di un elemento
    pop(&stack);

    // Visualizzazione dello stack dopo il pop
    displayStack(stack);

    return 0;
}