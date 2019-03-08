#include <iostream>

class Vector {
private:
    double size;
    double *ptrdb;
    public:
        Vector(); //default constructor
        Vector(double, double*); // constructor with two parameters
        Vector(const Vector& n); // copy constructor
        ~Vector(); //destructor


    //setters
    void setSize(const double newsize);
    void setPtrdb(const double &newptrdb);

    //getters
    double getSize();
    double getPtrdb();

    //services
    void print();
    double norm() const;
    double mult(const Vector &v) const;
    Vector add(const Vector &v) const;
    Vector diff(const Vector &v) const;

};


