#include <iostream>
using namespace std;


int main(void) {
	int n;
	cin >> n;
	int* arr=new int[n];
	int** res = new int* [4];
	for (int i=0; i<4; i++){
		res[i]=new int[n];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i==0){
			res[0][0]=0;
			res[1][0]=arr[0];
			res[2][0]=0;
			res[3][0]=arr[0];
			
		}else{
			res[0][i]=res[2][i-1];
			res[1][i]=(res[0][i-1] > res[2][i-1] ? res[0][i-1] : res[2][i-1]) +arr[i];
			res[2][i]=(res[1][i-1] > res[3][i-1] ? res[1][i-1] : res[3][i-1]);
			res[3][i]=res[1][i-1]+arr[i];
			
		}
		}
	//res0 - 00
	//res1 - 01
	//res2 - 10
	//res3 - 11
	
	int temp=res[0][n-1];
	temp= res[1][n-1] > temp ? res[1][n-1] : temp;
	temp= res[2][n-1] > temp ? res[2][n-1] : temp;
	temp= res[3][n-1] > temp ? res[3][n-1] : temp;
	
	cout << temp;
	
	return 0;
}

