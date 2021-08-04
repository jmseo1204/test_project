#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//01 10 11 
//10->1
//11->0
//01->1 or 0
int main(void) {
	int n;
	cin >> n;
	int* arr = new int[n];
	int** res = new int*[3];
	for(int i=0; i<3; i++){
		res[i]=new int[n];
	}
	for (int i=0; i<n; i++){
		cin >> arr[i];
		if (i==0) {
			res[0][0]=0;
			res[1][0]=arr[0];
			res[2][0]=arr[0];
				
		}else{
			res[0][i]=res[1][i-1] > res[2][i-1] ? res[1][i-1] : res[2][i-1];
			res[1][i]=res[2][i-1]+arr[i];
			res[2][i]=res[0][i-1]+arr[i];
		}
	}

	cout << (res[1][n-1] > res[2][n-1] ? res[1][n-1] : res[2][n-1]);
	return 0;
}

