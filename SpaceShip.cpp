/*
 * SpaceShip.cpp
 *
 *  Created on: May 5, 2018
 *      Author: i170037
 */

#include "SpaceShip.h"

SpaceShip::SpaceShip(float x, float y, float r)
: Shape(x, y, r)
{
	x1 = x; 			y1 = y + r;
	x2 = x - r; 		y2 = y - r;
	x3 = x + r; 		y3 = y - r;
	x4 = x + (3*r)/5; 	y4 = y - (2*r)/5;
	x5 = x - (3*r)/5; 	y5 = y - (2*r)/5;
	x6 = x; 			y6 = y - r;
	x7 = x + r/5; 		y7 = y - (2*r)/5;
	x8 = x - r/5; 		y8 = y - (2*r)/5;
	thrustCheck = false;
	gradientX = (x1 - getXCor()) / 5;
	gradientY = (y1 - getYCor()) / 5;
	bombCount = 0;
	bombArr = new Bomb[50];
	acceleration = 0.5;
}

void SpaceShip::Draw() {
	if (getIsAlive() == true)
	{
//		DrawCircle(getXCor(), getYCor(), getRadius(), colors[ORANGE]);
		if (thrustCheck == true)
		{
			DrawLine(x6, y6, x7, y7, 1, colors[WHITE]);
			DrawLine(x6, y6, x8, y8, 1, colors[WHITE]);
		}
		DrawLine(x1, y1, x2, y2, 1, colors[WHITE]);
		DrawLine(x1, y1, x3, y3, 1, colors[WHITE]);
		DrawLine(x4, y4, x5, y5, 1, colors[WHITE]);
		for (int i = 0; i < bombCount; i += 1)
		{
			if (Board::bombTimer >= bombArr[i].getFireRange() +10)
			{
				bombArr[i].setXCor(-10);
				bombArr[i].setYCor(-10);
				bombArr[i].setIncX(0);
				bombArr[i].setIncY(0);
			}
			bombArr[i].Draw();
			bombArr[i].Move();
		}
	}
	else
	{
		setXCor(-100);
		setYCor(-100);
		setRadius(0);
	}
}

