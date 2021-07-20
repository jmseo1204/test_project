#include <iostream>
using namespace std;
//1 1 11 12 132 145 1595 161414 17202814 1.8.27.48.42
//1 2 3  4   5   6    7    8     9          10  
/*
int calc(int i){
	int n=i-9;
	int key;
	int over10[7]={0,1,8,27,48,42,0};
	for (n; n>0; n--){
		if (n%2==1) {
			key=1;
		}else{
			key=-1;
		}
		for (int i=1; i<=5; i++){
				over10[i]=(over10[i]+over10[i+key])%1000000000;
			}
	}
	int temp=0;
	for (int i=0; i<7; i++){
		temp+=over10[i];
	}
	return temp;
}

int main(){
	int a;
	int under9[10]={1,1,2,3,6,10,20,35,70, 126};
	cin >> a;
	int* p = new int[2*a];
	for (int i=0; i<a; i++){
		if (i<10) p[2*i+1]=under9[i];
		else {
			p[2*i+1]= calc[i];
		}
		if (i==0){
			p[2*i]=10;
		}else{
			p[2*i]=(2*p[2*(i-1)]-2*p[2*i-1]+1000000000)%1000000000;
		}
	}
	cout << (p[2*(a-1)]-p[2*a-1]+1000000000)%1000000000;
	delete [] p;

}*/

int main(){
	unsigned int p[5]={1,1,1,1,1};
	unsigned int dy[5]={0,0,0,0,0};
	int a;
	cin >> a;
	for (int i=1; i<a; i++){
		for (int j=0; j<5; j++){
			if (j==0) dy[j]=p[j+1];
			else if (j==4) dy[j]=p[j-1]+p[j];
			else {
				dy[j]=p[j-1]+p[j+1];
			}	
		}
		for (int j=0; j<5; j++){
			p[j]=dy[j]%1000000000;
		}
	}
	int temp=0;
	for (int i=0; i<5; i++){
		temp+=p[i];
		temp%=1000000000;
	}
	temp*=2;
	temp%=1000000000;
	temp-=p[0];
	temp+=1000000000;
	temp%=1000000000;
	cout << temp;
}

