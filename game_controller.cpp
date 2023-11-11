#include "game_controller.hpp"

// std
#include <limits>

namespace lve {

void gameController::moveInPlaneXZ(
    GLFWwindow* window, float dt, LveGameObject& gameObject, LveGameObject& bird) {
  
    
    
    if (glfwGetKey(window, keys.spaceBar) == GLFW_PRESS) {
        bird.transform.translation.y -= dt * 10.f;
        bird.transform.rotation.z = -1.f;
    }

  float yaw = gameObject.transform.rotation.y;
  const glm::vec3 forwardDir{sin(yaw), 0.f, cos(yaw)};
  const glm::vec3 rightDir{forwardDir.z, 0.f, -forwardDir.x};
 

  glm::vec3 moveDir{0.f};
  moveDir += rightDir;
  if (glm::dot(moveDir, moveDir) > std::numeric_limits<float>::epsilon()) {
    gameObject.transform.translation += moveSpeed * dt * glm::normalize(moveDir);
    bird.transform.translation += moveSpeed * dt * glm::normalize(moveDir);
    bird.transform.translation.y += 0.006f;
    if (bird.transform.rotation.z<.65f) {
    bird.transform.rotation.z += 0.0125f;

    }
  }
}
}  // namespace lve