#include<iostream>
#include<queue> 
using namespace std;

int n;

int d[1000];

queue<int> two, three, five;

int main(){
	// 입력  
	cin>>n;
	
	// 못생긴 수 첫번째는 1  
	d[0]=1;
	for(int i=1; i<n; i++){
		// 이전 못갱긴 수에 2,3,5 곱하기  
		two.push(d[i-1]*2);
		three.push(d[i-1]*3);
		five.push(d[i-1]*5);
		
		// 가장 작은 수를 못생긴 수 배열에 저장  
		int inputnum = min(min(two.front(), three.front()), five.front());
		d[i]=inputnum;
		
		// 중복 제거  
		if(inputnum==two.front()) two.pop();
		if(inputnum==three.front()) three.pop();
		if(inputnum==five.front()) five.pop(); 
	}	
	
	// 답 출력
	cout<<d[n-1]; 
}
