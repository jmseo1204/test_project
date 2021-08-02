#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(void) {
	int n;
	cin >> n;
	int* arr = new int[n];
	int** res = new int* [2];
	res[0]=new int[n]; //right-up
	res[1]=new int[n]; //right-down
	int max=0;
	for (int i=0; i<n; i++){
		cin >> arr[i];
		res[0][i]=1;
		res[1][i]=1;
	}
	
	for (int i=1; i<n; i++){
		vector<int> under;
		vector<int> over;
		for (int j=0; j<i; j++){
			if (arr[j]<arr[i]){
				under.push_back(res[0][j]);
			}
			if(arr[n-1-i]>arr[n-1-j]){
				over.push_back(res[1][n-1-j]);
			}
		}
		if (!under.empty()) res[0][i]=*max_element(under.begin(), under.end())+1;
		if (!over.empty()) res[1][n-1-i]=*max_element(over.begin(), over.end())+1;
		
	}
	for (int i=0; i<n; i++){
		max = res[0][i] + res[1][i]-1 > max ? res[0][i]+res[1][i]-1 : max; 
	}
	cout << max;
	
	
	
	return 0;
}

