/* Implementar função solucao_ex3 */
// long a -rdi
// long b -rsi
// int *c -rdx
// int *d -rcx
// int  *e- r8
// int f -eax
void solucao_ex3(long a,long b ,int *c,int *d, int *e){
    *c=a<b;
    *d=a==b;
    *e=a>b;
}







