#include "vec2.h"
#include <iostream>
#include <cmath>
using namespace std;

//Constructors
vec2::vec2() : x(0), y(0){}
vec2::vec2(float v) : x(v), y(v){}
vec2::vec2(float x, float y) : x(x), y(y) {}

//Addition
vec2& vec2::operator+=(const vec2& b) {
	x += b.x; y += b.y;
	return *this;
}
vec2 operator+(vec2 a, const vec2& b) {
	a += b;
	return a;
}

//Subtraction
vec2& vec2::operator-=(const vec2& b) {
	x -= b.x; y -= b.y;
	return *this;
}
vec2 operator-(vec2 a, const vec2& b) {
	a -= b;
	return a;
}

//Multiplication
vec2& vec2::operator*=(const float b) {
	x *= b; y *= b;
	return *this;
}
vec2 operator*(vec2 a, const float b) {
	a *= b;
	return a;
}
vec2 operator*(const float b, vec2 a) {
	a *= b;
	return a;
}

//Division
vec2& vec2::operator/=(const float b) {
	x /= b; y /= b;
	return *this;
}
vec2 operator/(vec2 a, const float b) {
	a /= b;
	return a;
}

//Dot product
float dot(const vec2& a, const vec2& b) {
	return a.x * b.x + a.y * b.y;
}

//Normalize the vector
vec2 normalize(const vec2& v) {
	return v / length(v);
}

//Length
float length(const vec2& v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

//Negation
vec2 vec2::operator-() { return vec2(-x, -y); }

//iostream handling
ostream& operator<<(ostream &out, const vec2 &v) {
	out << "(" << v.x << ", " << v.y << ")";
	return out;
}
