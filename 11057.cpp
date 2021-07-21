#include <iostream>
using namespace std;

int main(){
	int a;
	int fir[10]={1,1,1,1,1,1,1,1,1,1};
	int dy[10]={0,};
	cin >> a;
	
	for(int i=1; i<a; i++){
		for (int j=0; j<10; j++){
			int t=0;
			for (int k=0; k<=j; k++){
				t+=fir[k];
			}
			dy[j]=t;
		}
		for (int j=0; j<10; j++){
			fir[j]=dy[j]%10007;
		}
	}
	int temp=0;
	for (int i=0; i<10; i++){
		temp+=fir[i];
	}
	cout << temp%10007;
	
}

