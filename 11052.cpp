#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int* arr = new int[n+1];
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	int* dp = new int[n+1];
	for(int i=1; i<=n; i++){
		int temp=0;
		for(int j=1; j<=i; j++){
			
			if (j==i){
				temp = arr[i] > temp ? arr[i] : temp;
			}else{
				temp = temp < (dp[j]+arr[i-j]) ? (dp[j]+arr[i-j]) : temp; 
			}
			
		}	
		dp[i]=temp;
		//cout << "dp "<<i << " = "<<temp<<endl;
	}

	cout << dp[n];
}

