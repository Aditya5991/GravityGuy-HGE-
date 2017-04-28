#pragma once

#include "Math.h"

class Force
{
private:
	double magnitude;
	double forceX;
	double forceY;
	double angle;

public:
	Force(void);

	double toRadians(double);
	void reset();
	void update();
	void invertX();
	void invertY();
	double getMagnitude();
	double getAngle();
	double getForceAlongX();
	double getForceAlongY();
	void setMagnitude(double);
	void setAngle(double);

	~Force(void);
};

