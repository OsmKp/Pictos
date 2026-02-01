#pragma once

#include "Pictos/Core/Event.h"

namespace Pictos
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)

			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}