#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;
/*
class tree{
	public:
		tree(int value) : value(value), left(NULL), right(NULL), child(1) {	
		}
		~tree(){
			if (right!=NULL){
				delete right;
			}
			if(left!=NULL){
				delete left;
			}
		}
		void make(int value){ //완전이진트리 
			child+=1;
			stack<bool> s;
			int temp=child;
			while(1){
				if(temp==1) break;
				else {
					s.puch(temp%2);
					temp/=2;
				}
			}
			tree* temp(this);
			while(!s.size()==1){
				if(s.top()==0) temp=temp->left;
				else temp=temp->right;
				s.pop();
				temp.child+=1;
			}
			if (s.top()==0) temp->left=new tree(value);
			else temp->right=new tree(value);
			return;
		}
		void make(int value){
			if (this->value < value){
				if (this->right!=NULL) this->right->make(value);
				else this->right=new tree(value);
			}else{
				if (this->left!=NULL) this->left->make(value);
				else this->left=new tree(value);
			}
			return;
		} 
		void search(){
			if(left!=NULL) left->search();
			cout << value << endl;
			if(right==NULL) return;
			else right->search();
			return;
		}
		
		tree* find(int index){ // index -> tree*
			tree* temp(this);
			while(index!=1){
				if (index%2) temp=temp->right;
				else temp = temp-> left;
				index/=2;
			}
			return temp;
		}
		bool comp(tree* pv, tree* t){  //tree* -> exchange value
			
			if (pv->value < t->value) return true;
			return false;
		}
		/*void quick(){
			if(this.child==1) return;
			int pivot=this;
			for(int i=this.child; i>1 i){
				if (!comp(pivot, find(i)))
			}
		}
		
		int value;
		int child;
		tree* left;
		tree* right;
	
};



void quick(int* start, int* end){ //quick sort algorithm
	int pivot=*start;
	//cout << "pivot "<<pivot<<endl;
	int* i=start;
	int* j=end;
	if(i>=j ) {
		//cout << "return"<<endl;
		return;
	}
	else if(i+1==j){
		if (*i>*j){
			int temp = *i;
			*i=*j;
			*j=temp;
		}
		return;
	}
	while(1){
		if(*i<=pivot){
			i++;
		}
		if(*j>=pivot){
			j--;
		}
		if(i>=j) break;
		if(*i>pivot && *j<pivot){
			int temp=*i;
			*i=*j;
			*j=temp;
		}
	}
	int* pidx;
	if(*i>pivot){
		int temp=*(i-1);
		*(i-1)=pivot;
		*start=temp;
		pidx=i-1;
	}else{
		int temp = *i;
		*i=pivot;
		*start=temp;
		pidx=i;
	}
	quick(start, pidx-1);
	quick(pidx+1, end);
	return;	
}
*/
void ex(int* arr, int i1, int i2){
	int temp=arr[i1];
	arr[i1]=arr[i2];
	arr[i2]=temp;
	return;
}
void mheap(int* arr, int i){
	if (i==1) return;
	if(arr[i/2] < arr[i]){
		ex(arr, i/2, i);
		mheap(arr, i/2);
	}
	return;
}

void sheap(int* arr, int i){
	ex(arr, 1, i);
	//cout << arr[i] <<" = arr["<<i<<"] in sheap"<<endl;
	int idx=1;
	int temp;
	while(1){
	//	cout << "idx : "<<idx<<", i = "<<i<<endl;
		if (idx<=(i-1) && (i-1)/2<idx) break;
		else if(idx==i/2 && i%2==0){
			break;
		}else if(idx==i/2 && i%2==1){
			temp=i-1;
		}else temp = arr[idx*2] < arr[idx*2+1] ? idx*2+1 : idx*2;
		if(arr[idx]>arr[temp]) break;
		else{
			ex(arr, idx, temp);
		}	
		idx=temp;
	}
	return;
	
}

int main(void) {
	int n;
	cin >> n;
	int* arr = new int[n+1];
	for(int i=1; i<=n; i++){
		cin >> arr[i];
		mheap(arr, i);
	}
/*	cout << "max heap"<<endl;
	
	for(int i=1; i<=n; i++){
		cout << arr[i] << '\n';
	}
*/	for(int i=n; i>1; i--){
		sheap(arr, i);
	}
	//quick(arr, arr+n-1);
	for(int i=1; i<=n; i++){
		cout << arr[i] << '\n';
	}
	
}

