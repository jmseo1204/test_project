#include <iostream>
using namespace std;


int main(void) {
	int T;
	cin >> T;
	int* ans = new int[T];
	for (int i=0; i<T; i++){
		int n;
		cin >> n;
		int** arr = new int* [2];
		int** res = new int* [2];
		
		for (int j=0; j<2; j++){
			arr[j]=new int[n];
			res[j]=new int[n];
		}
		for (int j = 0; j < 2*n; j++){
			cin >> arr[j/n][j%n];
		}	
		for (int j=0; j<2*n; j++){
			if (j<4){
				res[0][0]=arr[0][0];
				res[1][0]=arr[1][0];
				res[0][1]=arr[1][0]+arr[0][1];
				res[1][1]=arr[0][0]+arr[1][1];
			}else{
				int r=j%2;
				int c=j/2;
				res[r][c]=(res[(r+1)%2][c-2] > res[(r+1)%2][c-1] ? res[(r+1)%2][c-2] : res[(r+1)%2][c-1]) + arr[r][c];
			}
		}
		int temp = res[0][n-1];
		temp = res[1][n-1] > temp ? res[1][n-1] : temp;
		ans[i]=temp;	
	}
	for (int i=0; i<T; i++){
		cout << ans[i] << endl;
	}
	
	return 0;
}

