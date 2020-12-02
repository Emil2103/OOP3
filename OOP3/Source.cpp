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

class Storage {
protected:
	int count;
	int size;
	Object** object;
public:
	Storage(int size) {
		cout << "Storage(int size)" << endl;
		this->size = size;
		count = 0;
		object = new Object * [size];
		for (int i = 0; i < size; i++) {
			object[i] = NULL;
		}
	}
	void addObject(Object* t, int i) {
		if (i < size && object[i] == NULL) {
			object[i] = t;
			count++;
			cout << "void addObject(Object* t, int i)" << endl;
		}
		else
			cout << "Ошибка void addObject(Object* t, int i)" << endl;
	}
	Object* getObject(int i) {
		if (object[i] != NULL) {
			cout << "Object* getObject(int i)" << endl;
			return object[i];
		}
		else
			cout << "Ошибка Object* getObject(int i)" << endl;
	}
	void increaseSize(int newsize) {
		Object** NewObject = new Object * [size + newsize];
		for (int i = 0; i < size + newsize; i++) 
			NewObject[i] = NULL;
		
		for (int i = 0; i < size; i++) 
			if (object[i] != NULL)
				NewObject[i] = object[i];
		delete [] object;
		object = NewObject;
		size += newsize;
	}
	void deleteObject(int i) {
		if (object[i] != NULL) {
			object[i] = NULL;
			count--;
			cout << "void deleteObject(int i)" << endl;
		}
		else
			cout << "Ошибка void deleteObject(int i)" << endl;
	}
	int getsize() {
		return size;
	}
	~Storage() {
		cout << "~Storage()" << endl;
		delete[] object;
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	unsigned int start_time = clock();
	Storage p(100);
	for (int i = 0; i < 10; i++) {
		if(rand() % 2 == 0)
			if (rand() % 5 == 0) {
				Object* t = new Point;
				p.addObject(t, rand() % p.getsize());
			}
			else {
				Object* t = new Point3D;
				p.addObject(t, rand() % p.getsize());
			}
		else {
			if (rand() % 3 == 1)
				p.deleteObject(rand() % p.getsize());
			else
				p.getObject(rand() % p.getsize());
		}

	}
	unsigned int end_time = clock();
	unsigned int result_time = end_time - start_time;
	cout << "work time:" << result_time << "ms" << endl;
}

