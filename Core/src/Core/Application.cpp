#include "Pictos/Core/Application.h"
#include "Pictos/Core/Events/WindowEvents.h"

#include "Pictos/Core/Log.h"

#include <SDL2/SDL.h>

#include <iostream>

namespace Pictos
{
	Application* Application::s_Instance = nullptr;

	Application::Application(ApplicationSpecification appSpec)
		: m_Specification(appSpec)
	{
		if (s_Instance)
		{
			std::cerr << "Application already exists!" << std::endl;

		}

		s_Instance = this;

		// create window here later

		if (m_Specification.WindowSpec.Title.empty())
			m_Specification.WindowSpec.Title = m_Specification.Name;

		m_Specification.WindowSpec.EventCallback = [this](Event& event) {OnEvent(event);  };

		m_Window = std::make_shared<Window>(m_Specification.WindowSpec);
		m_Window->Create();

	}

	Application::~Application()
	{
		m_Window->Destroy();
		s_Instance = nullptr;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->Update();

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
		dispatcher.Dispatch<WindowClosedEvent>(
			[this](WindowClosedEvent& e) {return OnWindowClose(e); }
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

	bool Application::OnWindowClose(WindowClosedEvent&)
	{
		m_Running = false;
		return true;
	}

	Application& Application::Get()
	{
		assert(s_Instance);
		return *s_Instance;
	}

}