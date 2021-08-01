#include <iostream>
#include <cmath>
using namespace std;

/*

void recur(int n, int* arr, int** bu, int* ans, int count){
	int n2=bu[0][n];
	int n3=bu[1][n];
	if (n2+n3!=0) {
		*ans= count+n2+n3 < *ans ? count +n2+n3 : *ans;
		int temp2, temp3;
		for(int i=0; i<=n3; i++){
			int key=0;
			for (int j=0; j<=n2; j++){
				temp2=pow(2, j);
				temp3=pow(3, i);
				if (arr[n/temp2/temp3]==0){
					arr[n/temp2/temp3]=count+i+j;
				}else if(arr[n] > count){
					arr[n/temp2/temp3]=count+i+j;
				}else{
					key=1;
					break;
				}
			}
			if (key) break;
		}
	}
	if (n%3==0){
		n/=3;
		count++;
		if (arr[n]==0){
			arr[n]=count;
			recur(n, arr, bu, ans, count);
		}else if(arr[n] <= count){
			return;
		}else{
			arr[n]=count;
			recur(n, arr, bu, ans, count);
		}
	}if (n%2==0){
		n/=2;
		count++;
		if (arr[n]==0){
			arr[n]=count;
			recur(n, arr, bu, ans, count);
		}else if(arr[n] <= count){
			return;
		}else{
			arr[n]=count;
			recur(n, arr, bu, ans, count);
		}
	}
	n-
}

void bottom_up(int n, int** bu){
	int index3=0;
	int temp=0;
	while (1){
		temp = pow(3, index3);
		bu[1][temp]=index3;
		bu[0][temp]=0;
		if (temp*3>n) break;
		else index3++;
	}
	for (int i=0; i<=index3; i++){
		int index2=0;
		int temp2=pow(3, i);
		while (1){
			temp=temp2*pow(2, index2);
			bu[0][temp]=index2;
			bu[1][temp]=i;
			if (temp*2>n) break;
			else index2++;
		}
	}
	return;
}*/
void recur(int* arr, int n){
	if (n==1) return;
	int cas[3]={0,};
	if (n%3==0){
		if (arr[n/3]==0) {
			recur(arr, n/3);
		}
		cas[2]=arr[n/3]+1;
	}
	if (n%2==0){
		if (arr[n/2]==0) {
			recur(arr, n/2);
		}
		cas[1]=arr[n/2]+1;
		
	}
	if (arr[n-1]==0){
		recur(arr, n-1);
		
	}
	cas[0]=arr[n-1]+1;
	int temp=0;
	for (int i=0; i<3; i++){
		if (cas[i]!=0){
			if (temp==0) temp = cas[i];
			else temp=cas[i] < temp ? cas[i] : temp;
		}
	}
	//cout << "recur before temp"<<endl;
	//cout << "index : "<<n<<", temp : "<<temp << endl;
	arr[n]=temp;
	return;
}

int main(void) {
	int n;
	cin >> n;
	int* arr = new int[n+1];
	for (int i=0; i<n+1; i++){
		if (i==2 || i==3) arr[i]=1;
		else arr[i]=0;
	}
	recur(arr, n);
	cout << arr[n];
	
	
	

	
	
	return 0;
}

