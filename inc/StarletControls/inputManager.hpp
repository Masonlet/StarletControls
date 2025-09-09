#pragma once 

struct GLFWwindow;
#include "StarletMath/vec2.hpp"
#include <cstdint> 
#include <array> 
#include <vector>

struct KeyEvent {
  int key;
  int action;
  int mods;
};

class InputManager {
public:
  void clear();
  void update(GLFWwindow* window);

  static constexpr int keyCount() { return 349; }
  bool isKeyDown(int key) const;
  bool isKeyPressed(int key) const;
  void onKey(int key, int action, int mods);
  void onScroll(double xoffset, double yoffset);

  std::vector<KeyEvent> consumeKeyEvents();
  double consumeScrollX();
  double consumeScrollY();

  inline Vec2<double> getMouseDelta() const { return mouseDelta; }

  void setCursorLocked(bool locked);
  inline bool isCursorLocked() const { return cursorLocked; }

private:
  static constexpr int KEY_MAX = 349; // GLFW_KEY_LAST + 1
  static bool validKey(int key) { return key >= 0 && key < KEY_MAX; }

  std::vector<KeyEvent> keyEvents;
  std::array<bool, KEY_MAX> keyDown{};
  std::array<bool, KEY_MAX> keyLast{};

  Vec2<double> mouseDelta{ 0.0, 0.0 };
  Vec2<double> scrollDelta{ 0.0, 0.0 };
  Vec2<double> lastMousePos{ 0.0, 0.0 };
  bool firstMouse{ true }, cursorLocked{ true };
};