#include <GLFW/glfw3.h>
#include "starletcontrols/inputManager.hpp"
#include "starletparsers/utils/log.hpp"

const int InputManager::trackedKeys[TRACKED_KEY_COUNT] = {
  GLFW_KEY_W, GLFW_KEY_A, GLFW_KEY_S, GLFW_KEY_D,
  GLFW_KEY_SPACE, GLFW_KEY_LEFT_CONTROL,
  GLFW_KEY_UP, GLFW_KEY_DOWN, GLFW_KEY_LEFT, GLFW_KEY_RIGHT,
  GLFW_KEY_COMMA, GLFW_KEY_PERIOD, GLFW_KEY_E, GLFW_KEY_Q,
  GLFW_KEY_R, GLFW_KEY_F, GLFW_KEY_T, GLFW_KEY_G, GLFW_KEY_Y, GLFW_KEY_H
};

void InputManager::update(GLFWwindow* window) {
  for (int i = 0; i < TRACKED_KEY_COUNT; ++i) {
    previousKeyState[i] = keyState[i];
    keyState[i] = glfwGetKey(window, trackedKeys[i]) == GLFW_PRESS;
  }
  
  double xPos, yPos;
  glfwGetCursorPos(window, &xPos, &yPos);

  if (!cursorLocked) {
    mouseDelta = { 0.0f, 0.0f };
    lastMouseX = xPos;
    lastMouseY = yPos;
    firstMouse = true;
    return;
  }

  if (firstMouse) {
    lastMouseX = xPos;
    lastMouseY = yPos;
    firstMouse = false;
  }

  mouseDelta.x = static_cast<float>(xPos - lastMouseX);
  mouseDelta.y = static_cast<float>(lastMouseY - yPos);
  lastMouseX = xPos;
  lastMouseY = yPos;
}

bool InputManager::isKeyDown(int key) const {
  for (int i = 0; i < TRACKED_KEY_COUNT; ++i)
    if (trackedKeys[i] == key)
      return keyState[i];

  return false;
}
bool InputManager::isKeyPressed(int key) const {
  for (int i = 0; i < TRACKED_KEY_COUNT; ++i)
    if (trackedKeys[i] == key)
      return keyState[i] && !previousKeyState[i]; 

  return false;
}

void InputManager::setCursorLocked(bool locked) {
  cursorLocked = locked;
  firstMouse = true;
}

