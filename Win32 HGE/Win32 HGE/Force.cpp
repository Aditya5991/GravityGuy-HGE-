#include "precompiled.h"
#include "Force.h"

Force::Force(void){
	magnitude = 0;
	forceX = forceY = 0;
	angle = 0;
}

void Force::reset(){
	magnitude = angle = 0;
	forceX = forceY = 0;
}

void Force::update(){
	magnitude *= 0.97;
	forceX = magnitude*cos(angle);
	forceY = magnitude*sin(angle);
}

void Force::invertX(){ forceX *= -1; }
void Force::invertY(){ forceY *= -1; }

double Force::getMagnitude(){ return magnitude; }
double Force::getAngle(){ return angle; }
double Force::getForceAlongX(){ return forceX; }
double Force::getForceAlongY(){ return forceY; }

void Force::setMagnitude(double magnitude){ this->magnitude = magnitude; }
void Force::setAngle(double angle){ this->angle = angle; }

Force::~Force(void){
}
