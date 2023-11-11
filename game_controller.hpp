#pragma once

#include "lve_game_object.hpp"
#include "lve_window.hpp"

namespace lve {
class gameController {
 public:
  struct KeyMappings {
    int spaceBar = GLFW_KEY_SPACE;
  };

  void moveInPlaneXZ(GLFWwindow* window, float dt, LveGameObject& gameObject, LveGameObject& );

  KeyMappings keys{};
  float moveSpeed{2.5f};
  float lookSpeed{1.5f};
};
}  // namespace lve