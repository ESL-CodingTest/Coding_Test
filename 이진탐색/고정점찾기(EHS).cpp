#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int start, int end) {
    if (start > end) return -1;
    int mid = (start + end) / 2;
    // �������� ã�� ��� �߰��� �ε��� ��ȯ  
    if (arr[mid] == mid) return mid;
    // �߰����� ������ �߰����� ���� ��� ���� Ȯ��
    else if (arr[mid] > mid) return binarySearch(arr, start, mid - 1);
    // �߰����� ������ �߰����� ū ��� ������ Ȯ��
    else return binarySearch(arr, mid + 1, end);
}

int main(){
	int N;	
	cin>>N;
	
	vector<int> v(N);
	
	for(int i=0;i<N;i++) cin>>v[i];
	
	// ����Ž��
    int ans = binarySearch(v , 0, N - 1);

    // �� ��� 
    cout << ans << '\n';
}
