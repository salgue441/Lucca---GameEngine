/**
 * @file mouse_events.h
 * @brief Handles the logic behind the mouse events
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
	 * @class MouseButtonEvent
	 * @flag GE_API
	 * @inherits Event
	 * @brief Handles the logic behind the mouse button event
	 */
	class GE_API MouseMovedEvent : public Event
	{
	public:
		// Constructor
		MouseMovedEvent(float x, float y)
			: m_mouse_x(x), m_mouse_y(y) {}

		// Access Methods
		/**
		 * @brief
		 * Returns the x position of the mouse.
		 * @return float with the x position of the mouse.
		 */
		inline float get_x() const { return m_mouse_x; }

		/**
		 * @brief
		 * Returns the y position of the mouse
		 * @return float with the y position of the mouse
		 */
		inline float get_y() const { return m_mouse_y; }

		// Methods
		/**
		 * @brief
		 * Returns a string representation of the event.
		 * @return std::string with the event information.
		 */
		std::string to_string() const override
		{
			std::stringstream ss;

			ss << "MouseMovedEvent: " << m_mouse_x << ", " << m_mouse_y;
			return ss.str();
		}

		// Event Macros
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_mouse_x, m_mouse_y;
	};

	/**
	 * @class MouseScrolledEvent 
	 * @flag GE_API
	 * @inherits Event
	 * @brief Handles the logic behind the mouse scroll event
	 */
	class GE_API MouseScrolledEvent : public Event
	{
	public:
		// Constructor
		MouseScrolledEvent(float x_offset, float y_offset)
			: m_x_offset(x_offset), m_y_offset(y_offset) {}

		// Access Methods
		/**
		 * @brief 
		 * Returns the x offset of the mouse.
		 * @return float with the x offset of the mouse.
		 */
		inline float get_x_offset() const { return m_x_offset; }

		/**
		 * @brief
		 * Returns the y offset of the mouse.
		 * @return float with the y offset of the mouse.
		 */
		inline float get_y_offset() const { return m_y_offset; }

		// Methods
		/**
		 * @brief
		 * Returns a string representation of the event.
		 * @return std::string with the event information.
		 */
		std::string to_string() const override
		{
			std::stringstream ss;

			ss << "MouseScrolledEvent: " << get_x_offset() << ", " << get_y_offset();
			return ss.str();
		}

		// Event Macros
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_x_offset, m_y_offset;
	};

	/**
	 * @class MouseButtonEvent 
	 * @flag GE_API
	 * @inherits Event
	 * @brief Handles the logic behind the mouse button event
	 */
	class GE_API MouseButtonEvent : public Event
	{
	public:
		// Access Methods
		/** 
		 * @brief
		 * Returns the mouse button code.
		 * @return int with the mouse button code.
		 */
		inline int get_mouse_button() const { return m_button; }

		// Event Macros
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		// Constructor
		MouseButtonEvent(int button)
			: m_button(button) {}

		int m_button;
	};

	/**
	 * @class MouseButtonPressedEvent 
	 * @flag GE_API
	 * @inherits MouseButtonEvent
	 * @brief Handles the logic behind the mouse pressed button event
	 */
	class GE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		// Constructor
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		// Methods
		/**
		 * @brief
		 * Returns a string representation of the event.
		 * @return std::string with the event information.
		 */
		std::string to_string() const override
		{
			std::stringstream ss;

			ss << "MouseButtonPressedEvent: " << m_button;
			return ss.str();
		}

		// Event Macros
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	/**
	 * @class MouseButtonReleasedEvent 
	 * @flag GE_API
	 * @inherits MouseButtonEvent
	 * @brief Handles the logic behind the mouse released button event
	 */
	class GE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		// Constructor
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		// Methods
		/**
		 * @brief
		 * Returns a string representation of the event.
         * @return std::string with the event information.
		 */
		std::string to_string() const override
		{
			std::stringstream ss;

			ss << "MouseButtonReleasedEvent: " << m_button;
			return ss.str();
		}

		// Event Macros
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

} // namespace GameEngine