// long a -rdi
// long b -rsi
 //long c-rbx
// long  d-rax

long vezes2(long a);

/* Implementar função solucao_ex2 */
int solucao_ex2 (long a,long b){
    long d;
    long c;
    c=a;
    a=b;
    d=vezes2(a);
    if(d>c){
        c+=c;
    }
    d+=c;
    return d;
}


