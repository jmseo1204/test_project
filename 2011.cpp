#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int stoi(string& input, int index){
	return ((int)input[index]-48)*10 + (int)input[index+1]-48;
}

void recur(string& input, int* res, int index, int size){
	int temp;
	if (index==size-1){
		//cout << "case size-1";
		temp=(int)input[index]-48;
		if (temp==0) {
			res[index]=0;
			return;
		}else res[index]=1;
		return;
	}else if(index==size){
		//cout << "Case size";
		res[size]=1;
		return;
	}else temp=stoi(input, index);
	
	if (temp>0 && temp<27){
		//cout << "Case1";
		if (10>temp){
			res[index]=0;
			return;
		}else if (temp%10==0){
			if(res[index+2]==-1){
				recur(input, res, index+2, size);
			}
			res[index]=res[index+2];
		}else{
			if(res[index+2]==-1){
				recur(input, res, index+2, size);
			}
			if(res[index+1]==-1){
				recur(input, res, index+1, size);
			}
			res[index]=(res[index+1]+res[index+2])%1000000;
		}
	}else {
		if(res[index+1]==-1){
			recur(input, res, index+1, size);
		}
		res[index]=res[index+1];
	}
	return;
}

int main(void) {
	string input;
	cin >>input;
	int size=input.size();
	int* res = new int[size+1];
	for(int i=0; i<size+1; i++){
		res[i]=-1;
	}
	recur(input, res, 0, size);
	/*for(int i=0; i<size+1; i++){
		cout << res[i] << endl;
	}*/
	cout << res[0];
	
	
	//error ex : 30 or 100 or 1003
	
	

}

