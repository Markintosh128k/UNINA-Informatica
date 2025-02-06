/*Ua se ti dico che sto codice l'ho fatto sul pc del polacco in classe??
Grazie Sergio...Domani mi riprendo ventoy figlio di troia.*/

#include <stdio.h>

// Separo due funzioni cosi' non piangi tu che vuoi un codice pulito
// Questo stampa la matrice
void stampaMatrice(int mat[][100], int n){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
}

// Questo la trasporta
void trasportaMatrice(int mat[][100], int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

// Qui ci sta il main (Ma non mi dire...)
int main(){
    int n;
    // Lmao ho fatto gli input fr?
    printf("Inserisci l'ordine della matrice: ");
    scanf("%d", &n);

    int mat[100][100];

    // Qui il programma calcola la matrice in base a quanti elementi vanno inseriti
    printf("inserisci gli elementi della matrice:\n");
    for (int i=0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    // Mentre qui stampo sia la matrice originale che dichiaro i metodi per trasportarla
    printf("\nMatrice originale:\n");
    stampaMatrice(mat, n);

    trasportaMatrice(mat, n);

    printf("\nMatrice Trasposta:\n");
    stampaMatrice(mat, n);

    // Il programma qua finisce, iscriviti e metti la campanella womp womp
    return 0;
}