/*
 * Saucers.h
 *
 *  Created on: May 5, 2018
 *      Author: i170037
 */

#ifndef SAUCERS_H_
#define SAUCERS_H_

#include "Shape.h"
#include "Board.h"
#include "Bomb.h"

class Saucers: public Shape {
	bool isLarge;
	float incX, incY;
	Bomb bomb;
	int timer;
public:
	Saucers(float, float, float = 40, bool = false);
	void Draw();
	void Move();
	void Shoot();
	~Saucers();
	int getTimer() const;
	void setTimer(int timer);
};

#endif /* SAUCERS_H_ */
