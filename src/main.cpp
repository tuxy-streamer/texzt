#include <GLFW/glfw3.h>
#include <cstddef>
#include <iostream>
using namespace std;

int create_window(int width, int height, char *title) {
  GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);
  if (window == NULL) {
    cout << "Failed to create window." << endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwDestroyWindow(window);
  return 0;
}

int main(int argc, char *argv[]) {
  glfwInit();
  // HACK: Version hinting
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  char *title = (char *)("Texzt");
  create_window(800, 800, title);
  glfwTerminate();
  return 0;
}
