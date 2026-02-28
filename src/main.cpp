#include <GLFW/glfw3.h>
#include <cstddef>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  glfwInit();
  // HACK: Version hinting
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(800, 800, "Texzt", NULL, NULL);

  if (window == NULL) {
    cout << "Failed to create window." << endl;
    glfwTerminate();
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
