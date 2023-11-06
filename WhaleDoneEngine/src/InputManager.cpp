#include "../wdpch.h"
//---------------------------------------------------------------
#include "InputManager.h"
//---------------------------------------------------------------
// QuickSDL
//---------------------------------------------------------------
namespace wd {
	//Initializing to NULL
	InputManager* InputManager::s_Instance = nullptr;

	InputManager* InputManager::GetInstance() {
		//Create a new instance if no instance was created before
		if(s_Instance == nullptr)
			s_Instance = new InputManager();

		return s_Instance;
	}

	void InputManager::Release() {

		delete s_Instance;
		s_Instance = NULL;
	}

	InputManager::InputManager() {

		m_KeyboardState = SDL_GetKeyboardState(&m_KeyLength);
		//Setting mPrevKeyboardState to be the same length as mKeyboardState
		m_PrevKeyboardState = new Uint8[m_KeyLength];
		//Copying the contents of mKeyboardState into mPrevKeyboardState so that it contains data on the first frame
		memcpy(m_PrevKeyboardState, m_KeyboardState, m_KeyLength);
	}

	InputManager::~InputManager() {

		//Clearing the previous keyboard state array
		delete[] m_PrevKeyboardState;
		m_PrevKeyboardState = NULL;
	}

	bool InputManager::KeyDown(SDL_Scancode scanCode) {

		return (m_KeyboardState[scanCode] != 0);
	}

	bool InputManager::KeyPressed(SDL_Scancode scanCode) {

		//returning true of the key was not pressed in the previous keyboard state but is pressed in the current one
		return (m_PrevKeyboardState[scanCode]) == 0 && (m_KeyboardState[scanCode] != 0);
	}

	bool InputManager::KeyReleased(SDL_Scancode scanCode) {

		//returning true of the key was pressed in the previous keyboard state but is not pressed in the current one
		return (m_PrevKeyboardState[scanCode] != 0) && (m_KeyboardState[scanCode] == 0);
	}

	Vector2 InputManager::MousePos() {

		//Converting the mouse position into a Vector2 for ease of use since all entities use Vector2
		return Vector2((float)m_MouseXPos, (float)m_MouseYPos);
	}

	bool InputManager::MouseButtonDown(MOUSE_BUTTON button) {

		//mask to be using for bit wise operations
		Uint32 mask = 0;

		switch(button) {

		case left:

			mask = SDL_BUTTON_LMASK;
			break;

		case right:

			mask = SDL_BUTTON_RMASK;
			break;

		case middle:

			mask = SDL_BUTTON_MMASK;
			break;

		case back:

			mask = SDL_BUTTON_X1MASK;
			break;

		case forward:

			mask = SDL_BUTTON_X2MASK;
			break;
		}

		//return true if the mask exists in the current mouse state
		return ((m_MouseState & mask) != 0);
	}

	bool InputManager::MouseButtonPressed(MOUSE_BUTTON button) {

		//mask to be using for bit wise operations
		Uint32 mask = 0;

		switch(button) {

		case left:

			mask = SDL_BUTTON_LMASK;
			break;

		case right:

			mask = SDL_BUTTON_RMASK;
			break;

		case middle:

			mask = SDL_BUTTON_MMASK;
			break;

		case back:

			mask = SDL_BUTTON_X1MASK;
			break;

		case forward:

			mask = SDL_BUTTON_X2MASK;
			break;
		}

		//return true if the mask does not exist in the previous mouse state, but exists in the current one
		return ((m_PrevMouseState & mask) == 0) && ((m_MouseState & mask) != 0);
	}

	bool InputManager::MouseButtonReleased(MOUSE_BUTTON button) {

		Uint32 mask = 0;

		switch(button) {

		case left:

			mask = SDL_BUTTON_LMASK;
			break;

		case right:

			mask = SDL_BUTTON_RMASK;
			break;

		case middle:

			mask = SDL_BUTTON_MMASK;
			break;

		case back:

			mask = SDL_BUTTON_X1MASK;
			break;

		case forward:

			mask = SDL_BUTTON_X2MASK;
			break;
		}

		//return true if the mask exists in the previous mouse state, but does not exist in the current one
		return ((m_PrevMouseState & mask) != 0) && ((m_MouseState & mask) == 0);
	}

	void InputManager::Update() {

		//Updating the mouse state to get the key states of the current frame
		m_MouseState = SDL_GetMouseState(&m_MouseXPos, &m_MouseYPos);
	}

	void InputManager::UpdatePrevInput() {

		//Copying the keyboard state into the previous keyboard state array at the end of the frame
		memcpy(m_PrevKeyboardState, m_KeyboardState, m_KeyLength);
		//Setting the previous mouse state as the current mouse state at the end of the frame
		m_PrevMouseState = m_MouseState;
	}
}