#include "Pictos/Core/Window.h"

#include <SDL2/SDL.h>

#include "Pictos/Core/Events/WindowEvents.h"
#include "Pictos/Core/Events/InputEvents.h"

#include <iostream>
#include <assert.h>

namespace Pictos
{
	Window::Window(const WindowSpecification& spec)
		: m_Specification(spec)
	{
	}

	Window::~Window()
	{
		Destroy();
	}

	void Window::Create()
	{
		SDL_Init(SDL_INIT_VIDEO); // auto inits event subsystem as well

		m_Handle  = SDL_CreateWindow(
			m_Specification.Title.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			m_Specification.Width,
			m_Specification.Height,
			SDL_WINDOW_SHOWN | (m_Specification.IsResizable ? SDL_WINDOW_RESIZABLE : 0) | SDL_WINDOW_VULKAN
		);

		if (!m_Handle)
		{
			std::cerr << "Failed to create SDL Window: " << SDL_GetError() << std::endl;
			assert(false);
		}

	}

	void Window::Destroy()
	{
		if (m_Handle)
		{
			SDL_DestroyWindow(m_Handle);
			m_Handle = nullptr;
		}
		SDL_Quit();
	}

	void Window::Update()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			ProcessSDLEvent(event);
		}
	}

	void Window::RaiseEvent(Event& event)
	{
		if (m_Specification.EventCallback)
			m_Specification.EventCallback(event);
	}

	void Window::ProcessSDLEvent(const SDL_Event& sdlEvent)
	{
		// Process individual SDL events here
		Event* e = nullptr;
		switch (sdlEvent.type)
		{
			case SDL_QUIT:
			case SDL_WINDOWEVENT:
				if (sdlEvent.window.event == SDL_WINDOWEVENT_CLOSE)
				{
					e = new WindowClosedEvent();
					break;
				}
				else if (sdlEvent.window.event == SDL_WINDOWEVENT_RESIZED)
				{
					e = new WindowResizeEvent(sdlEvent.window.data1, sdlEvent.window.data2);
					break;
				}
				break;
			case SDL_KEYDOWN:
				e = new KeyPressedEvent(sdlEvent.key.keysym.scancode, sdlEvent.key.repeat != 0);
				break;
			case SDL_KEYUP:
				e = new KeyReleasedEvent(sdlEvent.key.keysym.scancode);
				break;
			case SDL_MOUSEBUTTONDOWN:
				e = new MouseButtonPressedEvent(sdlEvent.button.button);
				break;
			case SDL_MOUSEBUTTONUP:
				e = new MouseButtonReleasedEvent(sdlEvent.button.button);
				break;
			case SDL_MOUSEMOTION:
				e = new MouseMovedEvent(sdlEvent.motion.xrel, sdlEvent.motion.yrel);
				break;
			case SDL_MOUSEWHEEL:
				e = new MouseScrolledEvent(sdlEvent.wheel.x, sdlEvent.wheel.y);
				break;
			default:
				return;
		}

		if (e)
		{
			m_Specification.EventCallback(*e);
			delete e;
		}
	}


}