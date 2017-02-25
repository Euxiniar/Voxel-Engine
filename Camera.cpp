#include "Camera.h"

#include <cmath>

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "Display.h"

void Camera::input(float dt)
{
	Vector3 change;
	float speed = 3;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		change.x -= cos(glm::radians(rotation.y + 90)) * speed;
		change.z -= sin(glm::radians(rotation.y + 90)) * speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		change.x += cos(glm::radians(rotation.y + 90)) * speed;
		change.z += sin(glm::radians(rotation.y + 90)) * speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		change.x -= cos(glm::radians(rotation.y)) * speed;
		change.z -= sin(glm::radians(rotation.y)) * speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		change.x += cos(glm::radians(rotation.y)) * speed;
		change.z += sin(glm::radians(rotation.y)) * speed;
	}

	position += change * dt;
	float dtMouse = 0.3f;
	mouseInput(dtMouse);
}


void Camera::mouseInput(float dtMouse)
{
	static sf::Vector2i lastMousePosition;

	auto mouseChange = sf::Mouse::getPosition() - lastMousePosition;

	rotation.y += mouseChange.x * dtMouse;
	rotation.x += mouseChange.y * dtMouse;

	if (rotation.x > 80)
	{
		rotation.x = 80;
	}
	else if (rotation.x < -80)
	{
		rotation.x = -80;
	}
	if (rotation.y < 0)
	{
		rotation.y = 360;
	}
	else if (rotation.y > 360)
	{
		rotation.y = 0;
	}

	auto centerX = Display::WIDTH / 2;
	auto centerY = Display::HEIGHT / 2;

	sf::Mouse::setPosition(sf::Vector2i{ centerX, centerY }, Display::get());

	lastMousePosition = sf::Mouse::getPosition();
}
