#include "macros_correcoes.h"
#include <stdio.h>
#include <stdlib.h>

int size(char *stroriginal){
    int width = 0;
    for (int i = 0; stroriginal[i]; i++){
        width++;
    }
    return width;
}

/* Recebe duas strings e concatena em uma terceira */
char *mystrcat(char *str1, char *str2) {
    /* Faça sua solução aqui!*/
    /* Pode alterar tudo, inclusive o res*/
    size_t size1=size(str1),size2=size(str2);
    size_t size = size1  + size2;
    char *res = malloc(size *(sizeof(char)) + 1);
    res[size] = '\0';

    /*if (res == NULL){
        perror("malloc");
        exit(0);
    }*/
    for (int i = 0; i < size; i++){
        res[i] = str2[i-size1];
        if (i < size1){
            res[i] = str1[i];
        }
        
    }
    return res;
}


int main(int argc, char *argv[]) {
#define teste1 "str1"
#define teste2 "str2"
#define teste3 "0 str 3"

    char *res = mystrcat(teste1, teste2);
    assertEquals("teste 1", strcmp(res, teste1 teste2), 0);
    free(res);

    res = mystrcat(teste1, teste1);
    assertEquals("teste 2", strcmp(res, teste1 teste1), 0);
    free(res);

    res = mystrcat(teste1, teste3);
    assertEquals("teste 3", strcmp(res, teste1 teste3), 0);
    free(res);

    res = mystrcat(teste3, teste1);
    assertEquals("teste 4", strcmp(res, teste3 teste1), 0);
    free(res);

    res = mystrcat("", teste2);
    assertEquals("teste vazio 1", strcmp(res, teste2), 0);
    free(res);

    res = mystrcat(teste1, "");
    assertEquals("teste vazio 2", strcmp(res, teste1), 0);
    free(res);

    res = mystrcat("", "");
    assertEquals("teste vazio 3", strcmp(res, ""), 0);
    free(res);

    printSummary
    return 0;
}