// TODO implemente aqui uma funcao chamada "solucao"
//edi- int a
// rsi -long b
// rdx -long c
//eax - long d
int solucao(long a, int b, int *c){
    int d;
    a+=a;
    d=(b+b*4);
    d+=a;
    *c=d;
    d=b+b*2;
    d+=a;
    return d;

}
