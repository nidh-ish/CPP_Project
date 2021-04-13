#ifndef Triangle_H
#define Triangle_H
#include "Vertex.h"
#include "Face.h"
#include <vector>

using namespace std;

class Triangle {                                                        //Triangle class contains a vector of vertices, faces(triangles), and removed faces(triangles)
	
	private:
		
		vector<Vertex> vrtx;
		vector<Face> face;
		vector<Face> evictedFaces;

	public:

		Triangle(vector<Vertex> vertx, vector<Face> faces);   //Passing an initialising vector of vertices and faces
		
		void Sort();                                          //Sorting the triangles(faces) according to their area in descending order

		void evictFaces();                                    //This method discard lower 10 percent of the sorted list of triangles and stores all the triangles(faces) removed in the evictedFaces vector

		void vertexFinal();                                   //Now this method prune vertices which are not shared by any of the faces

		vector<Face>& getFaces();                             //Getter for returning vector of faces  

		vector<Vertex>& getVertx();                           //Getter for returning vector of vertices
};
#endif
