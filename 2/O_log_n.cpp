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
void doble(int N)
{   int i=1;
    while(i<N && cuenta())
    {
        cout<<i<<" ";
        i=i*2;
    }
}    
int main(){
    int tam_a=10;
    doble(tam_a);
    cout<<"\nN tiene "<<tam_a<<" de tamanio";
    cout<<"\nEl # de intrucciones ejecutadas es "<<nro_instrucciones;
    return 0;
}