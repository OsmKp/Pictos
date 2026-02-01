#include "Pictos/Core/Application.h"
#include "Pictos/Core/Events/ApplicationEvent.h"

#include "Pictos/Core/Log.h"

#include <SDL2/SDL.h>

#include <iostream>

namespace Pictos
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		if (s_Instance)
		{
			std::cerr << "Application already exists!" << std::endl;

		}

		s_Instance = this;

		// create window here later

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{

			// Update layers
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(0.016f);

			// Render layers (Vulkan later)
			for (Layer* layer : m_LayerStack)
				layer->OnRender();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(
			[this](WindowCloseEvent& e) {return OnWindowClose(e); }
		);

		// Propagate event to layers in reverse order (starting from top layer)
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent&)
	{
		m_Running = false;
		return true;
	}

	Application& Application::Get()
	{
		return *s_Instance;
	}

}