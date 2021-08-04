#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	long long **dp = new long long*[T];
	long long* ans=new long long[T];
	for (int i=0; i<T; i++){
		int n;
		cin >>n;
		dp[i]=new long long[n+5]{0,};
		dp[i][1]+=1;
		dp[i][3]+=1;
		dp[i][5]+=1;
		for(int j=1; j<n; j++){
			long long temp=dp[i][j];
			dp[i][j+1]+=temp;
			dp[i][j+5]+=temp;	
		}
		if (n==1) ans[i]=1;
		else ans[i]=dp[i][n-1];
	}
	for (int i=0; i<T; i++){
		cout << ans[i]<<endl;
	}
}

