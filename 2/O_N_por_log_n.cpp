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
void serie(int N)
{   
    for(int i=0;i<N && cuenta();i++)
    {   int j=1;
        while (j<N&& cuenta())
        {
            cout<<j<< " ";
            j=j*2;
        }
        
    }
}    
int main(){
    int tam_a=10;
    serie(tam_a);
    cout<<"\nN tiene "<<tam_a<<" de tamanio";
    cout<<"\nEl # de intrucciones ejecutadas es "<<nro_instrucciones;
    return 0;
}