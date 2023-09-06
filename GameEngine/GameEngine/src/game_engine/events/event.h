/**
 * @file event.h
 * @brief Handles the logic behind the events
 * @author Carlos Salguero
 * @date 2023-09-05
 * @version 1.0
 *  
 * @copyright Copyright (c) - MIT License
 * 
 */

#pragma once

// C++ Standard Library
#include <string>
#include <functional>

// Project Files
#include "../core/preprocessor/preprocessor.h"

/**
 * @brief
 * Events in Lucca Game Engine are currently blocking, meaning when an
 * event occurs it immediately gets dispatched and must be dealt with
 * right then an there.
 * @todo In the future, a better strategy might be to buffer events in an
 */
namespace GameEngine
{
	/**
	 * @enum class EventType
	 * @brief Defines the type of event.
	 * @details Contains the following categories of events:
	 *          Window Events, Application Events, Keyboard Events, Mouse Events.
	 */
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,	
		AppTick, AppUpdate, AppRender,											
		KeyPressed, KeyReleased, KeyTyped,										
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled		
	};

	/**
	 * @enum EventCategory
	 * @brief Defines the category of event.
	 * @details Bit corresponding to the category of event.
	 *          EventCategoryApplication is 0b00001
	 *          EventCategoryInput is 0b00010
	 *          EventCategoryKeyboard is 0b00100
	 *          EventCategoryMouse is 0b01000
	 *          EventCategoryMouseButton is 0b10000
	 */
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	// Macros to define the event type and category
	/**
	 * @def EVENT_CLASS_TYPE(type)
	 * @brief Defines the type of event.
	 * @details Defines the type of event as a static function.
	 * @param type Type of event
	 * @return EventType Type of event
	 * @return const char* Name of the event
	 */
	#define EVENT_CLASS_TYPE(type) static EventType static_type() { return EventType::##type; } \
					virtual EventType get_event_type() const override { return static_type(); } \
					virtual const char *get_name() const override { return #type; }

	/**
	 * @def EVENT_CLASS_CATEGORY(category)
	 * @brief Defines the category of event.
	 * @details Defines the category of event as virtual function.
	 * @param category Category of the event.
	 * @return int Category of the event.
	 */
	#define EVENT_CLASS_CATEGORY(category) virtual int get_category_flags() const override { return category; }

	// Class
	/**
	 * @class Event
	 * @flag GE_API
	 * @brief Defines the event.
	 */
	class GE_API Event
	{
	public:
		// Virtual methods
		virtual EventType get_event_type() const = 0;
		virtual const char *get_name() const = 0;
		virtual int get_category_flags() const = 0;
		virtual std::string to_string() const { return get_name(); }

		// Inline methods
		/**
		 * @brief
		 * Checks if the event corresponds to a certain category.
		 * @param category Category of the event.
		 * @return true If the event corresponds to the category.
		 * @return false If the event does not correspond to the category
		 */
		inline bool is_in_category(EventCategory category)
		{
			return get_category_flags() & category;
		}

	protected:
		bool m_handled = false;		

	private:
		friend class EventDispatcher;
	};

	/**
     * @class EventDispatcher
	 * @brief Dispatches the event.
	 */
	class EventDispatcher
	{};
}