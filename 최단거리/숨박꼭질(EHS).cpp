#include<iostream>
#include<vector>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정
using namespace std;

int n, m;

// 각 노드에 연결되어 있는 노드를 담는 배열
vector<int> graph[20001];
// 방문한 적이 있는지 체크하는 목적의 배열 만들기
bool visited[20001];
// 최단 거리 테이블 만들기
int d[20001];

// 방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 번호를 반환
int getSmallestNode() {
    int min_value = INF;
    int index = 0; // 가장 최단 거리가 짧은 노드
    for (int i = 1; i <= n; i++) {
        if (d[i] < min_value && !visited[i]) {
            min_value = d[i];
            index = i;
        }
    }
    return index;
}

// 다익스트라 알고리즘  
void dijkstra(int start) {
    d[start] = 0;
    visited[start] = true;
    for (int j = 0; j < graph[start].size(); j++) {
        d[graph[start][j]] = 1;
    }
	// 시작 노드를 제외한 전체 n - 1개의 노드에 대해 반복
    for (int i = 0; i < n - 1; i++) {
        // 현재 최단 거리가 가장 짧은 노드를 꺼내서, 방문 처리
        int now = getSmallestNode();
        visited[now] = true;
        // 현재 노드와 연결된 다른 노드를 확인
        for (int j = 0; j < graph[now].size(); j++) {
            int cost = d[now] + 1;
            // 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < d[graph[now][j]]) {
                d[graph[now][j]] = cost;
            }
        }
    }
}

int main(){
	// 입력  
	cin>>n>>m;
	
	// 입력  
	for(int i=0;i<m;i++){
		int x, y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}	
	
	// 최단 거리 테이블을 모두 무한으로 초기화
    fill_n(d, 20001, INF);
	
	// 다익스트라 알고리즘 실행  
	int start = 1;
	dijkstra(start);
    
    /*
    for(int i=1;i<=n;i++){
    	cout<<d[i]<<endl;
	}
	
	for(int i=1;i<=n;i++){
    	cout<<visited[i]<<endl;
	}
	*/
	
	// 답 구하기  
	int ans_n=1, ans_v;
	for(int i=2; i<=n ;i++){
		if(d[ans_n]<d[i]) {
			ans_n=i;
			ans_v=d[i];	
		}
	}
	
	int ans_c=0;
	for(int i=1;i<=n;i++){
		if(d[ans_n]==d[i]) ans_c++;
	}
	
	// 답 출력  
	cout<<ans_n<<' '<<ans_v<<' '<<ans_c;
}

