#pragma once
#include <iostream>

/*
	Chapter 13 Review Questions
1. What does a derived class inherit from a base class?

	All public/protected data members and methods except constructor/destructor,
	and assignment operator.

2. What doesn't a derived class inherit from a base class?

	Constructors/destructors, assignment operators, friend functions

3. Suppose the return type for the baseDMA::operator=() function were defined as void
	instead of baseDMA &. What effect, if any, would that have? What if the return type were
	baseDMA instread of baseDMA &?

	It would eliminate the chaining of assignment operators (eg. a = b = c;)  If the return type were
	baseDMA instead of baseDMA &, the function would incur time and memory penaties due to the 
	invokation of the copy constructor and the creation of a temporary object within the function.

4. In what order are class constructors and class destructors called when a derived-class
	object is created and deleted?

	created: base class constructor then derived class
	deleted: derived class destructor, then base class

5. If a derived class doesn't add any data members to the base class, does the derived class
	require constructors?

	Yes; it can be empty, but it must exist.

6. Suppose a base class and a derived class both define a method with the same name and a
	derived-class object invoked the method. What method is called?

	If the method is not virtual, and the derived class object has been upcasted to a baseClass type, 
	then the base class method is called. If the scope resolution operator is used (eg. baseClass::method()),
	then the base class method is called. Otherwise, the derived class method is called.

7. When should a derived class define an assignment operator?

	If the derived class introduced any new data elements that require dynamic memory allocation.
	*From the book: "More generally, the derived class shoudl define an assignment operator if the default
					assignment is incorrect for derived-class members."

8. Can you assign the address of an object of a derived class to a pointer to the base class?
	Can you assign the address of a n object of a base class to a pointer to the derived class?

	Yes, No (except by explicit type-cast)

9. Can you assign an object of a derived class to an object of the base class? Can you assign
	an object of a base class to an object of the derived class?

	Yes, No, unless there is an overriden conversion operator or type cast operator.

10. Suppose you define a function that takes a reference to a base-class object as an argu-
	ment. Why can this function also use a derived-class object as an argument?

	Because C++ allows base class reference to refer to derivations of that class.

11. Suppose you define a function that takes a base-class object as an argument (that is, the
	function passes a base-class object by value). Why can this function also use a derived-
	class object as an argument?

	Passing by value invokes the copy constructor of the formal parameter type. If that type
	is of the base class, the copy constructor would require a reference to a base class object.
	C++ allows a base class reference to refer to a derived class object. The resulting object
	would contain only the base class members of the passed object.

12. Why is it usually better to pass objects by reference than by value?

	Passing by value incurs time and space penalties. Passing by reference allows the 
	passed object to keep all of its overriden virtual functions. 

13. Suppose Corporation is a base class and PublicCorporation is a derived class. Also
	suppose that each class defines a head() member function, that ph is a pointer to the
	Corporation type, and that ph is assigned the address of a PublicCorporation object.
	How is ph->head() interprated if the bse class defines head() as a
		a. Regular nonvirtual method

			Corporation::head()

		b. Virtual method

			PublicCorporation::head()

14. What's wrong, if anything, with the following code?

class Kitchen
{
private:
	double kit_sq_ft;
public:
	Kitchen() { kit_sq_ft = 0.0; }
	virtual double area() const { return kit_sq_ft * kit_sq_ft; }
};
class House : public Kitchen
{
private:
	double all_sq_ft;
public:
	House() {all_sq_ft += kit_sq_ft;}
	double area(const char *s) const { cout << s; return all_sq_ft; }
};
	*from the book: the House class does not conform to the is-a model for inheritance.
	House::area() hides the Kitchen version of area, because the two methods have different
	signatures.
*/

// base class
class Cd {  // represents a CD disk
private:
	char * performers;
	char * label;
	int selections;     // number of selections
	double playtime;    // playing time in minutes
protected:
	enum {LEN = 50};
public:
	Cd(const char * s1, const char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;  // reports all CD data
	Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
private:
	char * primaryWork;
public:
	Classic();
	Classic(const char * pw, const char * perf, const char * lab, int sel = 0, double pt = 0.0);
	Classic(const Classic & c);
	~Classic();
	void Report() const;
	Classic & operator=(const Classic & c);
};

class Port
{
private:
	char * brand;
	char style[20];  // i.e., tawny, ruby, vintage
	int bottles;
public:
	Port(const char * br = "none", const char * st = "none", int b = 0);
	Port(const Port & p);                    // copy constructor
	virtual ~Port() { delete[] brand; }
	Port & operator=(const Port & p);
	Port & operator+=(int b);                // adds b to bottles
	Port & operator-=(int b);                // subtracts b from bottles, if available
	int BottleCount() const { return bottles; }
	virtual void Show() const;
	friend std::ostream & operator<<(std::ostream & os, const Port & p);
};

class VintagePort : public Port // style necessarily = "vintage"
{
private:
	char * nickname;            // i.e., "The Noble" or "Old Velvet", etc.
	int year;
public:
	VintagePort();
	VintagePort(const char * br, int b, const char * nn, int y);
	VintagePort(const VintagePort & vp);
	~VintagePort() { delete[] nickname; }
	VintagePort & operator=(const VintagePort & vp);
	void Show() const;
	friend ostream & operator<<(ostream & os, const VintagePort & vp);
};
void ex13_1();
void ex13_2();
void ex13_3();
void ex13_4();