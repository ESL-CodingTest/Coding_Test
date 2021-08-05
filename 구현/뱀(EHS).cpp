#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, K, L;

int map[101][101]; // 뱀이 있는 좌표는 1, 없는 좌표는 0  

vector<pair<int, int> > apple;
vector<pair<int, char> > command; 

queue<pair<int, int> > searchTail; // 꼬리 좌표를 알아내기 위한 큐  

int direction = 0;  // 0: 동 1: 서 2: 남, 3: 북  
int cx=1, cy=1;  // 머리좌표  

// 방향 설정  
void setDirection(char c){
	if(c=='L'){
		if(direction==0){
			direction=3;
		}
		else if(direction==1){
			direction=2;
		}
		else if(direction==2){
			direction=0;
		}
		else if(direction==3){
			direction=1;
		}
	}
	else if(c=='D'){
		if(direction==0){
			direction=2;
		}
		else if(direction==1){
			direction=3;
		}
		else if(direction==2){
			direction=1;
		}
		else if(direction==3){
			direction=0;
		}
	}
}

// 매개변수로 들어온 좌표값에 사과가 있는지 여부를 반환  
bool IsApple(int x, int y){
	for(int i=0;i<apple.size(); i++){
		if(apple[i].first==x && apple[i].second==y) {
			apple[i].first=-1;
			apple[i].second=-1;
			return true;
		}
	}	
	return false;
} 

// 꼬리 짜르기  
void updateTail(){
	int x = searchTail.front().first;
	int y= searchTail.front().second;
	searchTail.pop();
	map[x][y]=0;
}

int main(){
	// 입출력 빨라지게 해줌 
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	cin>>N;
	cin>>K;
	
	// 사과 위치좌표 입력  
	for(int i=0;i<K;i++){
		int x,y;
		cin>>x>>y;
		apple.push_back({x,y});
	}
	
	map[1][1]=1;
	searchTail.push({1,1});
	
	// 몇초에 어떤 방향으로 회전할지 입력  
	cin>>L;
	for(int i=0; i<L; i++){
		int x; char c;
		cin>>x>>c;
		command.push_back({x,c});  
	}
	
	// 0초부터 1초씩 늘려감  
	int ans=0;
	while(true){
		ans++;
		if(direction==0){
			if(cy+1> N) break;
			if(map[cx][cy+1]) break;
			cy+=1;
 			searchTail.push({cx,cy});
			if(IsApple(cx,cy)) map[cx][cy]=1;
			else{
				map[cx][cy]=1;
				updateTail();
			}
		}
		else if(direction==1){
			if(cy-1< 1) break;
			if(map[cx][cy-1]) break;
			cy-=1;
			searchTail.push({cx,cy});
			if(IsApple(cx,cy)) map[cx][cy]=1;
			else{
				map[cx][cy]=1;
				updateTail();
			}
		}
		else if(direction==2){
			if(cx+1> N) break;
			if(map[cx+1][cy]) break;
			cx+=1;
			searchTail.push({cx,cy});
			if(IsApple(cx,cy)) map[cx][cy]=1;
			else{
				map[cx][cy]=1;
				updateTail();
			}
		}
		else{
			if(cx-1< 1) break;
			if(map[cx-1][cy]) break;
			cx-=1;
			searchTail.push({cx,cy});
			if(IsApple(cx,cy)) map[cx][cy]=1;
			else{
				map[cx][cy]=1;
				updateTail();
			}
		}
		if(command.size()!=0){
			if(command[0].first==ans){
				setDirection(command[0].second);
				command.erase(command.begin());
			}  	
		}
	}
	
	// 답 출력  
	cout<<ans;
}
