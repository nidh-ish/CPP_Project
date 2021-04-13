#include "Face.h"
#include "Vertex.h"
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

Face :: Face(Vertex vt1, Vertex vt2, Vertex vt3) : v1(vt1), v2(vt2), v3(vt3) {}

float Face :: area() {   //This method computes the area of the triangle using its three vertices
                         //We apply Heron's formula to get the required area
	float a = sqrt(pow((this->v1.getX() - this->v2.getX()), 2.0) + pow((this->v1.getY() - this->v2.getY()), 2.0) + pow((this->v1.getZ() - this->v2.getZ()), 2.0));
	float b = sqrt(pow((this->v1.getX() - this->v3.getX()), 2.0) + pow((this->v1.getY() - this->v3.getY()), 2.0) + pow((this->v1.getZ() - this->v3.getZ()), 2.0));
	float c = sqrt(pow((this->v3.getX() - this->v2.getX()), 2.0) + pow((this->v3.getY() - this->v2.getY()), 2.0) + pow((this->v3.getZ() - this->v2.getZ()), 2.0));

	float s = (a + b + c) / 2;

	float area = abs(sqrt(s * (s - a) * (s - b) * (s - c)));

	return area;
}

void Face :: setV1(Vertex vertx1) {

	this->v1 = vertx1;
}	

void Face :: setV2(Vertex vertx2) {

	this->v2 = vertx2;
}

void Face :: setV3(Vertex vertx3) {

	this->v3 = vertx3;
}

Vertex Face :: getV1() {

	return this->v1;
}

Vertex Face :: getV2() {

	return this->v2;
}

Vertex Face :: getV3() {

	return this->v3;
}
