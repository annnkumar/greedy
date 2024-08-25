#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    double r1 = (p1.first * 1.0) / (p1.second * 1.0);
    double r2 = (p2.first * 1.0) / (p2.second * 1.0);
    return r1 > r2;
}

double fractionalKnapsack(vector<int>& profit, vector<int>& weight, int n, int w) {
    vector<pair<int, int> > arr;  // Note the space between > >

    for (int i = 0; i < n; i++) {
        arr.push_back(make_pair(profit[i], weight[i]));  // Use make_pair instead of brace initialization
    }

    sort(arr.begin(), arr.end(), cmp);

    double result = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i].second <= w) {
            result += arr[i].first;
            w -= arr[i].second;
        } else {
            result += ((arr[i].first * 1.0) / arr[i].second) * w;
            w = 0;
            break;
        }
    }
    return result;
}

int main() {
    int profitArray[] = {60, 100, 120};  // Use arrays
    int weightsArray[] = {10, 20, 30};   // Use arrays
    vector<int> profit(profitArray, profitArray + 3);
    vector<int> weights(weightsArray, weightsArray + 3);
    
    int w = 50;
    int n = 3;

    double result1 = fractionalKnapsack(profit, weights, n, w);

    cout << "Maximum profit is " << result1 << endl;

    return 0;
}