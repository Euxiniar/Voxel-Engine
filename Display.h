#pragma once
#include <string>

namespace sf
{
	class Window;
}

namespace Display
{
	constexpr static int WIDTH = 1280;
	constexpr static int HEIGHT = 720;

	void create(std::string title);
	void close();
	void clear();
	void update();

	void CheckForClose();
	bool isOpen();
	bool isSelect();

	const sf::Window& get();
}