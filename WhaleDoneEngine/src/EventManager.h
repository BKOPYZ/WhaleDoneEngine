#pragma once

#include <SDL2/SDL.h>
#include "Event.h"
#include <unordered_map>
#include <vector>

namespace wd{

  class EventHandler {
    public:
        using EventCallBackFn = std::function<void(SDL_Event const&)>;
        void RegisterEvent(SDL_EventType type, EventCallBackFn callback) {
          _registeredCallbacks[type].push_back(callback);
        }

        void HandleEvents() {
          SDL_Event event;
          while (SDL_PollEvent(&event) != 0) {
            for (auto& cb : _registeredCallbacks[static_cast<SDL_EventType>(event.type)]) {
              cb(event);
            }
          }
        }
      private:
        std::unordered_map<SDL_EventType, std::vector<EventCallBackFn>> _registeredCallbacks;


  };
}