#include <cstdio>
#include <bgfx/bgfx.h>
#include <GLFW/glfw3.h>
#include "platform_context.h"

int main(int argc, char *argv[]) {
  glfwInit();
  auto window = glfwCreateWindow(640, 480, "clear app", NULL, NULL);
  SetGLFWContext(window);

  int width, height;
  glfwGetWindowSize(window, &width, &height);
  bgfx::init();
  bgfx::reset(width, height);
  glfwSwapInterval(1);

  while (!glfwWindowShouldClose(window)) {
    const uint64_t time = static_cast<uint32_t>(glfwGetTime() * 100);
    const uint8_t r = (0 + time) % 255;
    const uint8_t g = (50 + time) % 255;
    const uint8_t b = (100 + time) % 255;
    
    const uint32_t color = (r << 24) | (g << 16) | (b << 8) | 0xff;
    bgfx::setViewRect(0, 0, 0, width, height);
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR, color);
    
    bgfx::touch(0);
    bgfx::frame();
    glfwPollEvents();
  }

  bgfx::shutdown();
  glfwTerminate();
  return 0;
}