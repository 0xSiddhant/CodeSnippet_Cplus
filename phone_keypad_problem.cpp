#include <iostream>
using namespace std;

char keypads[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void generate_name(char *in, char *out, int i, int j) {
    if (in[i] == '\0') {
        out[j] = '\0';
        cout<< out << endl;
        return;
    }
    int digit = in[i] - '0';
    if (digit == 0 || digit == 1) {
        generate_name(in, out, i + 1, j);
    }
    for(int k = 0; keypads[digit][k] != '\0'; k++) {
        out[j] = keypads[digit][k];
        generate_name(in, out, i+1, j+1);
    }
    return;
}

int main() {
    char arr[20];
    char output[1000];
    cin>>arr;
    generate_name(arr, output, 0, 0);
    return 0;
}
