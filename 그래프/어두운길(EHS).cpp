#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;

vector<pair<int, pair<int, int> > > edges;

int parent[200001];

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
	for(int i=0;i<m;i++){
		int v1, v2, cost;
		cin>>v1>>v2>>cost;
		edges.push_back({cost, {v1, v2}});
	}	
	
	// �θ����̺� �ʱ�ȭ  
	for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    // ��� ������������ ����  
    sort(edges.begin(), edges.end());
	
	int on=0;
	int total=0; 
    // ������ �ϳ��� Ȯ���ϸ�
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first+1;
        int b = edges[i].second.second+1;
        total+=cost;
        // ����Ŭ�� �߻����� �ʴ� ��쿡�� ���տ� ����
        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            on += cost;
        }
    }
	
	// �� ���  
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
