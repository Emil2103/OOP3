#include <iostream>
#include <locale.h>
#include <ctime>
using namespace std;

class Object {
public:
	Object() {}

	virtual ~Object() {
		cout << "~Object" << endl;
	}

	virtual void show(){}
	virtual void foo() {}
};

class Point : public Object {
protected:
	int x, y;

public:
	Point() {
		cout << "Point()" << endl;
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		cout << "Point(int x, int y)" << endl;
		this->x = x;
		this->y = y;
	}
	Point(const Point& p) {
		cout << "Point(const Point& p)" << endl;
		x = p.x;
		y = p.y;
	}
	~Point() {
		cout << "~Point()" << endl;
	}
	void show() {
		cout << "Это точка с координатами (" << x << "," << y << ")" << endl;
	}
	void foo() {
		++x;
		++y;
	}
};

class Point3D : public Object {
protected:
	int x, y, z;
public:
	Point3D() {
		cout << "Point3D()" << endl;
		x = 0;
		y = 0;
		z = 0;
	}
	Point3D(int x, int y, int z) {
		cout << "Point3D(int x, int y, int z)" << endl;
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Point3D(Point3D& p) {
		cout << "Point3D(Point3D& p)" << endl;
		x = p.x;
		y = p.y;
		z = p.z;
	}
	~Point3D() {
		cout << "~Point3D()" << endl;
	}
	void show() {
		cout << "Это точка с координатами (" << x << "," << y  << "," << z << ")" << endl;
	}
	void foo() {
		++x;
		++y;
		++z;
	}
	void set3D(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};


