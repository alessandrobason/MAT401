#include "runge_kutta.h"

void solveRungeKutta(
	number step_size, 
	number mass,
	number radius,
	number height,
	const vec3 &initial_vel,
	vec3 *vel,
	int count
) {
	// set starting velocity
	vel[0] = initial_vel;

	// moments of inertia for a cone
	const number r2 = radius * radius;
	const number h2 = height * height / 4.0;
	const number I1 = 3.0 / 20.0 * mass * (r2 + h2);
	const number I2 = 3.0 / 20.0 * mass * (r2 + h2);
	const number I3 = 3.0 / 10.0 * mass * (r2); // simplify 3/20 * 2 to 3/10

	// gamma values
	const number g1 = (I3 - I2) / I1;
	const number g2 = (I1 - I3) / I2;
	const number g3 = (I2 - I1) / I3;

	for (int n = 0; n < (count - 1); ++n) {
		const vec3 &p = vel[n];

		const vec3 k1 = {
			-step_size * g1 * p.y * p.z,
			-step_size * g2 * p.x * p.z,
			-step_size * g3 * p.x * p.y
		};

		const vec3 k2 = {
			-step_size * g1 * (p.y + (k1.y * 0.5)) * (p.z + (k1.z * 0.5)),
			-step_size * g2 * (p.x + (k1.x * 0.5)) * (p.z + (k1.z * 0.5)),
			-step_size * g3 * (p.x + (k1.x * 0.5)) * (p.y + (k1.y * 0.5))
		};

		const vec3 k3 = {
			-step_size * g1 * (p.y + (k2.y * 0.5)) * (p.z + (k2.z * 0.5)),
			-step_size * g2 * (p.x + (k2.x * 0.5)) * (p.z + (k2.z * 0.5)),
			-step_size * g3 * (p.x + (k2.x * 0.5)) * (p.y + (k2.y * 0.5))
		};

		const vec3 k4 = {
			-step_size * g1 * (p.y + k3.y) * (p.z + k3.z),
			-step_size * g2 * (p.x + k3.x) * (p.z + k3.z),
			-step_size * g3 * (p.x + k3.x) * (p.y + k3.y)
		};

		// calculate next array values
		vel[n + 1] = p + k1 / 6.0 + k2 / 3.0 + k3 / 3.0 + k4 / 6.0;
	}
}
