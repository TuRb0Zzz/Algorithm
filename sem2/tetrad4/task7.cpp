#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCouriers(vector<int>& orders, int K, int T) {

    sort(orders.begin(), orders.end(), greater<int>());
    
    vector<int> couriers(K, 0);
    int usedCouriers = 0;
    
    for (int distance : orders){
        bool assigned = false;
        for (int i = 0; i < usedCouriers; ++i) {
            if (couriers[i] + distance <= T) {
                couriers[i] += distance;
                assigned = true;
                break;
            }
        }
        
        if (!assigned) {
            if (usedCouriers < K && distance <= T) {
                couriers[usedCouriers] = distance;
                usedCouriers++;
            } else {
                return -1;
            }
        }
    }
    
    return usedCouriers;
}

int main() {
    int N, K, T;
    cout << "number of orders (N): ";
    cin >> N;
    cout << "number of kurers (K): ";
    cin >> K;
    cout << "max len of way (T): ";
    cin >> T;
    
    vector<int> orders(N);
    cout << "Enter order distances: ";
    for (int i = 0; i < N; ++i) {
        cin >> orders[i];
    }
    
    int result = minCouriers(orders, K, T);
    if (result == -1) {
        cout << "impossible" << endl;
    } else {
        cout << "min number of kurers: " << result << endl;
    }
    
    return 0;
}