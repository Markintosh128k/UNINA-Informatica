#include <stdio.h>

// Funzione di partizione
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Scegliamo il primo elemento come pivot
    int left = low + 1;   // Puntatore a sinistra
    int right = high;     // Puntatore a destra

    while (1) {
        // Trova un elemento a sinistra che deve essere scambiato
        while (left <= right && arr[left] <= pivot) {
            left++;
        }

        // Trova un elemento a destra che deve essere scambiato
        while (left <= right && arr[right] > pivot) {
            right--;
        }

        // Se i puntatori si incontrano, interrompi
        if (left > right) {
            break;
        }

        // Scambia gli elementi fuori posto
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

    // Posiziona il pivot nella posizione corretta
    arr[low] = arr[right];
    arr[right] = pivot;

    // Restituisce l'indice della posizione del pivot
    return right;
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

    // Esegui la partizione
    int pivotIndex = partition(arr, 0, n - 1);

    // Stampa i risultati
    printf("Array dopo la partizione (pivot in posizione %d):\n", pivotIndex);
    printArray(arr, n);

    return 0;
}