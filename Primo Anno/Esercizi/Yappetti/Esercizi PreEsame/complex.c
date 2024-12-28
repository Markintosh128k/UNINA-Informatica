#include <stdio.h>

struct Complex {
    double real;
    double imag;
};

struct Complex add(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

struct Complex subtract(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

struct Complex multiply(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

struct Complex divide(struct Complex c1, struct Complex c2) {
    struct Complex result;
    double denominator = c2.real * c2.real + c2.imag * c2.imag;
    if (denominator == 0) {
        printf("Errore: divisione per zero\n");
        result.real = 0;
        result.imag = 0;
    } else {
        result.real = (c1.real * c2.real + c1.imag * c2.imag) / denominator;
        result.imag = (c1.imag * c2.real - c1.real * c2.imag) / denominator;
    }
    return result;
}

void printComplex(struct Complex c) {
    if (c.imag >= 0) {
        printf("%.2f + %.2fi\n", c.real, c.imag);
    } else {
        printf("%.2f - %.2fi\n", c.real, -c.imag);
    }
}

int main() {
    struct Complex c1, c2, result;

    // Input dell'utente
    printf("Inserisci la parte reale e immaginaria di c1: ");
    scanf("%lf %lf", &c1.real, &c1.imag);

    printf("Inserisci la parte reale e immaginaria di c2: ");
    scanf("%lf %lf", &c2.real, &c2.imag);

    // Somma
    result = add(c1, c2);
    printf("Somma: ");
    printComplex(result);

    // Sottrazione
    result = subtract(c1, c2);
    printf("Differenza: ");
    printComplex(result);

    // Moltiplicazione
    result = multiply(c1, c2);
    printf("Prodotto: ");
    printComplex(result);

    // Divisione
    result = divide(c1, c2);
    printf("Quoziente: ");
    printComplex(result);

    return 0;
}