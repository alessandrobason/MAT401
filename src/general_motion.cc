#include "general_motion.h"

#include <cmath>

void solveGeneralMotion(
	number step_size,
	const vec3 &initial_position,
	vec3 *pos,
	const vec3 *vel,
	const vec3 *rcm,
	int count
) {
	pos[0] = initial_position;
	vec3 r1 = initial_position;

	for (int n = 0; n < (count - 1); ++n) {
		const vec3& v = vel[n];
		number v_mag = v.mag();
		vec3 vel_norm = v / v_mag;
		
		// alpha beta and gamma are the x, y, and z
		// values of the normalised velocity vector
		number a = vel_norm.x; // alpha
		number b = vel_norm.y; // beta
		number g = vel_norm.z; // gamma
	
		number theta = v_mag * step_size;

		// precalculate expensive cosine / sine
		number ct = cos(theta);
		number st = sin(theta);
		
		// calculate rotation matrix
		// (using x * x is faster than pow2(x) or pow(x, 2))
		matrix rotation = {
			a * a * (1 - ct) + ct,       a * b * (1 - ct) - g * st,   a * g * (1 - ct) + b * st,
			b * a * (1 - ct) + g * st,   b * b * (1 - ct) + ct,       b * g * (1 - ct) - a * st,
			g * a * (1 - ct) - b * st,   g * b * (1 - ct) + a * st,   g * g * (1 - ct) + ct,
		};

		// rotate point using matrix
		r1 = r1 * rotation;

		// calculate next position using formula r = rcm + r1
		pos[n + 1] = rcm[n + 1] + r1;
	}
}
