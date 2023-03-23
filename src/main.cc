#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "runge_kutta.h"
#include "general_motion.h"
#include "euler.h"

int main() {
	constexpr number time_max = 20.0;
	constexpr int count = 2000;
	constexpr number step_size = time_max / count;
	number time = 0.0;

	// - Task 1
	// For a cone of mass M = 10 kg, dimensions r = 1m and h = 4m, and with initial
	// conditions w0 = (3, 1, 2) rad/s, numerically solve Euler’s equations using 
	// your own bespoke fourth-order Runge-Kutta algorithm. Solve Euler’s equations 
	// for the case when there are no external torques acting on the cone, whose 
	// rotational motion takes place about an axis passing through its centre of 
	// mass and for a time period of t in the range [0, 20]s

	const number mass = 10;
	const number radius = 1;
	const number height = 4;
	vec3 initial_vel = vec3(3, 1, 2);

	// Solve for angular velocity
	RungeKutta<count> rk{};
	solveRungeKutta(step_size, mass, radius, height, initial_vel, rk);

	// - Task 2
	// From your solutions for Task 1, produce plots of wx(t), wy(t) and wz(t) as a 
	// function time, t, showing the periodic evolution of the angular speed for 
	// the toroidal system
	
	// (matplotlib will be used for plotting,
	//  so for now just print it to a csv file)
	FILE *task_2 = fopen("task_2.csv", "wb");

	fputs("time,x,y,z\n", task_2);
	
	for (const vec3 &v : rk.vel) {
		fprintf(task_2, "%g,%g,%g,%g\n", time, v.x, v.y, v.z);
		time += step_size;
	}

	fclose(task_2);

	// - Task 3
	// If the centre of mass of the cone is given an initial velocity of(0, 0, 200) 
	// m/s at t = 0s and its subsequent motion is governed by the force of gravity
	// such that its acceleration is a = (0, 0, -9.8)m/s, determine its resulting
	// trajectory for the time period t in the range [0, 20]s. To obtain the
	// trajectory solve Newton’s second law of motion using the semi - implicit 
	// Euler method

	initial_vel = vec3(0, 0, 200);
	const vec3 acceleration = vec3(0, 0, 9.8);

	Euler<count> euler{};
	solveSemiImplicitEuler(step_size, initial_vel, acceleration, euler);

	// - Task 4
	// From your solutions for Task 3, produce plots of the vertical velocity and
	// vertical displacement as a function of time t

	FILE *task_4 = fopen("task_4.csv", "wb");
	time = 0.0;

	fputs("time,vx,vy,vz,px,py,pz\n", task_4);

	for (int i = 0; i < count; ++i) {
		const vec3& v = euler.vel[i];
		const vec3& p = euler.pos[i];
		fprintf(task_4, "%g,%g,%g,%g,%g,%g,%g\n", time, v.x, v.y, v.z, p.x, p.y, p.z);
		time += step_size;
	}

	fclose(task_4);

	// - Task 5	
	// The complete motion of the cone will be a combination of its free rotation 
	// and its translational motion. Using the w solution (Task 1) and the cone 
	// trajectory (Task 3) obtained from your simulations, extend your code to 
	// determine the trajectory of the point P that has initial position (0, 3r/4, 0) 
	// as a function of time. From your simulation, produce a 2D projection on the 
	// xy-plane of the position of P for all times t in the range [0, 20]s, such that 
	// your plot will show a 2D trace of P in time.

	const vec3 initial_pos = vec3(0, 3.0 / 4.0 * radius, 0);

	GeneralMotion<count> gm{};
	solveGeneralMotion(step_size, radius, initial_pos, gm, rk, euler);

	FILE *task_5 = fopen("task_5.csv", "wb");

	fputs("x,y\n", task_5);

	for (const vec3 &p : gm.pos) {
		fprintf(task_5, "%g,%g\n", p.x, p.y);
	}

	fclose(task_5);
}