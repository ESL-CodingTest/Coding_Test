#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;

vector<pair<int, pair<int, int> > > edges;

int parent[200001];

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
	for(int i=0;i<m;i++){
		int v1, v2, cost;
		cin>>v1>>v2>>cost;
		edges.push_back({cost, {v1, v2}});
	}	
	
	// 부모테이블 초기화  
	for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    // 비용 오름차순으로 정렬  
    sort(edges.begin(), edges.end());
	
	int on=0;
	int total=0; 
    // 간선을 하나씩 확인하며
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first+1;
        int b = edges[i].second.second+1;
        total+=cost;
        // 사이클이 발생하지 않는 경우에만 집합에 포함
        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            on += cost;
        }
    }
	
	// 답 출력  
    cout << total- on;
}

/*
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11

51
*/
