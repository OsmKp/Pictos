#pragma once

#include "Event.h"

#include <glm/glm.hpp>

#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

#include <string>

#include <functional>

namespace Pictos
{
	struct WindowSpecification
	{
		std::string Title;
		uint32_t Width = 1280;
		uint32_t Height = 720;

		bool IsResizable = true;
		bool VSync = true;

		using EventCallbackFn = std::function<void(Event&)>;
		EventCallbackFn EventCallback;
	};

	class Window
	{
	public:
		Window(const WindowSpecification& props = WindowSpecification());
		~Window();

		void Create();
		void Destroy();

		void Update();

		void RaiseEvent(Event& event);

		glm::vec2 GetFramebufferSize() const;
		glm::vec2 GetMousePos() const;

		SDL_Window* GetHandle() const { return m_Handle; }
	private:
		void ProcessSDLEvent(const SDL_Event& event);

	private:
		SDL_Window* m_Handle;
		WindowSpecification m_Specification;

	};
}
