#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

// 값이 [left_value, right_value]인 데이터의 개수를 반환하는 함수
int countByRange(vector<int>& v, int leftValue, int rightValue) {
    vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
    return rightIndex - leftIndex;
}

int n, x;

vector<int> v;

int main() {
    // 입력
    cin >> n >> x;

    // 입력
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        v.push_back(temp);
    }

    // 이진탐색  
    int ans = countByRange(v, x, x);

    // 답 출력  
    if (ans == 0) cout << -1;  
    else cout << ans;  
}
