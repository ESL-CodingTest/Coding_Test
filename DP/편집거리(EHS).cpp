#include<iostream>
#include<cstring>
using namespace std;

string a, b;

int d[5001][5001];

int main(){
	// �Է�  
	cin>>a>>b;
	
	int size_a = a.size(), size_b = b.size();
	
	// �迭 �ʱ�ȭ  
	for(int i=0;i<=size_a;i++) d[i][0]=i;
	for(int i=0;i<=size_b;i++) d[0][i]=i;
	
	// ���̳��� ���α׷���  
	for(int i=1;i<=size_a;i++){
		for(int j=1;j<=size_b;j++){
			int add;
			// �ش� �ε��� ���ڿ��� ���� ��� add=0 
			if(a[i-1]==b[j-1]) add=0;
			else add=1;
			//�ּڰ����� ����  
			d[i][j]=min(min(d[i][j-1]+1, d[i-1][j]+1), d[i-1][j-1]+add);	
		}
	}	
	
	/*
	for(int i=0;i<=size_a;i++){
		for(int j=0;j<=size_b;j++) cout<<d[i][j]<<' ';
		cout<<endl;
	}
	*/
	// �� ��� 
	cout<<d[size_a][size_b]; 
}
