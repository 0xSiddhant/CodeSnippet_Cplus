// In Coding blocks test Kartik bhaiya gave students an array of n non-negative integers a1, a2, …, an ,where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). The task is to find two lines, which together with x-axis forms a container, such that the container contains the most water.
// Note: You may not slant the container.

// Input Format
// First line contains integer n as size of array. Next n lines contains a single integer as elements of array.

// Constraints
// n>=2

// Output Format
// Output maximum water the container contains.

// Sample Input
// 9
// 1 8 6 2 5 4 8 3 7
// Sample Output
// 49

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int *arr = new int[n];
  int t;
  for(int i=0;i<n;i++) {
    cin>>t;
    arr[i] = t;
  }
  int area = 0;
  int left = 0;
  int right = n-1;
  
  while(left<right) {
    area = max(area, min(arr[left],arr[right])*(right-left));
    if( arr[left]<arr[right]) left++;
    else right--;
  }
  cout<<area<<endl;
  return 0;
}
