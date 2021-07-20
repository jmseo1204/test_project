#include <iostream>
using namespace std;

//11726

int pibo(int n, int h, int t){
	if (n==0){
		return t;
	}else{
		return pibo(n-1, t, (2*h+t)%10007);
	}
}

int main(){
	int a;
	cin >> a;
	cout << pibo(a, 0, 1);

}
