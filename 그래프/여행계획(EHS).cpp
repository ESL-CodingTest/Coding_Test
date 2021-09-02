#include<iostream>
using namespace std;

int n, m;

int map[501][501];
int plan[501];

int parent[501];

// 특정 원소가 속한 집합을 찾기  
int find_parent(int x){
	if(parent[x]!=x) return find_parent(parent[x]);
	return x;
}

// 두 원소가 속한 집합을 합치기  
void union_parent(int a, int b){
	a = find_parent(a);
	b = find_parent(b);
	if(a<b) parent[b]=a;
	else parent[a]=b;
}

int main(){
	// 입력  
	cin>>n>>m;
	
	// 입력  
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cin>>map[i][j];
	}	
	
	// 입력  
	for(int i=0;i<m;i++) cin>>plan[i];
	
	// 부모테이블에서 부모를 자기 자신으로 초기화  
	for(int i=1;i<=n;i++) parent[i]=i;
	
	// 입력 기반 union연산  
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
	
	// 답 찾기  
	bool check=false;
	int check_parent = find_parent(plan[0]);
	for(int i=1;i<m;i++){
		if(check_parent!=find_parent(plan[i])) check=true;
	}
	
	// 답 출력  
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
