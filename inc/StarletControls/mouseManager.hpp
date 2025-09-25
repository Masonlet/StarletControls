#pragma once

#include "StarletMath/vec2.hpp"

struct GLFWwindow;

class MouseManager {
public:
  void update(GLFWwindow* window);

  void onScroll(const double xoffset, const double yoffset);

  double consumeScrollX();
  double consumeScrollY();

  inline Vec2<double> getMouseDelta() const { return mouseDelta; }

  void setCursorLocked(const bool locked);
  inline bool isCursorLocked() const { return cursorLocked; }

private:
  Vec2<double> mouseDelta{ 0.0, 0.0 };
  Vec2<double> scrollDelta{ 0.0, 0.0 };
  Vec2<double> lastMousePos{ 0.0, 0.0 };
  bool firstMouse{ true }, cursorLocked{ true };
};