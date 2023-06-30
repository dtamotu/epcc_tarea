
#include <iostream>
struct Vector;
void Resize(int *& rpVect, int& rnMax);
void Resize(Vector *pThis);
void Insert(int *& rpVect, int& rnCount, int& rnMax, int elem)
{
    if( rnCount == rnMax )      /* Verify the overflow */
        Resize(rpVect, rnMax);  /* Resize the vector before inserting elem */
    rpVect[rnCount++] = elem;   /* Insert the element at the end of the sequence */
}
void Resize(int *& rpVect, int& rnMax)
{
    const int delta = 10;   /* Used to increase the vector size */
    rpVect = reinterpret_cast<int*>(realloc(rpVect, sizeof(int) * (rnMax + delta)));
    rnMax += delta;         /* The Max has to be increased by delta */
}
struct Vector
{
    int
    m_nCount,   // Control how many elements are actually used
    m_nMax,     // Control how many are allocated as maximum
    m_nDelta;   // To control the growing
    int*m_pVect;// Pointer to the buffer
};
void Insert(Vector *pThis, int elem)
{
    if( pThis->m_nCount == pThis->m_nMax ) // Verify the overflow
        Resize(pThis); // Resize the vector before inserting elem
    // Insert the element at the end of the sequence
    pThis->m_pVect[pThis->m_nCount++] = elem;
}
void Resize(Vector *pThis)
{
    pThis->m_pVect = (int *)realloc(pThis->m_pVect, sizeof(int) *
                (pThis->m_nMax + pThis->m_nDelta));
    // The Max has to be increased by delta
    pThis->m_nMax += pThis->m_nDelta;
}
int main(){
    Vector *pastel= new Vector();
    *pastel={0,3,5,NULL};
    for(int i=0;i<4;i++)
        Insert(pastel,i);
    return 0;
}