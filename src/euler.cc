#include "euler.h"

void solveSemiImplicitEuler(
	number step_size, 
	const vec3 &initial_vel,
	const vec3 &acceleration,
	vec3 *vel, 
	vec3 *pos,
	int count
) {
	// set starting position
	pos[0] = 0.0;
	// set starting velocity
	vel[0] = initial_vel;

	for (int n = 0; n < (count - 1); ++n) {
		// calculate velocity
		vel[n + 1] = vel[n] - acceleration * step_size;
		// calculate displacement
		pos[n + 1] = pos[n] + vel[n + 1] * step_size;
	}
}
