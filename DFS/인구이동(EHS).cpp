#include<iostream>
#include<queue>
#include<vector>
#include<algorithm> // abs 함수 사용  
using namespace std;

int N, L, R;

int map[50][50];    // 인구 수  
bool check[50][50]; // 인구이동(연합)  여부 확인 (이동 시 true) 

// 이동할 네 가지 방향 정의 (상, 하, 좌, 우) 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int inx, int iny) {	
    int cnt=0; // 한개의 연합을 이루는  나라 숫자  
    
    queue<pair<int, int> > q; // bfs를 위한 queue  
	vector<pair<int,int> > v; // 연합 국가 저장 vector 
	
    q.push({inx, iny});
    v.push_back({inx,iny});
    check[inx][iny]=true;
    cnt++;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 동,서,남,북에 대해서 확인  
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 주어진 땅 크기를 벗어난 경우  
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            
            // 이미 인구이동이 일어난 지역인 경우  
            if(check[nx][ny]==true) continue;
            
            // 인구수 차이가 L과 R 사이 값이라면 인구이동  
            int temp = abs(map[x][y]-map[nx][ny]);
            if (L<=temp && temp<=R) {
                q.push({nx, ny});
                v.push_back({nx,ny});
                check[nx][ny]=true;
                cnt++;
            } 
        } 
    }
    
    // 인구이동이 일어난 나라숫자가 1일 때, 즉 인구이동이 일어나지 않은경우  
    if(cnt==1) {
    	check[v[0].first][v[0].second]=false;
		v.clear();
		return; 	
	}
	
	// 인구이동하는 모든 나라의 인구 수 합계 구하기  
    int sum=0;
    for(int i=0; i<v.size(); i++){
    	sum+=map[v[i].first][v[i].second];
	}
	
	// (연합의 인구수) / (연합을 이루고 있는 칸의 개수) 구하기  
	sum = sum/cnt;
	
	// 위에서 구한 값으로 연합 국가 인구수 초기화  
	for(int i=0; i<v.size(); i++){
    	map[v[i].first][v[i].second]=sum;
	}

}

int main(){
	// 입출력 빨라지게 해줌. 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력  
    cin>>N>>L>>R;
	
	// 인구 수 입력  
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cin>>map[i][j];
	}
	
	
	int ans=0; 
	while(true){
		
		// check 배열 모두 false로 초기화  
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++) check[i][j]=false;
		}
	
		// 모든 좌표에 대해서 bfs로 국경선 개방  
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(check[i][j]==false) bfs(i,j);
			}		
		}
		
		// 연합이  발생하지 않으면 반복문 빠져나감  
		bool ch = false;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(check[i][j]==true){
				    ch=true;
					break;	
				}
			}		
		}
		if(ch==false) break;
		
		ans++; // 1일 증가  	
	}
	
	// 답 출력  
	cout<<ans;
}
