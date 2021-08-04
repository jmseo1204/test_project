#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	int n, k;
	cin >>n >> k;
	n+=k;
	int** res = new int*[n+1];
	for(int i=1; i<=n; i++){
		res[i]=new int[k+1];
		for(int j=1; j<=i && j<=k; j++){
			if (j==i || j==1) res[i][j]=1;
			else res[i][j]=(res[i-1][j]+res[i-1][j-1])%1000000000;
		}
	}
	cout << res[n][k];
}

