#pragma once

#include "types.h"
#include "runge_kutta.h"
#include "euler.h"

template<size_t N>
struct GeneralMotion {
	vec3 pos[N]; // position
};

void solveGeneralMotion(number step_size, const vec3& initial_position, vec3 *pos, const vec3 *vel, const vec3 *rcm, int count);

template<size_t N>
void solveGeneralMotion(number step_size, const vec3& initial_position, GeneralMotion<N> &gm, const RungeKutta<N> &rk, const Euler<N> &e) {
	solveGeneralMotion(step_size, initial_position, gm.pos, rk.vel, e.pos, N);
}
