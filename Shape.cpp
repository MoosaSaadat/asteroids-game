/*
 * Shape.cpp
 *
 *  Created on: May 5, 2018
 *      Author: i170037
 */

#include "Shape.h"

Shape::Shape(float x, float y, float r, bool status) {
	xCor = x;
	yCor = y;
	radius = r;
	isAlive = status;
}

Shape::~Shape() {
}


float Shape::getXCor() const {
	return xCor;
}

void Shape::setXCor(float cor) {
	xCor = cor;
}

float Shape::getYCor() const {
	return yCor;
}

void Shape::setYCor(float cor) {
	yCor = cor;
}

float Shape::getRadius() const {
	return radius;
}

void Shape::setRadius(float radius) {
	this->radius = radius;
}

bool Shape::getIsAlive() const {
	return isAlive;
}

void Shape::setIsAlive(bool isAlive) {
	this->isAlive = isAlive;
}
