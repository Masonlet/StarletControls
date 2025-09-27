#pragma once 

#include "keyboardManager.hpp"
#include "mouseManager.hpp"

struct GLFWwindow;

class InputManager {
public:
  void reset();

  void onKey(const KeyEvent& event);
  bool isKeyDown(const int key) const;
  bool isKeyPressed(const int key) const;
  std::vector<KeyEvent> consumeKeyEvents();

  void setCursorLocked(const bool locked);
  bool isCursorLocked() const;
  Vec2<double> getMouseDelta() const;
  void updateMousePosition(GLFWwindow* window);

  void onButton(const MouseButtonEvent& event);
  bool isButtonDown(const int button) const;
  bool isButtonPressed(const int button) const;
  std::vector<MouseButtonEvent> consumeButtonEvents();

  void onScroll(const double xOffset, const double yOffset);
  double consumeScrollX();
  double consumeScrollY();

private:
  KeyboardManager keyboard;
  MouseManager mouse;
};