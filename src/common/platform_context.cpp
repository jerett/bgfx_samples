#include "platform_context.h"
#include <bx/platform.h>
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
#	define GLFW_EXPOSE_NATIVE_X11
#	define GLFW_EXPOSE_NATIVE_GLX
#elif BX_PLATFORM_OSX
#	define GLFW_EXPOSE_NATIVE_COCOA
#	define GLFW_EXPOSE_NATIVE_NSGL
#elif BX_PLATFORM_WINDOWS
#	define GLFW_EXPOSE_NATIVE_WIN32
#	define GLFW_EXPOSE_NATIVE_WGL
#endif //
#include <GLFW/glfw3native.h>
#include <bgfx/platform.h>

static void* GLFWNativeWindowHandle(GLFWwindow *window) {
#	if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
  return (void*)(uintptr_t)glfwGetX11Window(window);
#	elif BX_PLATFORM_OSX
  return glfwGetCocoaWindow(window);
#	elif BX_PLATFORM_WINDOWS
  return glfwGetWin32Window(window);
#	endif // BX_PLATFORM_
}

void SetGLFWContext(GLFWwindow *window) {
  bgfx::PlatformData pd;
#	if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
  pd.ndt = glfwGetX11Display();
#	elif BX_PLATFORM_OSX
  pd.ndt = NULL;
#	elif BX_PLATFORM_WINDOWS
  pd.ndt = NULL;
#	endif // BX_PLATFORM_WINDOWS
  pd.nwh = GLFWNativeWindowHandle(window);
  pd.context = NULL;
  pd.backBuffer = NULL;
  pd.backBufferDS = NULL;
  bgfx::setPlatformData(pd);
}
