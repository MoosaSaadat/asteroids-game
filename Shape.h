/*
 * Shape.h
 *
 *  Created on: May 5, 2018
 *      Author: i170037
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "util.h"

class Shape {
	float xCor, yCor, radius;
	bool isAlive;
public:
	Shape(float, float, float, bool = true);
	virtual void Move() = 0;
	virtual void Draw() = 0;
//	virtual void Destroy() = 0;
	float getXCor() const;
	void setXCor(float cor);
	float getYCor() const;
	void setYCor(float cor);
	float getRadius() const;
	void setRadius(float radius);
	bool getIsAlive() const;
	void setIsAlive(bool isAlive);
	~Shape();
};

#endif /* SHAPE_H_ */