void SpaceShip::Rotate(int angle) {
	float newX1 = x1*cos(Deg2Rad(angle))
				- y1*sin(Deg2Rad(angle))
				+ getXCor()*(1 - cos(Deg2Rad(angle)))
				+ getYCor()*sin(Deg2Rad(angle));
	float newY1 = x1*sin(Deg2Rad(angle))
				+ y1*cos(Deg2Rad(angle))
				+ (1 - cos(Deg2Rad(angle)))*getYCor()
				- sin(Deg2Rad(angle))*getXCor();
	float newX2 = x2*cos(Deg2Rad(angle))
				- y2*sin(Deg2Rad(angle))
				+ getXCor()*(1 - cos(Deg2Rad(angle)))
				+ getYCor()*sin(Deg2Rad(angle));
	float newY2 = x2*sin(Deg2Rad(angle))
				+ y2*cos(Deg2Rad(angle))
				+ (1 - cos(Deg2Rad(angle)))*getYCor()
				- sin(Deg2Rad(angle))*getXCor();
	float newX3 = x3*cos(Deg2Rad(angle))
				- y3*sin(Deg2Rad(angle))
				+ getXCor()*(1 - cos(Deg2Rad(angle)))
				+ getYCor()*sin(Deg2Rad(angle));
	float newY3 = x3*sin(Deg2Rad(angle))
				+ y3*cos(Deg2Rad(angle))
				+ (1 - cos(Deg2Rad(angle)))*getYCor()
				- sin(Deg2Rad(angle))*getXCor();
	float newX4 = x4*cos(Deg2Rad(angle))
				- y4*sin(Deg2Rad(angle))
				+ getXCor()*(1 - cos(Deg2Rad(angle)))
				+ getYCor()*sin(Deg2Rad(angle));
	float newY4 = x4*sin(Deg2Rad(angle))
				+ y4*cos(Deg2Rad(angle))
				+ (1 - cos(Deg2Rad(angle)))*getYCor()
				- sin(Deg2Rad(angle))*getXCor();
	float newX5 = x5*cos(Deg2Rad(angle))
				- y5*sin(Deg2Rad(angle))
				+ getXCor()*(1 - cos(Deg2Rad(angle)))
				+ getYCor()*sin(Deg2Rad(angle));
	float newY5 = x5*sin(Deg2Rad(angle))
				+ y5*cos(Deg2Rad(angle))
				+ (1 - cos(Deg2Rad(angle)))*getYCor()
				- sin(Deg2Rad(angle))*getXCor();
	float newX6 = x6*cos(Deg2Rad(angle))
				- y6*sin(Deg2Rad(angle))
				+ getXCor()*(1 - cos(Deg2Rad(angle)))
				+ getYCor()*sin(Deg2Rad(angle));
	float newY6 = x6*sin(Deg2Rad(angle))
				+ y6*cos(Deg2Rad(angle))
				+ (1 - cos(Deg2Rad(angle)))*getYCor()
				- sin(Deg2Rad(angle))*getXCor();
	float newX7 = x7*cos(Deg2Rad(angle))
				- y7*sin(Deg2Rad(angle))
				+ getXCor()*(1 - cos(Deg2Rad(angle)))
				+ getYCor()*sin(Deg2Rad(angle));
	float newY7 = x7*sin(Deg2Rad(angle))
				+ y7*cos(Deg2Rad(angle))
				+ (1 - cos(Deg2Rad(angle)))*getYCor()
				- sin(Deg2Rad(angle))*getXCor();
	float newX8 = x8*cos(Deg2Rad(angle))
				- y8*sin(Deg2Rad(angle))
				+ getXCor()*(1 - cos(Deg2Rad(angle)))
				+ getYCor()*sin(Deg2Rad(angle));
	float newY8 = x8*sin(Deg2Rad(angle))
				+ y8*cos(Deg2Rad(angle))
				+ (1 - cos(Deg2Rad(angle)))*getYCor()
				- sin(Deg2Rad(angle))*getXCor();
	x1 = newX1;
	y1 = newY1;
	x2 = newX2;
	y2 = newY2;
	x3 = newX3;
	y3 = newY3;
	x4 = newX4;
	y4 = newY4;
	x5 = newX5;
	y5 = newY5;
	x6 = newX6;
	y6 = newY6;
	x7 = newX7;
	y7 = newY7;
	x8 = newX8;
	y8 = newY8;
	gradientX = (x1 - getXCor()) / 5;
	gradientY = (y1 - getYCor()) / 5;
}

