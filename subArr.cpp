#include <iostream>
#include <climits>
using namespace std;



int main() {
	int arr[] = {-4,1,3,-2,6,2,-1,-4,-7};
	int n = sizeof(arr)/sizeof(arr[0]);
	int maximunSum = INT_MIN;
	int currentSum = 0;
	// 1. Brute Force Approach O(n^3)
	for (int i = 0; i < n; ++i) {
		for(int j=i;j<n;j++) {
			currentSum = 0;
			for(int k=i;k<=j;k++) {
				currentSum += arr[k];
			}
			maximunSum = max(maximunSum, currentSum);
		}
	}
	cout<<maximunSum<<endl;

	//2. Cumulative Sum Approach O(N+N^2) => O(N^2)
	int csum[n] = {0};
	csum[0] = arr[0];
	for(int i=1;i<n;i++) {
		csum[i] = arr[i] + csum[i-1];
	}
	for (int i = 0; i < n; ++i) {
		for(int j=i;j<n;j++) {
			currentSum = csum[j] - csum[i];
			maximunSum = max(maximunSum, currentSum);
		}
	}
	cout<<maximunSum<<endl;

	//3. Kadane's Algorithm O(N)
	int cs = 0;
	maximunSum=0;
	for (int i = 0; i < n; ++i) {
		cs = cs + arr[i];
		if (cs<0) { cs = 0;}
		maximunSum = max(cs,maximunSum);
	}
	cout<<maximunSum<<endl;
}