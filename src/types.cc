#include "types.h"

#include <cmath>

vec3::vec3() {
	x = y = z = 0;
}

vec3::vec3(number x, number y, number z) 
	: x(x), y(y), z(z)
{
}

vec3::vec3(number value_for_all) {
	x = y = z = value_for_all;
}

number vec3::mag() const {
	return sqrt(x * x + y * y + z * z);
}

vec3 vec3::operator+(const vec3& v) const {
	return vec3(x + v.x, y + v.y, z + v.z);
}

vec3 vec3::operator-(const vec3& v) const {
	return vec3(x - v.x, y - v.y, z - v.z);
}

vec3 vec3::operator*(const vec3& v) const {
	return vec3(x * v.x, y * v.y, z * v.z);
}

vec3 vec3::operator/(const vec3& v) const {
	return vec3(x / v.x, y / v.y, z / v.z);
}

vec3 vec3::operator+(number v) const {
	return vec3(x + v, y + v, z + v);
}

vec3 vec3::operator-(number v) const {
	return vec3(x - v, y - v, z - v);
}

vec3 vec3::operator*(number v) const {
	return vec3(x * v, y * v, z * v);
}

vec3 vec3::operator/(number v) const {
	return vec3(x / v, y / v, z / v);
}

vec3& vec3::operator+=(const vec3& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

vec3& vec3::operator-=(const vec3& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

vec3& vec3::operator*=(const vec3& v) {
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

vec3& vec3::operator/=(const vec3& v) {
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}

vec3& vec3::operator+=(number v) {
	x += x;
	y += y;
	z += z;
	return *this;
}

vec3& vec3::operator-=(number v) {
	x -= x;
	y -= y;
	z -= z;
	return *this;
}

vec3& vec3::operator*=(number v) {
	x *= x;
	y *= y;
	z *= z;
	return *this;
}

vec3& vec3::operator/=(number v) {
	x /= x;
	y /= y;
	z /= z;
	return *this;
}

vec3 vec3::operator*(const matrix& m) const {
	return vec3(
		m[0] * x + m[1] * y + m[2] * z,
		m[3] * x + m[4] * y + m[5] * z,
		m[6] * x + m[7] * y + m[8] * z
	);
}