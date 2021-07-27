#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n; cin>>n;
	vector<int> v(n);
	
	for(int i=0;i<n;i++) cin>>v[i];
	
	sort(v.begin(), v.end());
	
	int ans=1;
	for(int i=0;i<n;i++){
		if(ans<v[i]) break;
		ans+=v[i];
	}
	
	cout<<ans;
}
