#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(void) {
	int n;
	cin >> n;
	int* arr = new int[n];
	int* res = new int[n];
	int temp=0;
	for (int i=0; i<n; i++){
		cin >> arr[i];
		temp+=arr[i];

		if(i==0) {
			res[0]=arr[0];
		}else if(temp<0){
			temp=0;
			res[i]=res[i-1];
		}else if(temp>res[i-1]){
			res[i]=temp;
		}else{
			res[i]=res[i-1];
		}	
	}
	if (res[n-1]<=0){
		int max=arr[0];
		for(int i=0; i<n; i++){
			max = arr[i] > max ? arr[i] : max; 
		}
		res[n-1]=max;
	}
	cout << res[n-1];
	
	return 0;
}

