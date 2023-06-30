#include <vector> 
#include <list>
#include <iostream>
using namespace std;
// Class CVector definition
template<class Type>
class CVector
{
private:

    Type* m_pVect; // Puntero al búfer
    int m_nCount, // Controla cuántos elementos se utilizan realmente
        m_nMax, // Controla cuántos se han asignado como máximo
        m_nDelta; // Para controlar el crecimiento
    void Init(int); // Inicializa nuestras variables privadas, etc.
    void Resize(); // Cambia el tamaño del vector cuando se produce un desbordamiento
public:
    int get_m_nCount()
    {
        return this->m_nCount;
    }
    int get_m_nMax()
    {
        return this->m_nMax;
    }

    CVector(int); // Constructor
    void Insert(Type&); // Insert a new element
    // More methods go here
};

template<class Type>
CVector<Type>::CVector(int delta) // Constructor
{
    this->Init(10);
    this->m_nCount = this->m_nMax = 0;
    this->m_pVect = NULL;
}

template<class Type>
void CVector<Type>::Init(int delta)
{
    this->m_nDelta = delta;
}

template<class Type>
void CVector<Type>::Resize()
{
    this->m_pVect = (int*) realloc(this->m_pVect, sizeof(int) * (this->m_nMax + this->m_nDelta));

    // The Max has to be increased by delta
    this->m_nMax += this->m_nDelta;
}

template<class Type> void CVector<Type>::Insert(Type &elem)
{
    if( this->m_nCount == this->m_nMax ) // Verify the overflow
    {
        Resize(); // Resize the vector before inserting elem
    }
    this->m_pVect[this->m_nCount++] = elem; // Insert the element at the end
}

int main()
{
    int val=91;
    CVector<int> A{0};

    for (int i = 1; i <= val; i++)
    {
        A.Insert(i);
    }
    
    std::cout<<"Inserting "<<val<<" valores.\n-> m_nCount: "<<A.get_m_nCount()<<"\n-> m_nMax: "<<A.get_m_nMax();

}