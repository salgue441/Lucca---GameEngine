/**
 * @file key_event.h
 * @brief Handles the logic behind the key events
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
	 * @class KeyEvent
	 * @flag GE_API
	 * @inherits Event
	 * @brief Handles the logic behind the key events
	 */
	class GE_API KeyEvent : public Event
	{
	public:
		// Access Methods
		/**
		 * @brief 
		 * Retrieves the keycode of the key pressed.
		 * @return int with the keycode of the key pressed.
		 */
		inline int get_keycode() const { return m_keycode; }

		// Event Categories
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keycode) : m_keycode(keycode) {}

		int m_keycode;
	};

	/**
	 * @class KeyPressedEvent
	 * @flag GE_API
	 * @inherits KeyEvent
	 * @brief Handles the logic behind the key pressed event
	 */
	class GE_API KeyPressedEvent : public KeyEvent
	{
	public:
		// Constructor
		KeyPressedEvent(int keycode, int repeated_count)
			: KeyEvent(keycode), m_repeat_count(repeated_count) {}

		// Access Methods
		/**
		 * @brief
		 * Retrieves the number of times the key was pressed.
		 * @return int with the number of times the key was pressed
		 */
		inline int get_repeat_count() const { return m_repeat_count; }

		// Methods
		/**
		 * @brief 
		 * Returns a string representation of the event.
		 * @return std::string with the event information.
		 */
		std::string to_string() const override
		{
			std::stringstream ss;

			ss << "KeyPressedEvent: " << m_keycode << " (" << m_repeat_count << " repeats)";
			return ss.str();
		}

		// Event Categories
		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_repeat_count;
	};

	/** 
	 * @class KeyReleasedEvent
	 * @flag GE_API
	 * @inherits KeyEvent
	 * @brief Handles the logic behind the key released event
	 */
	class GE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		// Constructor
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		// Methods
		/**
		 * @brief
		 * Returns a string representation of the event.
		 * @return std::string with the event information.
		 */
		std::string to_string() const override
		{
			std::stringstream ss;

			ss << "KeyReleasedEvent: " << m_keycode;
			return ss.str();
		}

		// Event Categories
		EVENT_CLASS_TYPE(KeyReleased)
	};
} // namespace GameEngine