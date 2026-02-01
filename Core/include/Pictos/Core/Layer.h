#pragma once

#include <string>
#include "Event.h"

namespace Pictos
{
	class Layer
	{
	public:
		explicit Layer(const std::string& name = "Layer");

		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}

		virtual void OnUpdate(float dt) {}
		virtual void OnRender() {}

		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}