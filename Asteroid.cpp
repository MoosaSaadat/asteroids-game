/*
 * Asteroid.cpp
 *
 *  Created on: May 5, 2018
 *      Author: i170037
 */

#include "Asteroid.h"

Asteroid::Asteroid(float x, float y, int s, int r, bool check, int death)
: Shape (x, y, r)
{
	sides = s;
	isSimple = check;
	angle = GetRandInRange(0, 360);
	circumX = x + r* cos(Deg2Rad(angle));
	circumY = y + r* sin(Deg2Rad(angle));
	incX = GetRandInRange(-3, 3);
	incY = GetRandInRange(-3, 3);
	deathCount = death;
}

void Asteroid::Draw()
{
	if (getIsAlive() == true)
	{
		int radius = getRadius(); // sample radius
		int rndpoint = sides;// GetRandInRange(0, 9);
		int npoints = MAX(4, rndpoint);
		int dtheta = 360 / npoints;
		// using the formula rcostheta and rsin theta;
		float theta = angle; //MIN(90, dtheta); // GetRandInRange(0, dtheta);
	//	circumX = getXCor() + radius * cos(Deg2Rad(theta));
	//	circumY = getYCor() + radius * sin(Deg2Rad(theta));
		int sx = circumX;
		int sy = circumY;
		int x1 = sx;
		int y1 = sy;
		int stheta = dtheta + angle;
		for (int i = 0; i < npoints - 1; ++i) {
			theta = stheta + dtheta/npoints; // GetRandInRange(stheta, stheta + dtheta);
			int x2 = getXCor() + radius * cos(Deg2Rad(theta)),
				y2 = getYCor() + radius * sin(Deg2Rad(theta));
			DrawLine(x1, y1, x2, y2, 1, colors[WHITE]);
			x1 = x2;
			y1 = y2;
			stheta += dtheta;
		}
		DrawLine(x1, y1, sx, sy, 1, colors[WHITE]);
	}
	else
	{
		setXCor(-100);
		setYCor(-100);
		setRadius(0);
	}
}

void Asteroid::Rotate(int angle) {
	float x2 = circumX;
	float y2 = circumY;
	float newX2 = x2*cos(Deg2Rad(angle))
				- y2*sin(Deg2Rad(angle))
				+ getXCor()*(1 - cos(Deg2Rad(angle)))
				+ getYCor()*sin(Deg2Rad(angle));
	float newY2 = x2*sin(Deg2Rad(angle))
				+ y2*cos(Deg2Rad(angle))
				+ (1 - cos(Deg2Rad(angle)))*getYCor()
				- sin(Deg2Rad(angle))*getXCor();
	circumX = newX2;
	circumY = newY2;
	this->angle += angle;
}

void Asteroid::Move() {
	if (getIsAlive() == true)
	{
		int radius = getRadius();
		if (isSimple == false && Board::secCount %30 == 0)
		{
			incX = GetRandInRange(-2, 2);
			incY = GetRandInRange(-2, 2);
			if (incX == 0 && incY == 0)
			{
				incX = GetRandInRange(-3, 3);
				incY = GetRandInRange(-3, 3);
			}
		}

		setXCor(getXCor() + incX);
		setYCor(getYCor() + incY);
		circumX = getXCor() + radius* cos(Deg2Rad(angle));
		circumY = getYCor() + radius* sin(Deg2Rad(angle));

		//Checks to get it back in Board
		if (getXCor() - radius >= 1020 && incX > 0)
		{
			setXCor(-(2 * radius));
			circumX = getXCor() + radius* cos(Deg2Rad(angle));
			circumY = getYCor() + radius* sin(Deg2Rad(angle));
		}
		if (getXCor() + radius <= 0 && incX < 0)
		{
			setXCor(1024 + (2*radius));
			circumX = getXCor() + radius* cos(Deg2Rad(angle));
			circumY = getYCor() + radius* sin(Deg2Rad(angle));
		}
		if (getYCor() + radius <= 0 && incY < 0)
		{
			setYCor(840 + (2*radius));
			circumX = getXCor() + radius* cos(Deg2Rad(angle));
			circumY = getYCor() + radius* sin(Deg2Rad(angle));
		}
		if (getYCor() - radius >= 840 && incY > 0)
		{
			setYCor(0 - (2*radius));
			circumX = getXCor() + radius* cos(Deg2Rad(angle));
			circumY = getYCor() + radius* sin(Deg2Rad(angle));
		}
	}
}

bool Asteroid::getIsSimple() const {
	return isSimple;
}

void Asteroid::setIsSimple(bool isSimple) {
	this->isSimple = isSimple;
}

int Asteroid::getDeathCount() const {
	return deathCount;
}

void Asteroid::setDeathCount(int deathCount) {
	this->deathCount = deathCount;
}

Asteroid::~Asteroid() {
}

