#include <iostream>
using namespace std;

class Vector {
private:
	float x, y, z;
public:
	Vector(){}
	Vector(float x,float y,float z):x{x},y{y},z{z}{}

	Vector operator+(const Vector&v)const {

		return Vector{ x + v.x ,y + v.y, z + v.z };
	}
	Vector operator-(const Vector& v)const {
		return Vector{ x - v.x,y - v.y,z - v.z };
	}

	Vector operator-()const {
		return Vector{ -x,-y,-z };
	}

	Vector operator+()const {
		return Vector{ +x,+y,+z };
	}
	float operator*(const Vector& v)const {
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return dot;
	}


	Vector operator*(float n)const
	{
		return Vector(x * n, y * n, z * n);
	}


	Vector operator/(float n)const {
		return Vector(x / n, y / n, z / n);
	}

	Vector &operator++() {
		++x;
		++y;
		++z;
		return *this;
	}
	Vector& operator++(int) {
		Vector temp = *this;
		++x;
		++y;
		++z;
		return temp;
	}

	void printf() {
		cout << x << " " << y << " " << z << endl;
	}
};


int main() {
	Vector v0{ 0,1,2 };
	Vector v1{ 1,2,3 };

	//Vector v2 = v0 + v1;//이항연산자+
	Vector v2 = v0.operator+(v1);
	v2.printf();// 1 3 5

	Vector v8 = v0.operator-(v1);//이항 연산자 -
	v8.printf();//-1 -1 -1


	Vector v3 = -v1;//단항 연산자-
	v3.printf();//-1 -2 -3

	Vector v7 = +v1;//단항 연산자 +
	v7.printf();// 1 2 3


	float v4 = v0 * v1;//이항연산자*
	cout << v4 << endl;//8

	

	Vector v5 = v1 * 3.0f;
		v5.printf();//3 6 9

		Vector v6 = v1 / 3.0f;//이항연산자 / 
		v6.printf();//0.3333 0.6666 1


		Vector v9 = ++v1;//전위 연산자++
		v9.printf();//2 3 4

		Vector v10 = v1++;//후위 연산자++
		v10.printf();//2 3 4


		v1.printf();// 3 4 5 후위 연산자 확인용 출력

}