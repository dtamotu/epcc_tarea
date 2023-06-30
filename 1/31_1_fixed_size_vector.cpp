#include <iostream>
int gVect[100]; /* buffer */
int gnCount=0;    /* # elementos usados */
void Insert(int elem)
{
    if(gnCount<100) /* solo se puede insertar si hay espacio disponible */
        gVect[gnCount++]=elem; /* inserta el elemento al final */
}
int main()
{   Insert(1);
    return 0;
}