void SpaceShip::Move() {
	if (getIsAlive() == true)
	{
		if (Board::secCount %2 == 0)
			thrustCheck = true;
		else
			thrustCheck = false;

		setXCor(getXCor() + gradientX * acceleration);
		setYCor(getYCor() + gradientY * acceleration);
		x1 += gradientX * acceleration;
		y1 += gradientY * acceleration;
		x2 += gradientX * acceleration;
		y2 += gradientY * acceleration;
		x3 += gradientX * acceleration;
		y3 += gradientY * acceleration;
		x4 += gradientX * acceleration;
		y4 += gradientY * acceleration;
		x5 += gradientX * acceleration;
		y5 += gradientY * acceleration;
		x6 += gradientX * acceleration;
		y6 += gradientY * acceleration;
		x7 += gradientX * acceleration;
		y7 += gradientY * acceleration;
		x8 += gradientX * acceleration;
		y8 += gradientY * acceleration;
		gradientX = (x1 - getXCor()) / 5;
		gradientY = (y1 - getYCor()) / 5;
		if (acceleration < 2.00)
			acceleration += 0.2;

		//Checks to keep in board
		if (x2 -10 >= 1020 && x3 -10 >= 1020 && gradientX > 0)
		{
			//current differences
			int d1 = x1 - getXCor(),
				d2 = x2 - getXCor(),
				d3 = x3 - getXCor(),
				d4 = x4 - getXCor(),
				d5 = x5 - getXCor(),
				d6 = x6 - getXCor(),
				d7 = x7 - getXCor(),
				d8 = x8 - getXCor();
			setXCor(-getRadius());
			x1 = d1 + getXCor();
			x2 = d2 + getXCor();
			x3 = d3 + getXCor();
			x4 = d4 + getXCor();
			x5 = d5 + getXCor();
			x6 = d6 + getXCor();
			x7 = d7 + getXCor();
			x8 = d8 + getXCor();
		}
		if (x2 + 10 <= 0 && x3 +10 <= 0 && gradientX < 0)
		{
			//current differences
			//current differences
			int d1 = x1 - getXCor(),
				d2 = x2 - getXCor(),
				d3 = x3 - getXCor(),
				d4 = x4 - getXCor(),
				d5 = x5 - getXCor(),
				d6 = x6 - getXCor(),
				d7 = x7 - getXCor(),
				d8 = x8 - getXCor();
			setXCor(1020 + getRadius());
			x1 = d1 + getXCor();
			x2 = d2 + getXCor();
			x3 = d3 + getXCor();
			x4 = d4 + getXCor();
			x5 = d5 + getXCor();
			x6 = d6 + getXCor();
			x7 = d7 + getXCor();
			x8 = d8 + getXCor();
		}
		if (y2 - 10 >= 840 && y3 - 10 >= 840 && gradientY > 0)
		{
			//current differences
			int d1 = y1 - getYCor(),
				d2 = y2 - getYCor(),
				d3 = y3 - getYCor(),
				d4 = y4 - getYCor(),
				d5 = y5 - getYCor(),
				d6 = y6 - getYCor(),
				d7 = y7 - getYCor(),
				d8 = y8 - getYCor();
			setYCor(-getRadius());
			y1 = d1 + getYCor();
			y2 = d2 + getYCor();
			y3 = d3 + getYCor();
			y4 = d4 + getYCor();
			y5 = d5 + getYCor();
			y6 = d6 + getYCor();
			y7 = d7 + getYCor();
			y8 = d8 + getYCor();
		}
		if (y2 + 10 <= 0 && y3 + 10 <= 0 && gradientY < 0)
		{
			//current differences
			int d1 = y1 - getYCor(),
				d2 = y2 - getYCor(),
				d3 = y3 - getYCor(),
				d4 = y4 - getYCor(),
				d5 = y5 - getYCor(),
				d6 = y6 - getYCor(),
				d7 = y7 - getYCor(),
				d8 = y8 - getYCor();
			setYCor(840 + getRadius());
			y1 = d1 + getYCor();
			y2 = d2 + getYCor();
			y3 = d3 + getYCor();
			y4 = d4 + getYCor();
			y5 = d5 + getYCor();
			y6 = d6 + getYCor();
			y7 = d7 + getYCor();
			y8 = d8 + getYCor();
		}
	}
}

void SpaceShip::Shoot() {
	if (bombCount >= 50)
		bombCount = 0;
	bombArr[bombCount].setXCor( getXCor() );
	bombArr[bombCount].setYCor( getYCor() );
	bombArr[bombCount].setIncX( gradientX *2);
	bombArr[bombCount].setIncY( gradientY *2);
	bombArr[bombCount].setFireRange(Board::bombTimer);
	bombCount ++;
}

float SpaceShip::getGradientX() const {
	return gradientX;
}

float SpaceShip::getGradientY() const {
	return gradientY;
}

SpaceShip::~SpaceShip() {
}

float SpaceShip::getAcceleration() const {
	return acceleration;
}

void SpaceShip::setAcceleration(float acceleration) {
	this->acceleration = acceleration;
}
