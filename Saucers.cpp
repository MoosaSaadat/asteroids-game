/*
 * Saucers.cpp
 *
 *  Created on: May 5, 2018
 *      Author: i170037
 */

#include "Saucers.h"

Saucers::Saucers(float x, float y, float r, bool check)
: Shape(x, y, r)
{
	isLarge = check;
	if (isLarge == true)
	{
		setRadius(40);
	}
	else
	{
		setRadius(25);
	}
	incX = GetRandInRange(-3, 3);
	incY = GetRandInRange(-3, 3);
	timer = 0;
}

void Saucers::Draw() {
	if (getIsAlive() == true)
	{
		int radius = getRadius();
		//Base
		DrawLine(getXCor() -radius, getYCor(), getXCor() +radius, getYCor(), 2, colors[WHITE]);
		//Top
		DrawLine(getXCor() - (radius-(3*float(radius)/5)), getYCor() + (radius-(3*float(radius)/5)), getXCor() -radius, getYCor(), 1, colors[WHITE]);
		DrawLine(getXCor() + (radius-(3*float(radius)/5)), getYCor() + (radius-(3*float(radius)/5)), getXCor() +radius, getYCor(), 1, colors[WHITE]);
		DrawLine(getXCor() + (radius-(3*float(radius)/5)), getYCor() + (radius-(3*float(radius)/5)), getXCor() - (radius-(3*float(radius)/5)), getYCor() + (radius-(3*float(radius)/5)), 1, colors[WHITE]);
		//Bottom
		DrawLine(getXCor() - (radius-(3*float(radius)/5)), getYCor() - (radius-(3*float(radius)/5)), getXCor() -radius, getYCor(), 1, colors[WHITE]);
		DrawLine(getXCor() + (radius-(3*float(radius)/5)), getYCor() - (radius-(3*float(radius)/5)), getXCor() +radius, getYCor(), 1, colors[WHITE]);
		DrawLine(getXCor() + (radius-(3*float(radius)/5)), getYCor() - (radius-(3*float(radius)/5)), getXCor() - (radius-(3*float(radius)/5)), getYCor() - (radius-(3*float(radius)/5)), 1, colors[WHITE]);
		//Top head
		DrawLine(getXCor() + (radius-(3*float(radius)/5)), getYCor() + (radius-(3*float(radius)/5)), getXCor() + (float(radius)/5), getYCor() + (7*float(radius)/10), 1, colors[WHITE]);
		DrawLine(getXCor() - (radius-(3*float(radius)/5)), getYCor() + (radius-(3*float(radius)/5)), getXCor() - (float(radius)/5), getYCor() + (7*float(radius)/10), 1, colors[WHITE]);
		DrawLine(getXCor() + (float(radius)/5), getYCor() + (7*float(radius)/10), getXCor() - (float(radius)/5), getYCor() + (7*float(radius)/10), 1, colors[WHITE]);

		if (Board::bombTimer >= bomb.getFireRange() +10)
		{
			bomb.setIncX(0);
			bomb.setIncY(0);
			bomb.setXCor(-100);
			bomb.setYCor(-100);
		}
		if (Board::bombTimer >= bomb.getFireRange() + 30)
		{
			Shoot();
		}
		bomb.Draw();
		bomb.Move();
	}
	else
	{
		setXCor(-100);
		setYCor(-100);
		setRadius(0);
	}
}

void Saucers::Move() {
	if (getIsAlive() == true)
	{
		int radius = getRadius();

		if (isLarge == false && Board::secCount %30 == 0)
		{
			incX = GetRandInRange(-3, 3) +2;
			incY = GetRandInRange(-3, 3) +2;
		}

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

void Saucers::Shoot() {
	bomb.setXCor( getXCor() );
	bomb.setYCor( getYCor() );
	bomb.setIncX( incX *3);
	bomb.setIncY( incY *3);
	bomb.setIsAlive(true);
	bomb.setFireRange(Board::bombTimer);
//	cout << bomb.getIncX() << " " << bomb.getIncY() << endl;
}

Saucers::~Saucers() {
}

int Saucers::getTimer() const {
	return timer;
}

void Saucers::setTimer(int timer) {
	this->timer = timer;
}
