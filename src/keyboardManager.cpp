#include "StarletControls/keyboardManager.hpp"

#include <GLFW/glfw3.h>

static_assert(KeyboardManager::KEY_MAX == GLFW_KEY_LAST + 1, "KEY_COUNT must equal GLFW_KEY_LAST + 1");

std::vector<KeyEvent> KeyboardManager::consumeKeyEvents() {
  std::vector<KeyEvent> out{};
  out.swap(keyEvents);
  return out;
}

void KeyboardManager::clear() {
  keyLast.fill(false);
}

void KeyboardManager::onKey(const KeyEvent event) {
  if (!validKey(event.key)) return;

  if (event.action == GLFW_PRESS) {
    if (!keyDown[event.key]) keyLast[event.key] = true;
    keyDown[event.key] = true;
  }
  else if (event.action == GLFW_RELEASE)
    keyDown[event.key] = false;

  keyEvents.push_back(event);
}

bool KeyboardManager::isKeyDown(const int key) const {
  return validKey(key) && keyDown[key];
}
bool KeyboardManager::isKeyPressed(const int key) const {
  return validKey(key) && keyLast[key];
}