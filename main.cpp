#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include "Vertex.h"
#include "Face.h"
#include "Triangle.h"
#include <bits/stdc++.h>

using namespace std;

int main() {

	ifstream fin;                           

	fin.open("input.ply");

	string input;

	int vertex, face = 0;

	vector <Vertex> vertices;
	vector <Face> faces;

	while(fin >> input) {

		if(input == "element") {
			
			fin >> input;

			if(input == "face") {
			
				fin >> input;
				face = stoi(input);
			}
			
			else if(input == "vertex") {
			
				fin >> input;
				vertex = stoi(input);
			}
		}

		if(input == "end_header") {

			int i = 0;
			
			while(i < vertex) {
				
				float vt[3];
				int j = 0;
	
				while(j < 3) {

					fin >> input;
					vt[j] = stof(input);
					j = j + 1;
				}
	
				Vertex vrtx(vt[0], vt[1], vt[2]);
				vertices.push_back(vrtx);	
	
				i = i + 1;
			}

			i = 0;

			while(i < face) {
				
				fin >> input;

				int c = stoi(input);

				int posVertex[c];

				int j = 0;
			
				while(j < c) {
					
					fin >> input;
					posVertex[j] = stoi(input);

					j = j + 1;
				}

				if(c == 3) {

					Face face(vertices[posVertex[0]], vertices[posVertex[1]], vertices[posVertex[2]]);
					faces.push_back(face);
				}
                		
				else if(c > 3) {

					for(int k = 1; k < c - 1; k++) {
			             
				     		Face face(vertices[posVertex[0]] ,vertices[posVertex[k]] , vertices[posVertex[k+1]]);
                        			faces.push_back(face) ;
                			}
        			}

				i = i + 1;
			}		
		}
	}

	Triangle tr(vertices, faces);
	
	tr.Sort();

	tr.evictFaces();

	tr.vertexFinal();

	vector<Vertex> updatedVrtx = tr.getVertx();

	vector<Face> updatedFace = tr.getFaces();

	ofstream fout;

	fout.open("output.ply");

	fout << "ply" << endl;
	fout << "format ascii 1.0" << endl;
	fout << "comment made by anonymous" << endl;
	fout << "comment this file is a cube " << endl;
	fout << "element vertex " << updatedVrtx.size() << endl;
	fout << "property float32 x" << endl;
	fout << "property float32 y" << endl;
	fout << "property float32 z" << endl;
	fout << "element face " << updatedFace.size() << endl;
	fout << "property list uint8 int32 vertex_index" << endl;
	fout << "end_header" << endl;

	for(int i = 0; i < updatedVrtx.size(); i++) {

		fout << updatedVrtx[i].getX() << " " << updatedVrtx[i].getY() << " " << updatedVrtx[i].getZ() << endl;
	}

	for(int i = 0; i < updatedFace.size(); i++) {

		int pos1, pos2, pos3 = 0;

		float v1x = updatedFace[i].getV1().getX(); 
		float v1y = updatedFace[i].getV1().getY();
		float v1z = updatedFace[i].getV1().getZ();

		float v2x = updatedFace[i].getV2().getX(); 
		float v2y = updatedFace[i].getV2().getY(); 
		float v2z = updatedFace[i].getV2().getZ(); 

		float v3x = updatedFace[i].getV3().getX(); 
		float v3y = updatedFace[i].getV3().getY(); 
		float v3z = updatedFace[i].getV3().getZ(); 

		for(int j = 0; j < updatedVrtx.size(); j++) {

			if( ( abs(v1x - updatedVrtx[j].getX()) < 1e-6 ) && ( abs(v1y - updatedVrtx[j].getY()) < 1e-6 ) && ( abs(v1z - updatedVrtx[j].getZ()) < 1e-6) ) {

				pos1 = j;
			}
			if( ( abs(v2x - updatedVrtx[j].getX()) < 1e-6 ) && ( abs(v2y - updatedVrtx[j].getY()) < 1e-6 ) && ( abs(v2z - updatedVrtx[j].getZ()) < 1e-6) ) {

				pos2 = j;
			}
			if( ( abs(v3x - updatedVrtx[j].getX()) < 1e-6 ) && ( abs(v3y - updatedVrtx[j].getY()) < 1e-6 ) && ( abs(v3z - updatedVrtx[j].getZ()) < 1e-6 ) ) {
				
				pos3 = j;
			}
		}
		fout << "3" << " " << pos1 << " " << pos2 << " " << pos3 << endl;
	}
}
