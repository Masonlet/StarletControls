#pragma once 

struct GLFWwindow;
#include "starletmath/vec2.hpp"

class InputManager {
public:
  void update(GLFWwindow* window);
    
  bool isKeyDown(int key) const;
  bool isKeyPressed(int key) const;

  inline Vec2 getMouseDelta() const { return mouseDelta;  }

  void setCursorLocked(bool locked);
  inline bool isCursorLocked() const { return cursorLocked; }

private:
  static constexpr  int TRACKED_KEY_COUNT{ 20 };
  static const int trackedKeys[TRACKED_KEY_COUNT];

  bool keyState[TRACKED_KEY_COUNT]{false};
  bool previousKeyState[TRACKED_KEY_COUNT]{false};

  Vec2 mouseDelta{ 0.0f, 0.0f };
  double lastMouseX{ 0.0 }, lastMouseY{ 0.0 };
  bool firstMouse{ true }, cursorLocked{ true };
};