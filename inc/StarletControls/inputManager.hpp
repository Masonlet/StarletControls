#pragma once 

#include "keyboardManager.hpp"
#include "mouseManager.hpp"

struct GLFWwindow;

class InputManager {
public:
  inline void clear() { keyboard.clear(); }
  inline void update(GLFWwindow* window) { mouse.update(window); }

  void onKey(const KeyEvent& event)        { keyboard.onKey(event); }
  bool isKeyDown(int key) const            { return keyboard.isKeyDown(key);    }
  bool isKeyPressed(int key) const         { return keyboard.isKeyPressed(key); }
  std::vector<KeyEvent> consumeKeyEvents() { return keyboard.consumeKeyEvents(); }

  void onScroll(double xOffset, double yOffset) { mouse.onScroll(xOffset, yOffset); }
  void setCursorLocked(bool locked)             { mouse.setCursorLocked(locked);    }
  double consumeScrollX()            { return mouse.consumeScrollX(); }
  double consumeScrollY()            { return mouse.consumeScrollY(); }
  bool isCursorLocked() const        { return mouse.isCursorLocked(); }
  Vec2<double> getMouseDelta() const { return mouse.getMouseDelta();  }

private:
  KeyboardManager keyboard;
  MouseManager mouse;
};