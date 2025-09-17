#pragma once

#include "controller.hpp"
struct Model;

struct ModelController : public Controller<Model> {
	void update(Model& data, const InputManager& input, float deltaTime) override;
};