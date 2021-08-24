#include<iostream>
#include<queue> 
using namespace std;

int n;

int d[1000];

queue<int> two, three, five;

int main(){
	// �Է�  
	cin>>n;
	
	// ������ �� ù��°�� 1  
	d[0]=1;
	for(int i=1; i<n; i++){
		// ���� ������ ���� 2,3,5 ���ϱ�  
		two.push(d[i-1]*2);
		three.push(d[i-1]*3);
		five.push(d[i-1]*5);
		
		// ���� ���� ���� ������ �� �迭�� ����  
		int inputnum = min(min(two.front(), three.front()), five.front());
		d[i]=inputnum;
		
		// �ߺ� ����  
		if(inputnum==two.front()) two.pop();
		if(inputnum==three.front()) three.pop();
		if(inputnum==five.front()) five.pop(); 
	}	
	
	// �� ���
	cout<<d[n-1]; 
}
