#pragma once
#include "Event.h"
#include <SDL2/SDL.h>
#include <sstream>
namespace wd{

    class KeyEvent: public Event{
        public:
            SDL_Scancode GetKeyCode() const { return m_Scancode;}

            EVENT_CLASS_CATEGORY(EventCategoryKeyBoard | EventCategoryInput)
        protected:
            KeyEvent(const SDL_Scancode scancode) :m_Scancode(scancode){}
            SDL_Scancode m_Scancode;
    };

    class KeyPressedEvent: public KeyEvent{
        public:
            KeyPressedEvent(const SDL_Scancode keycode, bool isRepeat = false)
                : KeyEvent(keycode), m_IsRepeat(isRepeat) {}

            bool IsRepeat() const { return m_IsRepeat; }

            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "KeyPressedEvent: " << m_Scancode << " (repeat = " << m_IsRepeat << ")";
                return ss.str();
            }

            EVENT_CLASS_TYPE(KeyPressed)
        private:
            bool m_IsRepeat;
    };

    class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const SDL_Scancode scancode)
			: KeyEvent(scancode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_Scancode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const SDL_Scancode scancode)
			: KeyEvent(scancode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_Scancode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}