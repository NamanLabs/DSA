#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        pq.push(num);
    }
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
