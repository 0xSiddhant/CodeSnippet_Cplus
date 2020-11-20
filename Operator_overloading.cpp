#include <iostream>
using namespace std;
class Complex {
    private:
        int real;
        int img;
    public:
        Complex() {
            real = img = 0;
        }
        Complex(int r, int i) {
            real = r;
            img = i;
        }
        // Getter Setter
        void setReal(const int r) {
            real = r;
        }
        void setImg(const int i) {
            img = i;
        }
        int getReal() const {
            return real;
        }
        int getImg() const {
            return img;
        }

        void print() const {
            if(img > 0) cout<<real<< " + "<< img<<"i"<<endl;
            else cout<<real<<" - "<<-img<<"i"<<endl;
        }
        // Operator Overloading 
        void operator+(const Complex &c) {
            real += c.real;
            img += c.img;
        }
        void operator!() {
            img *= -1;
        }
        int operator[](const string s) {
          //  cout<<real<<" + "<<img<<"i "<<s<<endl;
          if (s == "real") return real;
          else return img;
        } 
};
// <<,>> Overloading
istream& operator>>(istream &i,Complex &c) {
    int r1,i1;
    i>>r1>>i1;
    c.setImg(i1);
    c.setReal(r1);
    return i;
}
ostream& operator<<(ostream &o, Complex c) {
    c.print();
    return o;
}
int main() {
    Complex c1(3,5);
    Complex c2;
    c2.setReal(2);
    c2.setImg(4);

    c1.print();
    c2.print();
    c1 + c2;
    !c2;
    c1.print();
    c2.print();
   // c1[" ya hooo"];
   cout<<c1["real"]<<endl;


   Complex c4;
   cin>>c4;
   cout<<c4;
}
