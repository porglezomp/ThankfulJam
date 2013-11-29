#ifndef TENSOR_vec2_INCLUDED
#define TENSOR_vec2_INCLUDED

#include <iostream>
using namespace std;

struct vec2 {
	float x, y;

	vec2();
	vec2(float);
	vec2(float, float);
	vec2& operator+=(const vec2&);
	vec2& operator-=(const vec2&);
	vec2& operator*=(const float);
	vec2& operator/=(const float);
	vec2 operator-();
	float radians();
	float degrees();
};

vec2 operator+(vec2, const vec2&);
vec2 operator-(vec2, const vec2&);
vec2 operator*(vec2, const float);
vec2 operator*(const float, vec2);
vec2 operator/(vec2, const float);
ostream& operator<<(ostream&, const vec2&);

//convert between angles and vectors
vec2 deg2vec(float);
vec2 rad2vec(float);
float vec2deg(vec2);
float vec2rad(vec2);

float dot(const vec2&, const vec2&);
float length(const vec2&);
vec2 normalize(const vec2&);

#endif