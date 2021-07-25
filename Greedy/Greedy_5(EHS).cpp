#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,m; cin>>n>>m;
	
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	
	sort(v.begin(), v.end());
	
	int ans=0;
	for(int i=0;i<n-1;i++){
		int a = v[i];
		for(int j=i+1; j<n; j++){
			if(a!=v[j]) ans++;
		}
	}
	
	cout<<ans;
} 
