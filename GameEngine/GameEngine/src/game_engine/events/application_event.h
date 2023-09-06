/**
 * @file application_event.h
 * @brief Handles the logic behind the application events
 * @author Carlos Salguero
 * @date 2023-09-05
 * @version 1.0
 * 
 * @copyright Copyright (c) - MIT License
 * 
 */

#pragma once

// C++ Standard Library
#include <sstream>

// Project Files
#include "event.h"

namespace GameEngine
{
	/** 
	 * @class WindowResizeEvent
	 * @flag GE_API
	 * @inherits Event
	 * @brief Handles the logic behind the window resize event
	 */
	class GE_API WindowResizeEvent : public Event
	{
	public:
		// Constructor
		WindowResizeEvent(unsigned int width, unsigned int height) 
			: m_width(width), m_height(height) {}

		// Access Methods
		/**
		 * @brief
		 * Returns the width of the window.
		 * @return unsigned int with the width of the window.
		 */
		inline unsigned int get_width() const { return m_width; }

		/**
		 * @brief
		 * Returns the height of the window.
		 * @return unsigned int with the height of the window.
		 */
		inline unsigned int get_height() const { return m_height; }

		// Methods
		/**
		 * @brief 
		 * Returns a string representation of the event.
		 * @return std::string with the event information.
		 */
		std::string to_string() const override
		{
			std::stringstream ss;

			ss << "WindowResizeEvent: " << m_width << ", " << m_height;
			return ss.str();
		}

		// Event Categories
		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	private:
		unsigned int m_width;
		unsigned int m_height;
	};

	/**
	 * @class WindowCloseEvent 
	 * @flag GE_API
	 * @inherits Event
	 * @brief Handles the logic behind the window close event
	 */
	class GE_API WindowCloseEvent : public Event
	{
	public:
		// Constructor
		WindowCloseEvent() {}

		// Event Categories
		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	/**
	 * @class AppTickEvent
	 * @flag GE_API
	 * @inherits Event
	 * @brief Handles the logic behind the application tick event
	 */
	class GE_API AppTickEvent : public Event
	{
	public:
		// Constructor
		AppTickEvent() {}

		// Event Categories
		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	/**
	 * @class AppUpdateEvent
	 * @flag GE_API
	 * @inherits Event
	 * @brief Handles the logic behind the application update event
	 */
	class GE_API AppUpdateEvent : public Event
	{
	public:
		// Constructor
		AppUpdateEvent() {}

		// Event Categories
		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	/**
	 * @class AppRenderEvent
	 * @flag GE_API
	 * @inherits Event
	 * @brief Handles the logic behind the application render event
	 */
	class GE_API AppRenderEvent : public Event
	{
	public:
		// Constructor
		AppRenderEvent() {}

		// Event Categories
		EVENT_CLASS_TYPE(AppRender);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};
} // namespace GameEngine