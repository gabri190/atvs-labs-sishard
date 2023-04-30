/* Implementar função solucao_ex1 */
// long a -rdi
// long b -rsi
// long c -rdx
// long d -rcx
// long e- rax
int solucao_ex1(long a,long b, long c,long d){
    long e;
    e=a+b*1;
    d=e+c*4;
    a*=a;
    e=a+b*2;
    c+=e;
    e=d>=c;
    return e;

}   
   
   
   

