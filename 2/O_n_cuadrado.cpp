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
void i_coma_j(int N)
{   
    for(int i=0;i<N && cuenta();i++)
    {   
        for(int j=0;j<N && cuenta();j++)
            {
                cout<<i<<" , "<<j <<" . ";
            }
    }
}    
int main(){
    int tam_a=10;
    i_coma_j(tam_a);
    cout<<"\nN tiene "<<tam_a<<" de tamanio";
    cout<<"\nEl # de intrucciones ejecutadas es "<<nro_instrucciones;
    return 0;
}