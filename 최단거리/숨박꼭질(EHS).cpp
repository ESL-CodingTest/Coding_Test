#include<iostream>
#include<vector>
#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����
using namespace std;

int n, m;

// �� ��忡 ����Ǿ� �ִ� ��带 ��� �迭
vector<int> graph[20001];
// �湮�� ���� �ִ��� üũ�ϴ� ������ �迭 �����
bool visited[20001];
// �ִ� �Ÿ� ���̺� �����
int d[20001];

// �湮���� ���� ��� �߿���, ���� �ִ� �Ÿ��� ª�� ����� ��ȣ�� ��ȯ
int getSmallestNode() {
    int min_value = INF;
    int index = 0; // ���� �ִ� �Ÿ��� ª�� ���
    for (int i = 1; i <= n; i++) {
        if (d[i] < min_value && !visited[i]) {
            min_value = d[i];
            index = i;
        }
    }
    return index;
}

// ���ͽ�Ʈ�� �˰���  
void dijkstra(int start) {
    d[start] = 0;
    visited[start] = true;
    for (int j = 0; j < graph[start].size(); j++) {
        d[graph[start][j]] = 1;
    }
	// ���� ��带 ������ ��ü n - 1���� ��忡 ���� �ݺ�
    for (int i = 0; i < n - 1; i++) {
        // ���� �ִ� �Ÿ��� ���� ª�� ��带 ������, �湮 ó��
        int now = getSmallestNode();
        visited[now] = true;
        // ���� ���� ����� �ٸ� ��带 Ȯ��
        for (int j = 0; j < graph[now].size(); j++) {
            int cost = d[now] + 1;
            // ���� ��带 ���ļ� �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ���
            if (cost < d[graph[now][j]]) {
                d[graph[now][j]] = cost;
            }
        }
    }
}

int main(){
	// �Է�  
	cin>>n>>m;
	
	// �Է�  
	for(int i=0;i<m;i++){
		int x, y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}	
	
	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
    fill_n(d, 20001, INF);
	
	// ���ͽ�Ʈ�� �˰��� ����  
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
	
	// �� ���ϱ�  
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
	
	// �� ���  
	cout<<ans_n<<' '<<ans_v<<' '<<ans_c;
}

