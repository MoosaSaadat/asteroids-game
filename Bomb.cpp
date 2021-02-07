/*
 * Bomb.cpp
 *
 *  Created on: May 7, 2018
 *      Author: i170037
 */

#include "Bomb.h"

Bomb::Bomb(float x, float y, float incX, float incY)
: Shape(x, y, 0)
{
	setRadius(3);
	fireRange = 0;
	this->incX = incX;
	this->incY = incY;
}

void Bomb::Draw() {
	if (getIsAlive() == true)
		DrawCircle(getXCor(), getYCor(), getRadius(), colors[YELLOW]);
	else
	{
		setXCor(-100);
		setYCor(-100);
		setRadius(0);
	}
}

void Bomb::Move() {
	if (getIsAlive() == true)
	{
		int radius = getRadius();

		setXCor(getXCor() + incX);
		setYCor(getYCor() + incY);

		//Checks to get it back in Board
		if (getXCor() - radius >= 1020 && incX > 0)
		{
			setXCor(-(2 * radius));
		}
		if (getXCor() + radius <= 0 && incX < 0)
		{
			setXCor(1024 + (2*radius));
		}
		if (getYCor() + radius <= 0 && incY < 0)
		{
			setYCor(840 + (2*radius));
		}
		if (getYCor() - radius >= 840 && incY > 0)
		{
			setYCor(0 - (2*radius));
		}
	}
}

float Bomb::getIncX() const {
	return incX;
}

void Bomb::setIncX(float incX) {
	this->incX = incX;
}

float Bomb::getIncY() const {
	return incY;
}

void Bomb::setIncY(float incY) {
	this->incY = incY;
}

Bomb::~Bomb() {
}

float Bomb::getFireRange() const {
	return fireRange;
}

void Bomb::setFireRange(float fireRange) {
	this->fireRange = fireRange;
}
