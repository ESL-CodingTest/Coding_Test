#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

// ���� [left_value, right_value]�� �������� ������ ��ȯ�ϴ� �Լ�
int countByRange(vector<int>& v, int leftValue, int rightValue) {
    vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
    return rightIndex - leftIndex;
}

int n, x;

vector<int> v;

int main() {
    // �Է�
    cin >> n >> x;

    // �Է�
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        v.push_back(temp);
    }

    // ����Ž��  
    int ans = countByRange(v, x, x);

    // �� ���  
    if (ans == 0) cout << -1;  
    else cout << ans;  
}
