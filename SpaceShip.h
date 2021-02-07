/*
 * SpaceShip.h
 *
 *  Created on: May 5, 2018
 *      Author: i170037
 */

#ifndef SPACESHIP_H_
#define SPACESHIP_H_

#include "Shape.h"
#include "cmath"
#include "Board.h"
#include "Bomb.h"

class SpaceShip: public Shape {
	float x1, y1,
		  x2, y2,
		  x3, y3,
		  x4, y4,
		  x5, y5,
		  x6, y6,
		  x7, y7,
		  x8, y8;
	float gradientX, gradientY;
	float acceleration;
	bool thrustCheck;
	int bombCount;
	int rangeCheck;
public:
	Bomb * bombArr;
	SpaceShip(float = 500, float = 400, float = 25);
	void Draw();
	void Move();
	void Shoot();
	void Rotate(int);
	~SpaceShip();
	float getGradientX() const;
	float getGradientY() const;
	float getAcceleration() const;
	void setAcceleration(float acceleration);
};

#endif /* SPACESHIP_H_ */
