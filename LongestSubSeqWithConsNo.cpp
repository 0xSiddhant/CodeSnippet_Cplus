//Longest Subsequence With Consecutive Numbers
//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//Your algorithm should run in O(n) complexity.
//
// Input Format
// First line contains single integer n.
// Second line contains n integers Ai.

// Constraints
// 1<=n<=1e5 1<=Ai<=1e6

// Output Format
// Single line containing single integer

// Sample Input
// 6
// 100 4 200 1 3 2
// Sample Output
// 4

#include<bits/stdc++.h>
#include<map>
using namespace std;
int main(){
     int n;
     cin>>n;
     map<int,bool> s;
     int fans;
     int x;
     while(n--) {
          cin>>x;
          s.insert(make_pair(x,false));
     }
     for(auto i=s.begin();i!=s.end();i++) {
          int a = (*i).first;
          if((*i).second) { continue;}
          s[a] = true;
          int ans = 1;
          a = a + 1;
          while(s.find(a) != s.end()) {
               s[a] = true;
               ans ++;
               a = a + 1;
          }
          fans = max(ans,fans);
     }
     cout<<fans<<endl;
     
     return 0;
}
