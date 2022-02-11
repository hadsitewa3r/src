#ifndef TEXTURE_CLASS
#define TEXTURE_CLASS

#include <iostream>
#include "glad/glad.h"
#include "stb_image.h"
#include "shaderClass.h"

class Texture{
public:
  GLuint ID;
  const char* type;
  GLuint unit;
  Texture(const char* image, const char* texType, GLuint slot, GLenum format, GLenum pixelType);
  void texUnit(Shader& shader, const char* uniform, GLuint unit);
  void Bind();
  void Unbind();
  void Delete();
};
#endif
