#include<iostream>
using namespace std;

int n;

int a[501][501];
int d[501][501];

int main(){
	// 입력  
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) cin>>a[i][j];
    }
    
    // 다이나믹 프로그래밍  
    d[1][1] = a[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            d[i][j]=d[i-1][j];
            if(d[i][j]<d[i-1][j-1]) d[i][j]=d[i-1][j-1];
            d[i][j]+=a[i][j];
        }
    }
    
    // 가장 아래층 중에서 최댓값을 정답으로 갱신  
    int ans=d[n][1];
    for(int i=1;i<=n;i++){
        if(ans<d[n][i]) ans=d[n][i];
    }
    
    // 답 출력  
    cout<<ans;
}
