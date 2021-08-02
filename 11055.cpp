#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//1로 dp 초기화
 

int limit_left_up(int* arr, int index, int limit){
	int temp = index;
	while(1){
		if (temp==0) break;
		temp--;
		if (arr[temp]>=arr[index] && arr[temp]<limit) return temp;
	}
	return -1;
}

int left_down(int* arr, int index){
	int temp=index;
	while(1){
		if (temp==0) break;
		temp--;
		if (arr[temp]<arr[index]) return temp;
	}
	return -1;
}


void recur(int* arr, int* res, int index){
	vector<int> under;
	int min_index=left_down(arr, index);
	//cout << "min index when index = " <<index << " -> "<< min_index<<endl;
	if (min_index==-1) {
		res[index]=arr[index];
		return;
	}else{
		if (res[min_index]==0) {
		recur(arr, res, min_index);
		}
		under.push_back(res[min_index]);	
		int temp;
		while(1){
			temp=limit_left_up(arr, min_index, arr[index]);
			if (temp==-1) break;
			else if (res[temp]==0){
				recur(arr, res, temp);
			}
			under.push_back(res[temp]);
			min_index=temp;
		}
	}
	/*cout << "i = "<< index <<" -> under : ";
	for (int i=0; i<under.size(); i++){
		cout<<under[i]<<" ";
	}
	cout << endl;
	*/
	res[index]=*max_element(under.begin(), under.end())+arr[index];
	return;
}

int main(void) {
	int n;
	cin >> n;
	int* arr = new int[n];
	int* res = new int[n];
	int max=0;
	for (int i=0; i<n; i++){
		cin >> arr[i];
		res[i]=0;
	
	}
	for (int i=0; i<n; i++){
		recur(arr, res, i);
		//cout << "res["<<i<<"] = "<<res[i]<<endl;
		max = res[i] > max ? res[i] : max; 
		//cout << "max = "<< max << endl;
	}
	cout << max;
	
	
	
	return 0;
}

