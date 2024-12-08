#include <iostream>
#include <set>
#include <numeric>

class Fraction {
	int numerator;
	int denominator;
	void normalize(){
		int gcd = std::gcd(numerator, denominator);

		numerator /= gcd;
		denominator /= gcd;
	}

public:
	Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
		normalize();
	}

	int getNumerator() const {
		return this->numerator;
	}

	int getDenominator() const {
		return this->denominator;
	}

	bool operator<(const Fraction& other) const {
		return this->numerator * other.denominator < other.numerator * this->denominator;
	}
	bool operator==(const Fraction& other) const {
		return this->getNumerator() == other.getNumerator() && this->getDenominator() == other.getDenominator();
	}
	Fraction operator+(const Fraction& other) const {
		Fraction result(this->getNumerator() + other.getDenominator(), this->getDenominator() + other.getDenominator());
		return result;
	}
	friend std::istream& operator>>(std::istream& in, Fraction& f);
	// Pre-increment
	Fraction& operator++(){
		this->numerator += this->denominator;
		return *this;
	}
	// Post-increment
	Fraction operator++(int){
		Fraction temp = *this;

		this->numerator += this->denominator;
		return temp;
	}
};

std::ostream& operator<<(std::ostream& out, const Fraction& f){
	return out << f.getNumerator() << '/' << f.getDenominator();
}

std::istream& operator>>(std::istream& in, Fraction& f){
	int x, y;
	in >> x >> y;

	if (y != 0) { f.numerator = x; f.denominator = y; }
	f.normalize();
	return in;
}