#include <string>
#include <sstream>
#include <iostream>

using namespace std;


class Complex {
    float real_, imaginary_;
  public:
    Complex (float, float);
    Complex operator= (const Complex& rhs);
    Complex operator+ (const Complex& rhs) const;
    Complex operator- (const Complex& rhs) const;
    Complex operator* (const Complex& rhs) const;
    string toString() const;
};

Complex::Complex (float r, float i){
  real_ = r;
  imaginary_ = i;
}

Complex Complex::operator= (const Complex& rhs){
    real_ = rhs.real_;
    imaginary_ = rhs.imaginary_;
    return *this;
}

Complex Complex::operator+ (const Complex& rhs) const{
    Complex result = *this;
    result.real_ += rhs.real_;
    result.imaginary_ += rhs.imaginary_;
    return result;
}

Complex Complex::operator- (const Complex& rhs) const{
    Complex result = *this;
    result.real_ -= rhs.real_;
    result.imaginary_ -= rhs.imaginary_;
    return result;
}

Complex Complex::operator* (const Complex& rhs) const{
    Complex result = *this; // this-> == *this == (*this)
    result.real_ = real_ * rhs.real_ - imaginary_ * rhs.imaginary_;
    //cout << result.real_ << "R " << result.imaginary_ << "I "<< "|" << rhs.real_ << "R " << rhs.imaginary_ << "I\n";
    result.imaginary_ = (real_ * rhs.imaginary_) + (rhs.real_ * imaginary_);
    //cout << result.real_ << "R " << result.imaginary_ << "I "<< "|" << rhs.real_ << "R " << rhs.imaginary_ << "I\n";
    return result;
}

string Complex::toString() const {
  stringstream ss;
  if (imaginary_ > 0){
    ss << real_ << " + " << imaginary_ << "i";
  }
  else {
    ss << real_ << " " << imaginary_ << "i";
  }
  return ss.str();
}

int main () {
  Complex a(5, 6);
  Complex b(1, 4);

  Complex sum = a + b;
  Complex dif = a - b;
  Complex pro = a * b;

  cout << "sum: " << sum.toString() << "\n";
  cout << "difference: " << dif.toString() << "\n";
  cout << "product: " << pro.toString() << "\n";

  return 0;
}
