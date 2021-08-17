#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, double> a, pair<int ,double> b){
    if(a.second>b.second) return true;
    else if(a.second==b.second){
        if(a.first<b.first) return true;
    }
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    // �� ���������� ������ ������ ���ϱ�  
    vector<int> depart(N, 0);
    for(int i=0;i<stages.size();i++){
        if(stages[i]>N){
            for(int j=0;j<N;j++){
                depart[j]+=1;
            }
        }
        else{
            for(int j=0; j<stages[i]; j++){
                depart[j]+=1;
            }
        }
    }
    
    // �� ���������� Ŭ�������� ���ϴ� ������ ���ϱ�  
    vector<int> curStage(N,0);
    for(int i=0;i<stages.size();i++){
        if(stages[i]>N) continue;
        curStage[stages[i]-1]+=1;
    }
    
    // ������ ���ϱ�  
    vector<pair<int, double> > failRate;
    for(int i=0;i<N;i++){
        if(depart[i]==0){
            failRate.push_back({i+1,0});
        }
        else{
            double temp= (double)curStage[i]/depart[i]; 
           failRate.push_back({i+1,temp }); 
        }
        
    }
    
    // ����  
    sort(failRate.begin(), failRate.end(), cmp);
    
    // ���� �Է�  
    for(int i=0;i<N;i++){
        answer.push_back(failRate[i].first);
    }
    
    // �� ��ȯ  
    return answer;
}
