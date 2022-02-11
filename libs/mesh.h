#ifndef MESH_CLASS
#define MESH_CLASS

#include<string>
#include"VAO.h"
#include"EBO.h"
#include"Camera.h"
#include"Textures.h"

class Mesh{
public:
	std::vector <Vertex> vertices;
	std::vector <GLuint> indices;
	std::vector <Texture> textures;

  // Initializes the mesh
  Mesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices, std::vector <Texture>& textures);
  // Draws the mesh
  void Draw(Shader& shader, Camera& camera);
};

#endif
