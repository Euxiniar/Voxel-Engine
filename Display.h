#pragma once

namespace sf
{
	class Window;
}

namespace Display
{
	constexpr static int WIDTH = 1280;
	constexpr static int HEIGHT = 720;

	void init();
	void close();
	void clear();
	void update();

	void CheckForClose();
	bool isOpen();

	const sf::Window& get();
}