#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

class Rational {
public:

	Rational() {
		numerator = 0;
		denominator = 1;
	};
	Rational(int new_numerator, int new_denominator) {
		if (new_denominator == 0) {
			stringstream ss;
			ss << "denominator " << "is" << denominator;
			throw invalid_argument(ss.str());
		}
		numerator = new_numerator;
		denominator = new_denominator;
	}

	int Numerator() const {
		return numerator;
	}
	int Denominator() const {
		return denominator;
	}

private:
	int numerator;
	int denominator;

};

Rational operator / (const Rational& lhs, const Rational& rhs) {
	if (rhs.Numerator()==0) {
		stringstream ss;
		ss << "One of us Denominators = 0";
		throw domain_error(ss.str());
	}
	return(Rational(lhs.Numerator() * rhs.Denominator(), rhs.Numerator() * lhs.Denominator()));
}
	

int main() {
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument&) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error&) {
	}

	cout << "OK" << endl;
	return 0;
}