/*
    CH08-320142
    A4_P4.cpp(Creature.cpp)
    Ardit Shala
    a.shala@jacobs-university.de
*/
class Creature { // the "main" class creature
	public:
		Creature(); // constructor
		void run() const; // method

	protected:
		int distance; // property
};

class Wizard : public Creature { // derived class of creature
	public:
		Wizard(); // construct
		void hover() const;

	private:
		int distFactor; // property
};

class Creature1 : public Creature { //derived class of creature
    public:
        Creature1(); //constructer of creature1
        ~Creature1(); //destructor of creature1
        void body() const;
    private:
        int length; //property

};

class Creature2 : public Creature { //derived class of creature
    public:
        Creature2(); //constructor of creature2
        ~Creature2(); //destructor of creature 2
        void life() const; //method
    private:
        int year; //property of creature2
};
