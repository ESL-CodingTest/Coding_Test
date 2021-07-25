#include<iostream>
using namespace std;

int solution(int food_items[], int size, int k){
	int index=0;
	bool check;
	for(int i=0;i<k;){
		check=true;
		for(int j=0;j<size;j++){
			if(food_items[j]!=0){
				check=false;
			}
		}
		if(check==true) return -1;
		if(food_items[index]-1>=0) {
			food_items[index]-=1;
			i++;	
		}
		index++;
		if(index>=size) index=0;
	}
	
	if(food_items[index]==0){
		check=true;
		for(int i=0;i<size;i++){
			if(food_items[i]!=0) check=false;
		}
		if(check==true) return -1;
		
		while(true){
			index++;
			if(index>=size) index=0;
			if(food_items[index]!=0) return index+1;
		}
	}
	
	return index+1;
}

int main(){
	int food_items[] = {3,1,2};
	int k=5;
	int ans = solution(food_items, sizeof(food_items)/sizeof(food_items[0]), k);
	
	cout<<ans;
} 
