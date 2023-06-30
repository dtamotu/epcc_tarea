#include <vector>
#include <iostream>

using namespace std;

class CMyComplexDataStructure
{
    std::vector<float> m_container;
public:
    void Insert(float fVal) { m_container.push_back(fVal); }

    void mostrar()
    {
        for (size_t i = 0; i < m_container.size(); i++)
        {
            std::cout<<" ... "<<m_container[i];
        }
    }
    
    template <typename objclass>
    void sumone(objclass funobj)
    {
        vector<float>::iterator iter = m_container.begin();
        for (; iter != m_container.end() ; iter++)
        {
            funobj(*iter);
        }
    }
};

template <typename objclass>
class funcobjclass
{
public:
    void operator ()(objclass& objinstance)
    {
        objinstance++;
    }
};
int main()
{
    CMyComplexDataStructure ds;
    ds.Insert(3.5);
    ds.Insert(4.5);
    ds.Insert(6.5);
    ds.Insert(3.9);
    funcobjclass<float> x;
    ds.sumone(x);
    ds.mostrar();
    return 0;
}