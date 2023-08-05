#include <vector>
#include <iostream>

using namespace std;

vector<int> beneficios = {2, 3, 4, 5}, pesos = {1, 2, 3, 4}; //Capacidad 7
vector<int> solucion_optima;
int c=7;
class Node //Class.
{
public:
    int key;
    Node *LeftSon;
    Node *RigthSon;
    Node(int y)
    {
        this->key = y;
        this->LeftSon = nullptr;
        this->RigthSon = nullptr;
    }
    ~Node(){
       delete LeftSon;
       delete RigthSon; 
    }
    int GetValor()
    {
        return this->key;
    }
    Node *GetLeftSon()
    {
        return this->LeftSon;
    }
    Node *GetRigthSon()
    {
        return this->RigthSon;
    }

    void InsertLeftChild()
    {
        this->LeftSon = new Node(0);
    }
    void InsertRigthChild()
    {
        this->RigthSon = new Node(1);
    }
};

class BinaryTree
{
public:
    Node *root;
    BinaryTree()
    {
        this->root = new Node(-1);
    };
    ~BinaryTree(){
       delete root; 
    }
    Node *GetRoot()
    {
        return this->root;
    }

    void insertando(int h, Node *nodo, vector<int> *solucion, vector<vector<int> *> *all_results, int *benef_final);
};

void actualizaSolucion(vector<int> *solucion, int *benef_final, vector<vector<int> *> *all_results)
{
    int bene_total = 0;
    int peso_total = 0;
    for (size_t i = 0; i < solucion->size(); i++)
    {
        if ((*solucion)[i] == 1){
            bene_total += beneficios[i];
            peso_total+=pesos[i];
        }
    }

    if(peso_total <=7){
        all_results->push_back(solucion);
    }

    if (bene_total > *benef_final&&peso_total<=c){
        *benef_final = bene_total;
        solucion_optima=*solucion;
    }
        
}

void BinaryTree::insertando(int h, Node *nodo, vector<int> *solucion, vector<vector<int> *> *all_results, int *benef_final)
{
    if (h != 0)
    {

        vector<int> *ResultLeft = solucion;
        vector<int> *ResultRigth = new vector<int>(*solucion);
        nodo->InsertLeftChild();
        ResultLeft->push_back(0);
        this->insertando(h - 1, nodo->GetLeftSon(), ResultLeft, all_results, benef_final);
        nodo->InsertRigthChild();
        ResultRigth->push_back(1);
        this->insertando(h - 1, nodo->GetRigthSon(), ResultRigth, all_results, benef_final);
       
    }
    else
    {
        actualizaSolucion(solucion, benef_final,all_results);
        return;
    }
}
void mostrar_array(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void imprime( vector<vector<int> *> *all_results, int benef_final)
{
    cout<<"Capacidad de la Mochila: "<<c<<"\n";
    cout<<"Pesos de los Objetos:\n";
    mostrar_array(pesos);
    cout<<"\n Beneficios de los Objetos:\n";
    mostrar_array(beneficios);
    cout<<"\n Todos las soluciones :\n";
   for(int i=0;i<all_results->size();i++){
         for (int j = 0; j < beneficios.size(); j++)
        {
            //cout<<i<<" "<<j<<endl;
            cout<<(*(*all_results)[i])[j];
        }
        cout<<" ";
    }
    cout<<"\n \n Todos las soluciones optimas por beneficios:\n";
    for(int i=0;i<all_results->size();i++){
         for (int j = 0; j < beneficios.size(); j++)
        { 
            //cout<<i<<" "<<j<<endl;
            if((*(*all_results)[i])[j]==1)
                cout<<pesos[j];
            else 
                cout<<(*(*all_results)[i])[j];
        }
        cout<<" ";
    }
    cout<<"\n \n Pesos metidos a la mochila:\n";
    for(int i=0;i<solucion_optima.size();i++){

        if(solucion_optima[i]==1)
            cout<<pesos[i];
    }
   
    cout<<"\n Beneficio maximo obtenido: "<<benef_final;
}

void mochila()
{
    BinaryTree *tree = new BinaryTree();
    vector<int> *solucion = new vector<int>();
    vector<vector<int> *> *all_results = new vector<vector<int> *>(); 
    int benef_final = -222;
    tree->insertando(pesos.size(), tree->GetRoot(), solucion, all_results, &benef_final);
    imprime(all_results,benef_final);
   
    // limpiar  memory
    delete tree;
    for (auto vec : *all_results)
    {
        delete vec;
    }
    delete all_results;
    delete solucion;
}
int main()
{
    mochila();
    return 0;
}
