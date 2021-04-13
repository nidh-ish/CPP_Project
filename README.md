# CPP_Project


  - Read the file.
  - Compute the area of each face in the graphical object, and sort the faces by area.
  - Each face is a triangle, hence, the formula for area of the triangle can be used.
  - For polygon with more than 3 vertices, you can pick one vertex and introduce edges from the vertex to all other vertices, in addition to its existing edges. The new edges “subdivide” the polygon to triangles. The area of the polygon is the sum total of the areas of the new triangles.
  - Discard faces which are in the lower 10% of the sorted list of triangles.
  - Prune vertices which are now not shared by any faces.
  - Output the filtered surface mesh in a .ply file format.
