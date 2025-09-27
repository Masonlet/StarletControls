#pragma once 

#include "keyboardManager.hpp"
#include "mouseManager.hpp"

struct GLFWwindow;

class InputManager {
public:
  inline void reset() { keyboard.resetKeys(); mouse.resetButtons(); }

  void onKey(const KeyEvent& event)        { keyboard.onKey(event); }
  bool isKeyDown(int key) const            { return keyboard.isKeyDown(key);    }
  bool isKeyPressed(int key) const         { return keyboard.isKeyPressed(key); }
  std::vector<KeyEvent> consumeKeyEvents() { return keyboard.consumeKeyEvents(); }

  inline void updateMousePosition(GLFWwindow* window) { mouse.updateMousePosition(window); }

  void onButton(const MouseButtonEvent event) { mouse.onButton(event); }
  bool isButtonDown(const int button) const           { return mouse.isButtonDown(button); }
  bool isButtonPressed(const int button) const        { return mouse.isButtonPressed(button);}
  std::vector<MouseButtonEvent> consumeButtonEvents() { return mouse.consumeButtonEvents(); }

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