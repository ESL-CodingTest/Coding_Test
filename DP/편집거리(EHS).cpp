#include<iostream>
#include<cstring>
using namespace std;

string a, b;

int d[5001][5001];

int main(){
	// 입력  
	cin>>a>>b;
	
	int size_a = a.size(), size_b = b.size();
	
	// 배열 초기화  
	for(int i=0;i<=size_a;i++) d[i][0]=i;
	for(int i=0;i<=size_b;i++) d[0][i]=i;
	
	// 다이나믹 프로그래밍  
	for(int i=1;i<=size_a;i++){
		for(int j=1;j<=size_b;j++){
			int add;
			// 해당 인덱스 문자열이 같은 경우 add=0 
			if(a[i-1]==b[j-1]) add=0;
			else add=1;
			//최솟값으로 저장  
			d[i][j]=min(min(d[i][j-1]+1, d[i-1][j]+1), d[i-1][j-1]+add);	
		}
	}	
	
	/*
	for(int i=0;i<=size_a;i++){
		for(int j=0;j<=size_b;j++) cout<<d[i][j]<<' ';
		cout<<endl;
	}
	*/
	// 답 출력 
	cout<<d[size_a][size_b]; 
}
