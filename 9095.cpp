#include <iostream>
using namespace std;


int fac(int n, int total=1){
	if (n==0) return total;
	else{
		total*=n;
	}
	return fac(n-1, total);
}

int div(int n){
	int mod=n%3;
	int quot=n/3;
	int turn;
	int n1, n2, n3, min;
	if (mod==0) turn=quot;
	else turn=quot+1;
	int temp=0;
	for (turn; turn<=n; turn++){
		n3=(n-turn)/2;
		n2=(n-turn)%2;
		n1=turn-n3-n2;
		min=((n3<n1) ? n3 : n1);
		for (int i=0; i<=min; i++){
			int test=fac(turn)/fac(n1-i)/fac(n2+2*i)/fac(n3-i);
			//cout << "turn : "<<turn << ", (n1 n2 n3)= "<<n1<<n2<<n3<<", test : "<<test<<endl;
			temp+=test;
		}
	}
	return temp;
}

int main(){
	int a;
	cin >> a;
	int temp;
	for (int i=0; i<a; i++){
		cin >> temp;
		cout << div(temp) << endl;
	}


}
