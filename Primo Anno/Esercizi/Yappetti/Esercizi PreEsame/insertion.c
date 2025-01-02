#include <stdio.h>

// Funzione per l'ordinamento con insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Elemento corrente da posizionare
        int j = i - 1;

        // Sposta gli elementi maggiori di key verso destra
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Inserisce key nella posizione corretta
        arr[j + 1] = key;
    }
}

// Funzione per stampare l'array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Input dimensione dell'array
    printf("Inserisci il numero di elementi dell'array: ");
    scanf("%d", &n);

    int arr[n];

    // Input elementi dell'array
    printf("Inserisci %d elementi:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Stampa array originale
    printf("Array originale: ");
    printArray(arr, n);

    // Ordinamento con insertion sort
    insertionSort(arr, n);

    // Stampa array ordinato
    printf("Array ordinato: ");
    printArray(arr, n);

    return 0;
}