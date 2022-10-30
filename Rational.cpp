#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;

template<typename T>
T myabs(T a){
    return a > 0 ? a : -a;
}

class Rational
{
public:
    Rational();
    Rational(int, int);
    Rational add(const Rational&) const;
    Rational operator+(const Rational&) const;
    // Rational substract(const Rational& anotherRational) const;
    // Rational multiply(const Rational& anotherRational) const;
    // Rational divide(const Rational& anotherRational) const;
    int compareTo(const Rational& anotherRational) const;
    double doubleValue() const;
    int intValue() const;
    string toString() const; 
private:
    int numerator;
    int denominator;
    static int Common(int n, int d);
};

Rational::Rational(){
    numerator = 0;
    denominator = 1;
}

int Rational::Common(int n, int d){
    if(d)
        return Common(d, n % d);
    else
        return n;
}
Rational::Rational(int newNumerator, int newDenominator){
    numerator = newNumerator / Common(myabs(newNumerator), myabs(newDenominator));
    denominator = newDenominator / Common(myabs(newNumerator), myabs(newDenominator));
}
Rational Rational::add(const Rational& anotherRational) const{
    int n = numerator * anotherRational.denominator + anotherRational.numerator * denominator;
    int d = denominator * anotherRational.denominator;
    return Rational(n, d);
}
Rational Rational::operator+(const Rational& anotherRational) const{    
    return add(anotherRational);
}
string Rational::toString() const{
    stringstream ss;
    denominator > 1 ? ss << numerator << " / " << denominator : ss << numerator;
    return ss.str();
}
double Rational::doubleValue() const{
    return static_cast <double> (numerator) / denominator;
}
#include<iostream>
#include<string>
int main()
{
    Rational r1(11, 20), r2(12, 20);
    std::cout << (r1 + r2).toString() << endl;
    cout << (r1 + r2).doubleValue() << endl;
    system("pause");
    return 0;
}