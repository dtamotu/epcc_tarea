#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int nro_instrucciones=0;
bool cuenta()
{
    nro_instrucciones++;
    return true;
}
void a_coma_b(string A, string B)
{   
for(size_t i=0;i<A.length()&& cuenta();i++)
{   
    for(size_t j=0;j<B.length() && cuenta();j++)
        {
            cout<<A[i]<<" , "<<B[j] <<" : ";
        }
}
}
int main(){
    int tam_a=10, tam_b=9;
    string A(tam_a,'0');
    string B(tam_b,'1');
    a_coma_b(A,B);
    cout<<"\nA tiene "<<tam_a<<" y B "<<tam_b<<" de tamanio";
    cout<<"\nEl # de intrucciones ejecutadas es "<<nro_instrucciones;
    return 0;
}