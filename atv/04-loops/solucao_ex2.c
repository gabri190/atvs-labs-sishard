
/* Implemente aqui sua versão em C da função soma_n
 * presente no arquivo ex2.o
 *
 * Chame sua função de soma_n_solucao */
//edi -int a
//rdx,edx -long or int  b
//rcx -long c
//rax,eax=long or int ret
 
// edx,edi,rcx,rdx
//eax,rax-retornos
long soma_n_solucao(int a){
    long c,b=0,ret=0;
    while(ret<a){
        c=ret;
        b+=c;
        ret+=1;
    }
    return b;
}
