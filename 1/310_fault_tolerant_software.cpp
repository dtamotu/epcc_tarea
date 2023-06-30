#include <iostream>
using namespace std;
double division1(double a, double b);
void division(int x, int y){
    double z;
    try // our critical section with possible exceptions begins here
    {
    z = division1(x, y);
    cout << z;
    }
    catch (int errorcode) // catching the exception
    {
    cout<<"No esta permitida la division entre zero";
    }
}
double division1(double a, double b)
{
    if ( b == 0.0 )
    throw (int)0; // an exceptions is thrown here
    return a/b;
}

int main()
{   cout<<"1/0 ";
    division(1,0);
    cout<<"\n1/2 ";
    division(1,2);
    return 0;
}