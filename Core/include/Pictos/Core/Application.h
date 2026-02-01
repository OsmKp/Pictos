#pragma once

#include "LayerStack.h"
#include "Event.h"

#include <glm/glm.hpp>

#include <string>
#include <memory>
#include <vector>
#include <set>
#include <functional>


namespace Pictos
{
	class Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		//glm::vec2 GetFramebufferSize() const;

		static Application& Get();

	private:
		bool OnWindowClose(class WindowCloseEvent& e);

		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;

	};
	
	// To be defined in CLIENT
	Application* CreateApplication();
}