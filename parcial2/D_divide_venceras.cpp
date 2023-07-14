#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortbli(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first < b.first;
}

vector<pair<int, int>> cover_segment(vector<pair<int, int>>& segments, int start, int end, int M) {
    if (start > end) {
        return vector<pair<int, int>>();
    }

    sort(segments.begin() + start, segments.begin() + end + 1, sortbli);

    vector<pair<int, int>> covered;
    int max_right = -1;

    for (int i = start; i <= end; i++) {
        if (segments[i].first <= M && (max_right == -1 || segments[i].second > segments[max_right].second)) {
            max_right = i;
        }
    }

    if (max_right == -1 || segments[max_right].second < M) {
        return vector<pair<int, int>>();
    }

    covered.push_back(segments[max_right]);

    if (segments[max_right].second >= M) {
        return covered;
    }

    vector<pair<int, int>> left_covered = cover_segment(segments, start, max_right - 1, M);
    vector<pair<int, int>> right_covered = cover_segment(segments, max_right + 1, end, M);

    if (!left_covered.empty()) {
        covered.insert(covered.end(), left_covered.begin(), left_covered.end());
    }
    if (!right_covered.empty()) {
        covered.insert(covered.end(), right_covered.begin(), right_covered.end());
    }

    return covered;
}

int main() {
    int num_tests;
    cin >> num_tests;

    for (int case_num = 0; case_num < num_tests; case_num++) {
        int M;
        cin>>M;

        vector<pair<int, int>> segments;
        while (true) {
            int L, R;
            cin>>L>> R;
            if (L == 0 && R == 0) {
                break;
            }
            segments.push_back(make_pair(L, R));
        }

        vector<pair<int, int>> result = cover_segment(segments, 0, segments.size() - 1, M);

        if (result.empty()) {
            cout<<'0'<<endl;
        }
        else {
            cout << result.size() << endl;
            for (const auto& segment : result) {
                cout<<segment.first<<" "<<segment.second<<endl;
            }
        }
        cout <<endl;
    }

    return 0;
}
