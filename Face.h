#ifndef Face_H
#define Face_H
#include "Vertex.h"

class Face {

	private:                                              //Face file contains three vertices of a triangle

		Vertex v1, v2, v3;

	public:

		Face(Vertex vt1, Vertex vt2, Vertex vt3);     //Passing and initializing the three vertices in the constructor

		float area();                                 //This method calculates the area of the triangle formed using the three vertices
		
		void setV1(Vertex vertx1);                    //Setters to set the individual vertices
		void setV2(Vertex vertx2);
		void setV3(Vertex vertx3);

		Vertex getV1();                               //Getters to get the individual vertices
		Vertex getV2();
		Vertex getV3();

};
#endif
