#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int nro_instrucciones=0;
int nro_instrucciones2=0;
bool cuenta()
{
    nro_instrucciones++;
    return true;
}
bool cuenta2()
{
    nro_instrucciones2++;
    return true;
}
void pares(int N)
{   
    for(int i=0;i<N && cuenta();i++)
    {   
        if (i%2==0&&cuenta())
        {
            cout<<i<< " ";
        }
        
    }
}  
void pares_e_impares(int N)
{   
    for(int i=0;i<N && cuenta2();i++)
    {   
        if (i%2==0&& cuenta2())
        {
            cout<<i<< " ";
        }
        
    }
    for(int i=0;i<N && cuenta2();i++)
    {   
        if (i%2!=0 && cuenta2())
        {
            cout<<i<< " ";
        }
        
    }
}    
int main(){
    int tam_a=10;
    int tam_b=10;
    pares(tam_a);
    cout<<"\nN tiene "<<tam_a<<" de tamanio";
    cout<<"\nEl # de intrucciones ejecutadas es "<<nro_instrucciones<<"\n";
    pares_e_impares(tam_b);
    cout<<"\nN tiene "<<tam_a<<" de tamanio";
    cout<<"\nEl # de intrucciones ejecutadas es "<<nro_instrucciones2<<"\n";
    return 0;
}