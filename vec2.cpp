#include "vec2.h"
#include <iostream>
#include <cmath>

#define PI	3.141592654

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

//Angle-vector conversion
float vec2::radians() {
	vec2 v = normalize(*this);
	float angle = acos(v.y);
	if (v.y < 0) angle += PI/2;
	return angle;
}
float vec2::degrees() {
	vec2 v = normalize(*this);
	float angle = acos(v.y);
	if (v.y < 0) angle += PI/2;
	return angle/PI*180;
}
vec2 deg2vec(float deg) {
	float rad = deg / 180 * PI;
	return vec2(cos(rad), sin(rad));
}
vec2 rad2vec(float rad) {
	return vec2(cos(rad), sin(rad));
}
float vec2deg(vec2 v) {
	return v.degrees();
}
float vec2rad(vec2 v) {
	return v.radians();
}