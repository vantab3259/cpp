#include <ctime>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

class Base {
	public:
		virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

static Base* generate() {
	const int n = rand() % 3;

	if (n == 0)
		return new A;
	if (n == 1)
		return new B;
	return new C;
}

static void identify(Base* p) {
	char type = 'A';

	if (dynamic_cast<B*>(p))
		type = 'B';
	else if (dynamic_cast<C*>(p))
		type = 'C';

	std::cout << type << std::endl;
}

static void identify(Base& p) {
	Base q;

	try {
		q = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}

	try {
		q = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}

	std::cout << "C" << std::endl;
}

int main() {
	A a;
	B b;
	C c;

	std::srand(std::time(NULL));

	Base* r1 = generate();
	Base* r2 = generate();
	Base* r3 = generate();
	std::cout << "adress" <<std::endl;

	identify(&a);
	identify(&b);
	identify(&c);
	identify(r1);
	identify(r2);
	identify(r3);

	std::cout << std::endl;
	std::cout << "ref" <<std::endl;
	identify(a);
	identify(b);
	identify(c);
	identify(*r1);
	identify(*r2);
	identify(*r3);

	delete r1;
	delete r2;
	delete r3;
}