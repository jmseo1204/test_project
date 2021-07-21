#include <iostream>
using namespace std;

unsigned long long recur(int n, unsigned long long h, unsigned long long t){
	//h:1, t:0
	if (n==0) return h+t;
	return recur(n-1, t, h+t);
}

int main(){
	int a;
	cin >> a;
	if (a<3) cout << 1;
	else cout << recur(a-3, 1, 1);
	
}

