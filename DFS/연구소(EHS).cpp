#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M;

int lab[8][8]; // 연구소   
int tmp[8][8]; // 연구소 복사  

bool check[8][8]; 

vector<pair<int,int> > zero; // lab좌표 중 0인 좌표 저장  

// 연구소 복사  
void copyLab(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) tmp[i][j]=lab[i][j];
	}
}

// 바이러스 퍼트리기  
void dfs(int x, int y) {
    // 주어진 범위를 벗어나는 경우에는 즉시 종료  
    if (x <= -1 || x >=N || y <= -1 || y >= M)  return;
    // 벽을 만나면 종료  
    if(tmp[x][y]==1) {
    	check[x][y]=true;
    	return;
	}
	 
    if(check[x][y]==true) return; // 이미 체크한 위치라면 종료 
    
    check[x][y]=true;
    
    // 벽이 아니면서 바이러스가 퍼지지 않은 구역이라면  
	if(tmp[x][y] == 0) {
        tmp[x][y] = 2; // 바이러스 퍼트리기  
    }
    
    // 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
    dfs(x - 1, y);
    dfs(x, y - 1);
    dfs(x + 1, y);
    dfs(x, y + 1);
}

// 안전구역 count  
int countSafeZone(){
	int cnt=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
	    	if(tmp[i][j]==0) cnt++;
		}
	}
	return cnt;
}

int main(){
	// 입출력 빨라지게 해줌. 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// 입력  
	cin>>N>>M;
	
	// 입력  
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) cin>>lab[i][j];
	}
	
	// '0' 좌표 zero 벡터에 저장  
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(lab[i][j]==0) zero.push_back({i,j});	
		}
	}
	
	// 조합을 위한 코드  
	vector<int> ind;
	int k=3;
	for(int i=0; i<k; i++){
		ind.push_back(1);
	}
	for(int i=0; i<zero.size()-k; i++){
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end());
	
	
	int ans=0;	
	do{
		copyLab();
		
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++) check[i][j]=false;
		}
		
		// 조합  
		for(int i=0; i<ind.size(); i++){
			if(ind[i] == 1){
				tmp[zero[i].first][zero[i].second]=1;
			}
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(tmp[i][j]==2 && check[i][j]==false) dfs(i,j);
			}
		}
		
		ans = max(ans, countSafeZone());
		
	}while(next_permutation(ind.begin(), ind.end()));		
	
	// 정답 출력  
	cout<<ans;
}
