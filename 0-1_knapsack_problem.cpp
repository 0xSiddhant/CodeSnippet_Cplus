#include <iostream>
#include<climits>
using namespace std;

int generate_profit(int N, int C,int *wt, int *prices) {
    if(N == 0 || C == 0) {
        return 0;
    }
    int inc,exc;
    inc = exc = INT_MIN;
    if( wt[N-1]<=C) {
        inc = prices[N-1] + generate_profit(N-1, C-wt[N-1], wt, prices);
    }
    exc = generate_profit(N -1, C, wt, prices);
    return max(inc,exc);
}

int main() {
    int N = 4;
    int C = 7;
    int weights[] = {1,2,3,5};
    int prices[] = {40,20,35,100};
    cout<< generate_profit(N, C, weights, prices) << endl;
    return 0;
}
