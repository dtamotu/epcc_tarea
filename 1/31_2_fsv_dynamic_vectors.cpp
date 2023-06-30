#include <iostream>
int *gpVect = NULL,
gnCount = 0,
gnMax = 0;

void Resize();
void Insert(int elem)
{
    if( gnCount == gnMax ) Resize();
        gpVect[gnCount++] = elem; 
}
void Resize()
{
    const int delta = 10; 
    gpVect = (int *)(realloc(gpVect, sizeof(int) * (gnMax + delta)));

    /* sustitutos alternativos, sino se usan devuelve___ error: invalid conversion from 'void*' to 'int*' */
        // reinterpret_cast<int*>(realloc..
        // (int *)(realloc..
        // static_cast<int*>(realloc..

        /* code Alternativo a realloc.. */
    // int *pTemp, i;
    // pTemp = new int[gnMax + delta];  /* Alloc a new vector */
    // for(i = 0 ; i < gnMax ; i++)     /* Transfiere elementos */
    //      pTemp[i] = gpVect[i];       /* we can also use the function memcpy */
    // delete [ ] gpVect;   /* delete the old vector */
    // gpVect = pTemp;      /* Actualiza puntero */
    gnMax += delta;         /* The Max has to be increased by delta */
}
int main()
{
    Resize();
    return 0;
}