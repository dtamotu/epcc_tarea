#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct Item {
    int benefit;
    int weight;
};

struct Node {
    int level;
    int benefit;
    int weight;
    double lowerBound;
    double upperBound;
};

bool compareItemsByRatio(const Item& item1, const Item& item2) {
    return static_cast<double>(item1.benefit) / item1.weight > static_cast<double>(item2.benefit) / item2.weight;
}

double MochilaVoraz( const Node& node,int capacity, const vector<Item>& items) {

    double bacum,pacum;
    bacum=pacum=0;
    int i = node.level + 1;
    if (node.level >= items.size() ) {
        return 0;
    }

    if (items[i].weight > capacity) {
        return 0;
    }

    for(;i<items.size();i++){
        if(pacum+items[i].weight<=capacity){
            pacum=pacum+items[i].weight;
            bacum=bacum+items[i].benefit;
        }
    }
    return bacum;
}

double calculateBound(const Node& node, int capacity, const vector<Item>& items) {
    if (node.weight >= capacity)
        return 0;

    double bound = node.benefit;
    int j = node.level + 1;
    int totalWeight = node.weight;

    while (j < items.size() && totalWeight + items[j].weight <= capacity) {
        totalWeight += items[j].weight;
        bound += items[j].benefit;
        j++;
    }

    /*if (j < items.size()) {
        bound += static_cast<double>(capacity - totalWeight) / items[j].weight * items[j].benefit;
    }*/

    return bound;
}

bool isSolution(const Node& node, int capacity) {
    return node.weight <= capacity;
}

void branchAndBoundKnapsack(int capacity, const vector<Item>& items, Node& solution) {
    vector<Node> activeNodes;
    double lowerBoundRoot = 0+calculateBound({1, 0, 0, 0, 0}, capacity, items);
    double upperBoundRoot = calculateBound({-1, 0, 0, 0, 0}, capacity, items);
    activeNodes.push_back({-1, 0, 0, lowerBoundRoot, upperBoundRoot});

    double C = 0;

    while (!activeNodes.empty()) {
        Node x = activeNodes.back();
        activeNodes.pop_back();
        if ( x.upperBound > C) {//x.upperBound > solution.benefit &&
            if (x.level == items.size() - 1) {
                if (isSolution(x, capacity) && x.benefit > solution.benefit && x.weight <= capacity) {
                    solution = x;
                }
                continue;
            }

            int nextLevel = x.level + 1;
            // Crear nodos 'withNext' y 'withoutNext' como se hace en el algoritmo
            Node withNext = {
                    nextLevel,
                    x.benefit + items[nextLevel].benefit,
                    x.weight + items[nextLevel].weight,
                    0, 0
            };

            withNext.lowerBound = withNext.benefit + MochilaVoraz(withNext, capacity-withNext.weight, items);
            withNext.upperBound = x.upperBound;//MochilaVoraz(withNext, capacity, items);

            Node withoutNext = {
                    nextLevel,
                    x.benefit,
                    x.weight,
                    0, 0
            };
            withoutNext.lowerBound = withoutNext.benefit + MochilaVoraz(withoutNext, capacity-x.weight, items);
            withoutNext.upperBound = x.upperBound;//calculateBound(withoutNext, capacity, items);

            if (isSolution(withoutNext, capacity) && withoutNext.benefit > solution.benefit) {
                solution = withoutNext;
                C = max(C,static_cast<double>( withoutNext.benefit));

            } else if (!isSolution(withoutNext, capacity-x.weight) && withoutNext.upperBound > C) {
                activeNodes.push_back(withoutNext);
                C = max(C, static_cast<double>(withoutNext.lowerBound));
            }
            if(withoutNext.lowerBound==withoutNext.upperBound)
                activeNodes.push_back(withoutNext);

            if (isSolution(withNext, capacity) && withNext.benefit > solution.benefit) {
                solution = withNext;

                C = max(C, static_cast<double>(withNext.benefit));
            } else if (!isSolution(withNext, capacity) && withNext.upperBound > C) {
                activeNodes.push_back(withNext);
                C = max(C, static_cast<double>(withNext.lowerBound) );
            }
            if(withNext.lowerBound==withNext.upperBound)
                activeNodes.push_back(withNext);


        }
    }
}

int main() {
    int capacity = 61;
    vector<Item> items = {{11, 1}, {21, 11}, {31, 21}, {33, 23},{43,33}};
    //int capacity = 7;
    //vector<Item> items = {{2, 1}, {3, 2}, {4, 3}, {5, 4}};
    sort(items.begin(), items.end(), compareItemsByRatio);

    Node solution = {-1, 0, 0, 0, 0};
    branchAndBoundKnapsack(capacity, items, solution);

    cout << "Solucion optima:\n";
    cout << "Beneficios: " << solution.benefit << endl;
    cout << "Pesos: " << solution.weight << endl;

    return 0;
}
