#ifndef Vertex_H
#define Vertex_H

class Vertex {                                          //Vertex class contains x, y, z coordinate

	private:

		float x,y,z;

	public:

		Vertex(float X, float Y, float Z);     //Three coordinates are passed and initialized in the constructor

		Vertex(){};                            //This is the default constructor   

		void setX(float xc);                   //Set methods for setting the individual vertices
		void setY(float yc);
		void setZ(float zc);

		float getX();                          //Get methods to get the individual vertices
		float getY();
		float getZ();

};
#endif
