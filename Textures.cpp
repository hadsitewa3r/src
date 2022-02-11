#include "libs/Textures.h"

Texture::Texture(const char* image, const char* texType, GLuint slot, GLenum format, GLenum pixelType){
  type = texType;
  //define the textures
  int widthImg, heightImg, nrChannels;
  stbi_set_flip_vertically_on_load(true);
  unsigned char *data = stbi_load(image, &widthImg, &heightImg, &nrChannels, 0);
  //taygenerati textures, 7tta hadi khasni ngolha lik ?
  GLuint texture;
  glGenTextures(1, &ID);
  glActiveTexture(GL_TEXTURE0 + slot);
  unit = slot;
  //z3ma rah 2d
  glBindTexture(GL_TEXTURE_2D, ID);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  if(data){
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }

  else {
    std::cout<<"A Chamss l3achiya 2"<<std::endl;
  }

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  //wayli nta baghi lmemory ghi t3mr mabitihach tkhwa
  stbi_image_free(data);
}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit){
  GLuint tex0Uni = glGetUniformLocation(shader.ID, uniform);
  shader.Activate();
  glUniform1i(tex0Uni,unit);
}

void Texture::Bind(){
  glActiveTexture(GL_TEXTURE0 + unit);
  glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind(){
  glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete() {
  glDeleteTextures(1, &ID);
}
