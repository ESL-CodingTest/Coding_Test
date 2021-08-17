#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int start, int end) {
    if (start > end) return -1;
    int mid = (start + end) / 2;
    // 고정점을 찾은 경우 중간점 인덱스 반환  
    if (arr[mid] == mid) return mid;
    // 중간점의 값보다 중간점이 작은 경우 왼쪽 확인
    else if (arr[mid] > mid) return binarySearch(arr, start, mid - 1);
    // 중간점의 값보다 중간점이 큰 경우 오른쪽 확인
    else return binarySearch(arr, mid + 1, end);
}

int main(){
	int N;	
	cin>>N;
	
	vector<int> v(N);
	
	for(int i=0;i<N;i++) cin>>v[i];
	
	// 이진탐색
    int ans = binarySearch(v , 0, N - 1);

    // 답 출력 
    cout << ans << '\n';
}
