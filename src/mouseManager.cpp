#include "StarletControls/mouseManager.hpp"

#include <GLFW/glfw3.h>

void MouseManager::update(GLFWwindow* window) {
  double xPos, yPos;
  glfwGetCursorPos(window, &xPos, &yPos);

  if (!cursorLocked) {
    mouseDelta = { 0.0f, 0.0f };
    lastMousePos = { xPos, yPos };
    firstMouse = true;
    return;
  }

  if (firstMouse) {
    lastMousePos = { xPos, yPos };
    firstMouse = false;
  }

  mouseDelta.x = xPos - lastMousePos.x;
  mouseDelta.y = lastMousePos.y - yPos;
  lastMousePos = { xPos, yPos };
}

double MouseManager::consumeScrollX() {
  double x = scrollDelta.x;
  scrollDelta.x = 0.0f;
  return x;
}
double MouseManager::consumeScrollY() {
  double y = scrollDelta.y;
  scrollDelta.y = 0.0f;
  return y;
}

void MouseManager::onScroll(const double xOffset, const double yOffset) {
  scrollDelta.x += xOffset;
  scrollDelta.y += yOffset;
}

void MouseManager::setCursorLocked(const bool locked) {
  cursorLocked = locked;
  firstMouse = true;
}
