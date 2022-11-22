#include<iostream>
#include<string>
#include<sstream>
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
    friend ostream& operator<<(ostream&, const Rational&);
    // Rational substract(const Rational& anotherRational) const;
    // Rational multiply(const Rational& anotherRational) const;
    // Rational divide(const Rational& anotherRational) const;
    int compareTo(const Rational& anotherRational) const;
    double doubleValue() const;
    int intValue() const;
    string toString() const; 
    Rational operator++();
    Rational operator++(int);
    operator string(){
        return toString();
    }
    operator double(){
        return doubleValue();
    }
    operator int(){
        return intValue();
    }
private:
    int numerator;
    int denominator;
    static int gcd(int n, int d);
};

Rational::Rational(){
    numerator = 0;
    denominator = 1;
}

int Rational::gcd(int n, int d){
    if(d)
        return gcd(d, n % d);
    else
        return n;
}
Rational::Rational(int newNumerator = 0, int newDenominator = 1){
    numerator = newNumerator / gcd(myabs(newNumerator), myabs(newDenominator));
    denominator = newDenominator / gcd(myabs(newNumerator), myabs(newDenominator));
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
ostream& operator<<(ostream& out, const Rational& thisRational){
    thisRational.denominator > 1 ? out << thisRational.numerator << " / " << thisRational.denominator : out << thisRational.numerator;
    return out;
}

Rational Rational::operator++(int){     // r++
    Rational thatRational(numerator, denominator);
    Rational thisRational(numerator + denominator, denominator);
    *this = thisRational;
    return thatRational;
}
Rational Rational::operator++(){        // ++r
    Rational thisRational(numerator + denominator, denominator);
    *this = thisRational;
    return *this;
}
typedef Rational Integer;

#include<iostream>
int main()
{
    Rational r1(1, 2), r2(1, 3);
    cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
    cout << r1++ + r2 << endl;
    cout << r1 << endl;
    cout << (++r2) + r1 << endl;
    cout << r2 << endl;
    system("pause");
    return 0;
}