#include <iostream>
using namespace std;

void generate_bracket(char *out, int n, int idx,int open, int close) {
    //base case
    if(idx == 2*n) {
        out[idx] = '\0';
        cout<< out << endl;
        return;
    }
    //recursive case
    if(open < n) {
        out[idx] = '(';
        generate_bracket(out, n, idx + 1, open + 1, close);
    }
    if(close< open) {
        out[idx] = ')';
        generate_bracket(out, n, idx + 1, open, close + 1);
    }
    return;
}
int main() {
    int n;
    cin>>n;
    char output[2*n];
    generate_bracket(output, n, 0, 0, 0);
    return 0;
}
