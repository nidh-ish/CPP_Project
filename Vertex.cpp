#include "Vertex.h"

Vertex :: Vertex(float X, float Y, float Z) : x(X), y(Y), z(Z) {}

void Vertex :: setX(float xc) {

	this->x = xc;
}

void Vertex :: setY(float yc) {

	this->y = yc;
}

void Vertex :: setZ(float zc) {

	this->z = zc;
}

float Vertex :: getX() {
	
	return this->x;
}

float Vertex :: getY() {

	return this->y;
}

float Vertex :: getZ() {

	return this->z;
}
