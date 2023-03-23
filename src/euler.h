#pragma once

#include "types.h"

template<size_t N>
struct Euler {
	vec3 vel[N]; // velocity
	vec3 pos[N]; // displacement
};

void solveSemiImplicitEuler(number step_size, const vec3& initial_vel, const vec3& acceleration, vec3 *vel, vec3 *pos, int count);

template<size_t N>
void solveSemiImplicitEuler(number step_size, const vec3& initial_vel, const vec3& acceleration, Euler<N> &values) {
	solveSemiImplicitEuler(step_size, initial_vel, acceleration, values.vel, values.pos, N);
}
