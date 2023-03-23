#pragma once

#include "types.h"

template<size_t N>
struct RungeKutta {
	vec3 vel[N]; // angular velocity
};

void solveRungeKutta(number step_size, number mass, number radius, number height, const vec3& initial_vel, vec3 *pos, int count);

template<size_t N>
void solveRungeKutta(number step_size, number mass, number radius, number height, const vec3& initial_vel, RungeKutta<N> &values) {
	solveRungeKutta(step_size, mass, radius, height, initial_vel, values.vel, N);
}