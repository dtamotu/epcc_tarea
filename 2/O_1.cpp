#include <cstdio>
int nro_instrucciones;
int par_o_impar(int N)
{   
    if(N%2==0){
        nro_instrucciones++;
        printf("par");}
    else{
        nro_instrucciones++;
        printf("impar");
        }
    
}
int main(){
    int N=1000;
    par_o_impar(N);
    printf("\nEl # de intrucciones es %d\n",nro_instrucciones);
    return 0;
}