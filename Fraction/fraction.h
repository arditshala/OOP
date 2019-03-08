/*
    CH08-320142
    a6_p2.cpp(fraction.h)
    Ardit Shala
    a.shala@jacobs-university.de
*/
#ifndef FRACTION_H_
#define FRACTION_H_

using namespace std;

class Fraction {
private:                                                             // internal implementation is hidden
	int number;                                                      // numerator
	int denominator;
	                                                 // denominator

public:

	Fraction();                                                      //empty constructor
	Fraction(int, int = 1);             //constructor taking values for fractions and
                                                                        //integers. Denominator by default 1
    ~Fraction();
    int getnumber();
    int getdenominator(); //getters
    void setnumber(int number); //setter for number
    void setdenominator(int denominator); //setter for denominator
    friend ostream& operator<<(ostream& os, const Fraction &f){ //friend function
        os << f.number << "/" << f.denominator << endl;
        return os;
    };

    friend istream &operator>>( istream  &input, Fraction &f ) {
         int a, b, gcdAB;
         input >> a >> b;
         gcdAB = f.gcd(a, b);
         f.number = a / gcdAB;
         f.denominator = b / gcdAB;
         return input;
    }

    bool operator<(const Fraction &second) const
    {
        unsigned long long num1 = this->number * second.denominator;
        unsigned long long num2 = second.number * this->denominator;
        return num1 < num2;

    }

    bool operator>(const Fraction &second) const
    {
        unsigned long long num1 = this->number * second.denominator;
        unsigned long long num2 = second.number * this->denominator;
        return num1 > num2;
    }


    Fraction operator=(Fraction);
    Fraction operator*(Fraction); // method for multiplying
    Fraction operator/(Fraction); // method for dividing
    Fraction operator+(Fraction);
    Fraction operator-(Fraction);
    int gcd(int a, int b);              //calculates the gdc of a and b
	int lcm(int a, int b);

	void print();                            //prints it to the screen
};

#endif /* FRACTION_H_ */
