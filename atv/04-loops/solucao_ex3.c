/* Implemente aqui sua versão em C da função ex3
 * presente no arquivo ex3.o
 * 
 * Chame sua função de ex3_solucao */
//rax,rdx

// rdi- long a
//rsi - long b
//rdx - long c
// rcx,ecx-long or int d
//r8,r8d - long or int e
//rax -long ret

long ex3_solucao(long a, long b) {
    long d = 0,e=0,ret,c;
    while (d < a) {
        ret = d / b;
        c = d % b;
        if (c == 0) {
            e += d;
        }
        d += 1;
    }
    return e;
}
