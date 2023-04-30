#include <stdio.h>
#include <stdlib.h>
#include "macros_correcoes.h"

/* Copia string e retorna uma nova string */
int size(char *stroriginal){
    int width = 0;
    for (int i = 0; stroriginal[i]; i++){
        width++;
    }
    return width;
}
/* Copia string e retorna uma nova string */
char *mystrcpy(char *stroriginal) {
    /* Faça sua solução aqui!*/
    /* Pode alterar tudo, inclusive o res*/
    size_t width = size(stroriginal);
    char *res = malloc(width *(sizeof(char)) + 1);
    res[width] = '\0';
    /*if (res == NULL){
        perror("malloc");
        exit(0);
    }*/
    for (int i = 0; i < width; i++){
        res[i] = stroriginal[i];
    }
    return res;
}


int main(int argc, char *argv[]) {
    char *strcopia;

    char *s1 = "AAAAA";
    char *t1 = mystrcpy(s1);
    assertEquals("Teste 1", strcmp(s1, t1), 0);
    assertDifferent("Teste 1 - endereço diferente", s1, t1);
    free(t1);

    s1 = "";
    t1 = mystrcpy(s1);
    assertEquals("Teste 2", strcmp(s1, t1), 0);
    assertDifferent("Teste 2 - endereço diferente", s1, t1);
    free(t1);

    s1 = "AaAa123384739jlkfjdsl";
    t1 = mystrcpy(s1);
    assertEquals("Teste 3", strcmp(s1, t1), 0);
    assertDifferent("Teste 3 - endereço diferente", s1, t1);
    free(t1);

    s1 = "Aa00asdsada";
    t1 = mystrcpy(s1);
    assertEquals("Teste 4", strcmp(s1, t1), 0);
    assertDifferent("Teste 4 - endereço diferente", s1, t1);
    free(t1);

    s1 = "0asgfd";
    t1 = mystrcpy(s1);
    assertEquals("Teste 5", strcmp(s1, t1), 0);
    assertDifferent("Teste 5 - endereço diferente", s1, t1);
    free(t1);

    printSummary

    return 0;
}

