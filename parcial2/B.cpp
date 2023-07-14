#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

float distance(const pair<int, int>& p1, const pair<int, int>& p2) {
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

float closedistance(const vector<pair<int, int>>& points) {
    float minDistance = 10001;
    int n = points.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            float dist = distance(points[i], points[j]);
            minDistance = min(minDistance, dist);
        }
    }

    return minDistance;
}

int main() {
    int N;

    while (cin >> N && N != 0) {
        vector<pair<int, int>> points(N);

        for (int i = 0; i < N; ++i) {
            cin >> points[i].first >> points[i].second;
        }

        float distancia = closedistance(points);

        if (distancia < 10000.0) {
            cout << fixed;
            cout.precision(4);
            cout << distancia << endl;
        }
        else {
            cout << "INFINITY" << endl;
        }
    }

    return 0;
}
