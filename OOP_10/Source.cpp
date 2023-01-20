#include <iostream>
#include <vector>
#include <string>

// Агрегация, композиция, наследование

// Наследование
class A {
public:
	void public_method() {}

protected:
	void protected_method() {}

private:
	void private_method() {}

};

// public, private, protected
class B : public A {
private:
	void func() {
		void protected_method();
	}
};

// Ассоциация
// Агрегация и Композиция

// Композиция - один класс не существует без другого, например, автомобиль не существует без двигателя

class Engine {
public:
	Engine(int p) : _power(p){
		std::cout << "Parametrized constructor was called (Engine)" << '\n';
	}
	Engine(Engine& other) : _power(other._power) {
		std::cout << "Copy constructor was called (Engine)" << '\n';
	}
	int getPower() {
		return _power;
	}
private:
	int _power;
};

class Car {
public:
	// композиция
	Car (int enginePower) : _engine(enginePower){}
	// агрегация
	Car(Engine& e) :_engine(e) {}

	int getPower() {
		return _engine.getPower();
	}
private:
	std::string _model = "Porshe";
	Engine _engine;	// Car ассоциирован с Engine
};

// Виртуальное наследование
/*class Vehicle {
public:
	Vehicle(int speed) : _speed(speed) {
		std::cout << "Vehicle()" << '\n';
	}
	int getSpeed() {
		return _speed;
	}

private:
	int _speed;
};

enum Transmition {
	Auto,	// автоматическая
	Manual	// ручная
};

class Automobile : public virtual Vehicle {
public:
	Automobile(int speed, Transmition transmition) : Vehicle(speed), _transmition(transmition){}
private:
	Transmition _transmition;
};

enum OriginCountry {
	Russia,
	UAE
};

class Airplane : public virtual Vehicle {
public:
	Airplane(int speed, OriginCountry country) : Vehicle(speed), _originCountry(country){}
private:
	OriginCountry _originCountry;
};

enum FlyingCarMode {
	Drive,
	Fly
};

class FlyingCar : public Automobile, Airplane {
public:
	FlyingCar(int speed, OriginCountry country, Transmition transmition, FlyingCarMode initialMode): Automobile(speed, transmition), Airplane(speed, country), _mode(initialMode), Vehicle(speed) {}
private:
	FlyingCarMode _mode;
};

void race(Vehicle* v1, Vehicle* v2) {

}
*/


// Виртуальные функции
class C {
public:
	// static dispatch / early binding (статический вызов, ранняя привязка)
	void foo() {
		std::cout << "С:foo()" << '\n';
	}
};

/*class D : public C {
public :
	void foo() {
		std::cout << "D:foo()" << '\n';
	}
};*/

class D { // vptr 
public:
	// vtable
	virtual void bar() {
		std::cout << "D:bar()" << '\n';
	}
	virtual void qux() {
		std::cout << "D:qux()" << '\n';
	}
};

class E : public D{ // vptr - указывает на наследника, у которого есть функции
	// vptr
	void bar() override {
		std::cout << "E::bar()" << '\n';
	}
};



int main() {
	/*A a;
	a.public_method();
	B b;
	b.public_method();

	Car c(200);

	Engine e(333);
	Car c2(e);

	std::cout << c.getPower() << '\n';
	std::cout << c2.getPower() << '\n';*/

	// Виртуальное наследование

	/*FlyingCar fc(800, OriginCountry::Russia, Transmition::Auto, FlyingCarMode::Fly);
	std::cout << fc.getSpeed() << '\n';

	Vehicle* fc2 = new FlyingCar(800, OriginCountry::Russia, Transmition::Auto, FlyingCarMode::Fly);

	delete fc2;*/

	// Виртуальные функции
	/*D* d = new E;
	d->bar();*/
	


}