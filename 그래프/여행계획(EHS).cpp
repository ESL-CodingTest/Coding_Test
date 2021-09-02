#include<iostream>
using namespace std;

int n, m;

int map[501][501];
int plan[501];

int parent[501];

// Ư�� ���Ұ� ���� ������ ã��  
int find_parent(int x){
	if(parent[x]!=x) return find_parent(parent[x]);
	return x;
}

// �� ���Ұ� ���� ������ ��ġ��  
void union_parent(int a, int b){
	a = find_parent(a);
	b = find_parent(b);
	if(a<b) parent[b]=a;
	else parent[a]=b;
}

int main(){
	// �Է�  
	cin>>n>>m;
	
	// �Է�  
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cin>>map[i][j];
	}	
	
	// �Է�  
	for(int i=0;i<m;i++) cin>>plan[i];
	
	// �θ����̺��� �θ� �ڱ� �ڽ����� �ʱ�ȭ  
	for(int i=1;i<=n;i++) parent[i]=i;
	
	// �Է� ��� union����  
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i<j && map[i][j]==1) union_parent(i,j); 
		}
	}
	
	/*
	for(int i=1;i<=n;i++){
		cout<<find_parent(i)<<endl;
	}
	*/
	
	// �� ã��  
	bool check=false;
	int check_parent = find_parent(plan[0]);
	for(int i=1;i<m;i++){
		if(check_parent!=find_parent(plan[i])) check=true;
	}
	
	// �� ���  
	if(check==true) cout<<"NO";
	else cout<<"YES";
}
/*
5 4
0 1 0 1 1
1 0 1 1 0
0 1 0 0 0
1 1 0 0 0
1 0 0 0 0
2 3 4 3
*/
