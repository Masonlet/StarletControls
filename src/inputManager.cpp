#include <GLFW/glfw3.h>
#include "StarletControls/inputManager.hpp"
#include "StarletParsers/utils/log.hpp"
static_assert(InputManager::keyCount() == GLFW_KEY_LAST + 1, "KEY_COUNT must equal GLFW_KEY_LAST + 1");

void InputManager::clear() {
  keyLast.fill(false);
}

void InputManager::update(GLFWwindow* window) {
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

bool InputManager::isKeyDown(int key) const {
  return validKey(key) && keyDown[key];
}
bool InputManager::isKeyPressed(int key) const {
  return validKey(key) && keyLast[key];
}

void InputManager::setCursorLocked(bool locked) {
  cursorLocked = locked;
  firstMouse = true;
}

void InputManager::onKey(KeyEvent event) {
  if (!validKey(event.key)) return;

  if (event.action == GLFW_PRESS) {
    if (!keyDown[event.key]) keyLast[event.key] = true;
    keyDown[event.key] = true;
  }
  else if (event.action == GLFW_RELEASE)
    keyDown[event.key] = false;

  keyEvents.push_back(event);
}

void InputManager::onScroll(double xOffset, double yOffset) {
  scrollDelta.x += xOffset;
  scrollDelta.y += yOffset;
}

std::vector<KeyEvent> InputManager::consumeKeyEvents() {
  std::vector<KeyEvent> out;
  out.swap(keyEvents);
  return out;
}
double InputManager::consumeScrollX() {
  double x = scrollDelta.x;
  scrollDelta.x = 0.0f;
  return x;
}
double InputManager::consumeScrollY() {
  double y = scrollDelta.y;
  scrollDelta.y = 0.0f;
  return y;
}