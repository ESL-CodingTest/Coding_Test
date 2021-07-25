#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n; cin>>n;
	
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	
	sort(v.begin(), v.end());
	
	int ans=0;
	int cnt=0, max=0;
	for(int i=0;i<n;i++){
		if(max<v[i]) max=v[i];
		cnt++;
		if(cnt==max) {
			ans++;
			max=0;
			cnt=0;
		}
	}
	
	cout<<ans;
}
