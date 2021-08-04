#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int* res = new int[n+1];
	for (int i=0; i<n+1; i++){
		res[i]=-1;
	}
	res[0]=0;

	for(int i=1; i<=n; i++){
		int temp=sqrt(i);
		//cout << "temp = "<<temp<<endl;
		int p;
		vector<int> comp;
		for(int j=1; j<=temp; j++){
			p=pow(j, 2);
			comp.push_back(res[i-p]+1);
		}
		res[i]=*min_element(comp.begin(), comp.end());
		//cout << "res["<<i<<"] = "<<res[i]<<endl;
	}
	cout << res[n];
}

