#include <cstdio>
#include <bgfx/bgfx.h>
#include <GLFW/glfw3.h>
#include "platform_context.h"
#include <cassert>

bgfx::VertexDecl vertex_decl;
bgfx::VertexBufferHandle vbh;

void CreateTriangleVertex() {
  vertex_decl.begin()
    .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
    .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
    .end();

  struct ColoredVertex {
    float x;
    float y;
    float z;
    uint32_t rgba;
  };
  static ColoredVertex triangle_vertices[] =
  {
    {-.5f, -.5f, .0f, 0xff0000ff},
    {.5f, -.5f, .0f, 0x00ff00ff},
    {.0f, .5f, .0f, 0x0000ffff},
  };
  vbh = bgfx::createVertexBuffer(bgfx::makeRef(triangle_vertices, sizeof(triangle_vertices)), vertex_decl);
}

bgfx::ShaderHandle sh;
bgfx::ProgramHandle program;
void CreateShader() {
}

int main(int argc, char *argv[]) {
  glfwInit();
  auto window = glfwCreateWindow(800, 600, "triangle app", nullptr, nullptr);
  SetGLFWContext(window);
  assert(bgfx::init());

  CreateTriangleVertex();
  
  int width, height;
  glfwGetWindowSize(window, &width, &height);
  bgfx::reset(width, height);
  bgfx::setViewRect(0, 0, 0, width, height);

  while (!glfwWindowShouldClose(window)) {
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR, 0xff0000ff);
    bgfx::touch(0);
    bgfx::frame(0);
    glfwPollEvents();
  }
  return 0;
}
