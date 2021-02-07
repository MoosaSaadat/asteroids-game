/*
 * Bomb.h
 *
 *  Created on: May 7, 2018
 *      Author: i170037
 */

#ifndef BOMB_H_
#define BOMB_H_

#include "Shape.h"

class Bomb: public Shape {
	float incX, incY, fireRange;
public:
	Bomb(float = -100, float = -100, float = 0, float = 0);
	void Draw();
	void Move();
	~Bomb();
	float getIncX() const;
	void setIncX(float incX);
	float getIncY() const;
	void setIncY(float incY);
	float getFireRange() const;
	void setFireRange(float fireRange);
};

#endif /* BOMB_H_ */
