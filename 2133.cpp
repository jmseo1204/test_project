#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	if(n%2==1){
		cout << 0;
		return 0;
	}
	n/=2;
	
	int* res = new int[n+1]{1,3,};
	for(int i=2; i<=n; i++){
		//cout << "i="<<i<<endl;
		for(int j=1; j<=i; j++){
		//	cout<<"j="<<j<<endl;
			if (j==1) {
				res[i]+=res[i-1]*3;	
		//	cout << "res += "<<res[i-1]*3<<endl;
			}
			else {
				res[i]+=res[i-j]*2;
		//	cout << "res += "<<res[i-j]*2<<endl;
			}
		}
	}
	cout << res[n];
}

