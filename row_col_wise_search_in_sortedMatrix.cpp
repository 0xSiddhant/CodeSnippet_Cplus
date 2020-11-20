#include<iostream>
using namespace std;

void findValue(int arr[][4], int value, int n, int m) {
	int i = 0, j = m-1;
	bool flag = true;
	while(i < n && j >= 0) {
		if(value < arr[i][j]) {
			j--;
		} else if(value > arr[i][j]) {
			i++;
		} else {
			cout<<value<<" found at index "<<i<<", "<<j<<endl;
			flag = false;
			break;
		}
	}
	if (flag) {
		cout<<"Element Not Found"<<endl;
	}
}

int main() {

	int arr[][4] = {{1,4,8,10},{2,5,9,15},{6,16,18,20},{11,17,19,23}};
	findValue(arr,3,4,4);
	return 0;
}