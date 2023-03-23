#pragma once

// use typedef "number" so we can easily swap between double and float for
// either accuracy or performance
// using number = float;
using number = double;

using matrix = number[9];

struct vec3 {
	vec3();
	vec3(number x, number y, number z);
	vec3(number value_for_all);

	number mag() const;

	vec3 operator+(const vec3& v) const;
	vec3 operator-(const vec3& v) const;
	vec3 operator*(const vec3& v) const;
	vec3 operator/(const vec3& v) const;
	vec3 operator+(number v) const;
	vec3 operator-(number v) const;
	vec3 operator*(number v) const;
	vec3 operator/(number v) const;

	vec3 &operator+=(const vec3 &v);
	vec3 &operator-=(const vec3 &v);
	vec3 &operator*=(const vec3 &v);
	vec3 &operator/=(const vec3 &v);
	vec3 &operator+=(number v);
	vec3 &operator-=(number v);
	vec3 &operator*=(number v);
	vec3 &operator/=(number v);

	vec3 operator*(const matrix &m) const;

	number x, y, z;
};
