#include<iostream>
#include <cmath>

using namespace std;
int M=6;
int const tam_p=3;
int const p[tam_p]={2,3,4};

int const tam_b=3;
int b[tam_b]={1,2,5};

int const tam_mochi=6;
int V[tam_p+1][tam_mochi+1];

void caso_base(){
    for(int i=0;i<=tam_p;i++){
        for(int j=0;j<=tam_b;j++){
            V[i][j]=0;
        }
    }
}
void recomponer()
{
    int j=M;
    int x[tam_p];
    for(int i=tam_p; i>=1;i--)
    {
        if(V[i][j]==V[i-1][j])
            x[i]=0;
        else
        {
            x[i]=1;
            j=j-p[i];
        }
    }
    for(int i=0; i<tam_p;i++){
        cout<<x[i]<<" ";
    }
}
int main()
{
     
    for(int i=1;i<=tam_p;i++){
        for(int j=1;j<=M;j++){
            if(j-p[(i-1)]<0)
                V[i][j]=V[i-1][j];
            else
                V[i][j]=max(V[i-1][j], b[(i-1)]+V[i-1][j-p[(i-1)]]);
            
        }
    }
   
   for(int i=0;i<=tam_p;i++){
        for(int j=0;j<=M;j++){
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    recomponer();
    return 0;
} 

