#include "Triangle.h"
#include "Vertex.h"
#include "Face.h"
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

Triangle :: Triangle(vector<Vertex> vertx, vector<Face> faces) {

	vrtx = vertx;
	face = faces;
}

vector<Face>& Triangle :: getFaces() {

	return face;
}

vector<Vertex>& Triangle :: getVertx() {

	return this->vrtx;
}

static bool areaCmp(Face f1, Face f2) {   //This is a boolean method that compares area of two faces(triangles) 

	if(f1.area() > f2.area()) {
		return true;
	}

	return false;
}

void Triangle :: Sort() {                //This method sorts the vector of triangles according to their area

	sort(face.begin(), face.end(), areaCmp);
}

void Triangle :: evictFaces() {          //This method discards the lower 10 percent of the sorted list of triangles 

	int faceSize = face.size();

	int evict = 0.1 * faceSize;

	for(int i = 0; i < evict; i++) { //We store the removed trianlges(faces) in the vector, evictedFaces

		evictedFaces.push_back(face[faceSize - i - 1]);
		face.erase(face.begin() + (faceSize - i - 1));
	}
}

void Triangle :: vertexFinal() {   //This method checks if there is some vertex that is not being shared by any of the faces
                                   //If it is, we remove that vertex from the vertex vector
	int faceSize = face.size();
	int vertexSize = vrtx.size();

	for(int i = 0; i < evictedFaces.size(); i++) { //For each evicted face, we iterate through this loop

		int ec1_index1, ec1_index2, ec1_index3 = 0;
		int ec2_index1, ec2_index2, ec2_index3 = 0;
		int ec3_index1, ec3_index2, ec3_index3 = 0;

		Vertex ec1 = evictedFaces[i].getV1(); //We store the vertex of the evicted face
		Vertex ec2 = evictedFaces[i].getV2();
		Vertex ec3 = evictedFaces[i].getV3();

		for(int j = 0; j < faceSize; j++) { //Now we iterate through each of the remaining faces

			Vertex v1 = face[j].getV1();
			Vertex v2 = face[j].getV2();
			Vertex v3 = face[j].getV3();

	
			if( (abs(ec1.getX() - v1.getX()) < 1e-6) && (abs(ec1.getY() - v1.getY()) < 1e-6) && (abs(ec1.getZ() - v1.getZ()) < 1e-6) ) {
                		continue;
            		}
			else {                                       //We increase the count if the vertex does not match with the remaining vertex in the faces vector
				ec1_index1 = ec1_index1 + 1;
			}

			if( (abs(ec1.getX() - v2.getX()) < 1e-6) && (abs(ec1.getY() - v2.getY()) < 1e-6) && (abs(ec1.getZ() - v2.getZ()) < 1e-6) ) {
                                continue;
                        }
                        else {
                                ec1_index2 = ec1_index2 + 1;
                        }

			if( (abs(ec1.getX() - v3.getX()) < 1e-6) && (abs(ec1.getY() - v3.getY()) < 1e-6) && (abs(ec1.getZ() - v3.getZ()) < 1e-6) ) {
                                continue;
                        }
                        else {
                                ec1_index3 = ec1_index3 + 1;
                        }


			if( (abs(ec2.getX() - v1.getX()) < 1e-6) && (abs(ec2.getY() - v1.getY()) < 1e-6) && (abs(ec2.getZ() - v1.getZ()) < 1e-6) ) {
                                continue;
                        }
                        else {
                                ec2_index1 = ec2_index1 + 1;
                        }

                        if( (abs(ec2.getX() - v2.getX()) < 1e-6) && (abs(ec2.getY() - v2.getY()) < 1e-6) && (abs(ec2.getZ() - v2.getZ()) < 1e-6) ) {
                                continue;
                        }
                        else {
                                ec2_index2 = ec2_index2 + 1;
                        }

                        if( (abs(ec2.getX() - v3.getX()) < 1e-6) && (abs(ec2.getY() - v3.getY()) < 1e-6) && (abs(ec2.getZ() - v3.getZ()) < 1e-6) ) {
                                continue;
                        }
                        else {
                                ec2_index3 = ec2_index3 + 1;
                        }



			if( (abs(ec2.getX() - v1.getX()) < 1e-6) && (abs(ec2.getY() - v1.getY()) < 1e-6) && (abs(ec2.getZ() - v1.getZ()) < 1e-6) ) {
                                continue;
                        }
                        else {
                                ec3_index1 = ec3_index1 + 1;
                        }

                        if( (abs(ec2.getX() - v2.getX()) < 1e-6) && (abs(ec2.getY() - v2.getY()) < 1e-6) && (abs(ec2.getZ() - v2.getZ()) < 1e-6) ) {
                                continue;
                        }
                        else {
                                ec3_index2 = ec3_index2 + 1;
                        }

                        if( (abs(ec2.getX() - v3.getX()) < 1e-6) && (abs(ec2.getY() - v3.getY()) < 1e-6) && (abs(ec2.getZ() - v3.getZ()) < 1e-6) ) {
                                continue;
                        }
                        else {
                                ec3_index3 = ec3_index3 + 1;
                        }
		}   //If count is equal to the size of the face vector, it means that, there is no face using that vertex in the final set of faces, so we have to prune that vertex

		
		if( (ec1_index1 == faceSize) && (ec1_index2 == faceSize) && (ec1_index3 == faceSize) ) { //If the count is equal to the size of the face vector, we remove that vertex from the vertex vector

			for(int k = 0; k < vertexSize; k++) {

				Vertex ck = vrtx[k];
				if( (abs(ck.getX() - ec1.getX()) < 1e-6) && (abs(ck.getY() - ec1.getY()) < 1e-6) && (abs(ck.getZ() - ec1.getZ()) < 1e-6) ) {
			                vrtx.erase(vrtx.begin() + k);
                    			break;
                		}
				else {
					continue;
				}
			}
		}

		if( (ec2_index1 == faceSize) && (ec2_index2 == faceSize) && (ec2_index3 == faceSize) ) {

                        for(int k = 0; k < vertexSize; k++) {

                                Vertex ck = vrtx[k];
                                if( (abs(ck.getX() - ec3.getX()) < 1e-6) && (abs(ck.getY() - ec3.getY()) < 1e-6) && (abs(ck.getZ() - ec3.getZ()) < 1e-6) ) {
                                        vrtx.erase(vrtx.begin() + k);
                                        break;
                                }
                                else {
                                        continue;
                                }
                        }
                }

		if( (ec3_index1 == faceSize) && (ec3_index2 == faceSize) && (ec3_index3 == faceSize) ) {

                        for(int k = 0; k < vertexSize; k++) {

                                Vertex ck = vrtx[k];
                                if( (abs(ck.getX() - ec3.getX()) < 1e-6) && (abs(ck.getY() - ec3.getY()) < 1e-6) && (abs(ck.getZ() - ec3.getZ()) < 1e-6) ) {
                                        vrtx.erase(vrtx.begin() + k);
                                        break;
                                }
                                else {
                                        continue;
                                }
                        }
                }
	}
}
