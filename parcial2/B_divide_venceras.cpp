#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Point;

bool compareY(Point a, Point b) {
    return a.second < b.second;
}

bool compareX(Point a, Point b) {
    return a.first < b.first;
}

//distancia euclidiana
float distance(Point p1, Point p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

//resolviendo el problema más pequeño
float bruteForce(vector<Point>& P, int start, int end) {
    float minDist = 999999;
    for (int i = start; i <= end; i++) {
        for (int j = i + 1; j <= end; j++) {
            float dist = distance(P[i], P[j]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    return minDist;
}

float stripClosest(vector<Point>& strip, float d) {
    float minDist = d;
    sort(strip.begin(), strip.end(), compareY);
    int n = strip.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && (strip[j].second - strip[i].second) < minDist; j++) {
            float dist = distance(strip[i], strip[j]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    return minDist;
}

float closestRecursive(vector<Point>& P, int start, int end) {
    int n = end - start + 1;
    if (n <= 3) {
        return bruteForce(P, start, end);
    }

    int mid = (start + end) / 2;
    Point midPoint = P[mid];

    float dl = closestRecursive(P, start, mid);
    float dr = closestRecursive(P, mid + 1, end);
    float d = min(dl, dr);

    vector<Point> strip;
    for (int i = start; i <= end; i++) {
        if (abs(P[i].first - midPoint.first) < d) {
            strip.push_back(P[i]);
        }
    }

    float stripDist = stripClosest(strip, d);
    return min(d, stripDist);
}

void closedistance(vector<Point>& points) {
    int n = points.size();
    sort(points.begin(), points.end(), compareX);
    float minDistance= closestRecursive(points, 0, n - 1);

    if(minDistance<10000)
        cout<<minDistance<<endl;
    else
        cout<<"INFINITY"<<endl;
}

int main() {
    int N;
    while(cin >> N){
        if(N==0)
            break;

        vector<Point> points(N);
        for (int i = 0; i < N; i++)
        {
            int X,Y;
            cin >>X>>Y;
            points[i]=make_pair(X, Y);
        }
        closedistance(points);
    }
    return 0;
}
