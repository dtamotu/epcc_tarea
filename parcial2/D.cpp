#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortbli(const pair<float, float>& a, const pair<float, float>& b)
{
    return a.first < b.first;
}
vector<pair<int, int>> cover_segment(vector<pair<int, int>>& segments, int M) {
    sort(segments.begin(), segments.end(), sortbli);

    vector<pair<int, int>> covered;
    int current = 0;
    int i = 0;
    int n = segments.size();

    while (current < M && i < n) {
        int max_right = current;
        int next_segment_index = -1;

        while (i < n && segments[i].first <= current) {
            if (segments[i].second > max_right) {
                max_right = segments[i].second;
                next_segment_index = i;
            }
            i++;
        }

        if (next_segment_index != -1) {
            covered.push_back(segments[next_segment_index]);
            current = max_right;
        }
        else {
            return vector<pair<int, int>>(); 
        }
    }

    if (current >= M) {
        return covered;
    }
    else {
        return vector<pair<int, int>>(); 
    }
}

int main() {
    int num_tests;
    cin >> num_tests;

    for (int case_num = 0; case_num < num_tests; case_num++) {
        int M;
        cin >> M;

        vector<pair<int, int>> segments;
        while (true) {
            int L, R;
            cin >> L >> R;
            if (L == 0 && R == 0) {
                break;
            }
            segments.push_back(make_pair(L, R));
        }

        vector<pair<int, int>> result = cover_segment(segments, M);

        if (result.empty()) {
            cout << 0 << endl;
        }
        else {
            cout << result.size() << endl<<endl;
            for (const auto& segment : result) {
                cout << segment.first << " " << segment.second << endl;
            }
        }

        cout << endl;
    }

    return 0;
}