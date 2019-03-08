/*
    CH08-320142
    a3_p6.cpp
    Ardit Shala
    a.shala@jacobs-university.de
*/

class Complex {
private:
    float real;  // real part
	float imag;  // imaginary part
public:


	Complex();                 // empty constructor
	Complex(float, float = 0); // constructor taking values for real and
    ~Complex();

    void setReal(float newreal); //setters
    void setImag(float newimag);

    float getReal(); //getters
    float getImag();


    void conjugate(); //conjugate
    Complex add(Complex aa);
	void print();
	Complex mul(Complex ab);
	Complex diff(Complex ac);

};
