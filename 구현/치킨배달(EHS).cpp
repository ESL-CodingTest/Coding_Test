#include<iostream>
#include<vector>
#include<algorithm> // min함수 사용  

#define INF 2147483647 // int형 최대 범위 수  

using namespace std;

int n,m;
int homeCnt=0, chickenCnt=0;

vector<pair<int, int> > home;
vector<pair<int, int> > chicken;

// 정수n의 2진수 1비트 개수 반환   
int count_OneBits(int n){
	int cnt_OneBit = 0;
	while(n){
		if(n&1) ++cnt_OneBit;
		n = n >> 1;
	}
	return cnt_OneBit;
}

// 치킨집을 최대 M개를 골랐을 때, 도시의 치킨 거리의 최솟값을 출력
int get_distMinimum(){
	int distMinimum = INF;
	for(int set=0; set<1<<chickenCnt; set++){
		if(count_OneBits(set)==m){
			int sum=0;
			for(int i=0; i<homeCnt; i++){
				int dist = INF;
				for(int j=0; j<chickenCnt; j++){
					if(set&1<<j){
						dist = min(dist, 
						abs(home[i].first-chicken[j].first)+abs(home[i].second-chicken[j].second));
					}
				}
				sum += dist; 
			}
			distMinimum = min(distMinimum, sum);
		}
	}
	return distMinimum;
}

int main(){
	// 입출력 빨라지게 해줌. 
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	// 입력
	cin>>n>>m;

	// 입력 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int temp; cin>>temp;
			if(temp==1) {
				home.push_back({i,j});
				homeCnt++;	
			}
			else if(temp==2){
				chicken.push_back({i,j});
				chickenCnt++;	
			} 
		}
	}
	
	// 답 출력  
	int ans = get_distMinimum();
	cout<<ans;
}


