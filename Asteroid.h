/*
 * Asteroid.h
 *
 *  Created on: May 5, 2018
 *      Author: i170037
 */

#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "Shape.h"
#include "cmath"
#include "Board.h"

class Asteroid: public Shape {
	int sides, deathCount;
	float circumX, circumY;
	float angle;
	float incX, incY;
	bool isSimple;
public:
	Asteroid(float, float, int = 6, int = 50, bool = true, int = 0);
	void Draw();
	void Rotate(int = 1);
	void Move();
	bool getIsSimple() const;
	void setIsSimple(bool isSimple);
	~Asteroid();
	int getDeathCount() const;
	void setDeathCount(int deathCount);
};

#endif /* ASTEROID_H_ */
