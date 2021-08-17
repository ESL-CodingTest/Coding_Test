#include<iostream>
#include<queue>
using namespace std;

int n;

// 우선순위 큐 (오름차순)  
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
	// 입력  
	cin>>n;
	
	// 입력  
	for(int i=0;i<n;i++){
		int temp; cin>>temp;
		pq.push(temp);
	}	
	
	// 입력이 한개일 경우 
	if(pq.size()==1){
		// 입력이 1개이면서 입력값이 1인경우  
		if(pq.top()==1){
			cout<<0;
			return 0;
		}
		
		cout<<pq.size();
		return 0;
	}
	
	int ans=0;
	while(true){
		int x = pq.top(); pq.pop();	
		int y = pq.top(); pq.pop();
		
		ans = ans + (x+y);
		
		if(pq.size()==0) break;
		
		pq.push(x+y);
	}	
	
	// 답 출력  
	cout<<ans;
} 
