#
# Dependencies
#
include(FetchContent)

# GLM (header-only)
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 1.0.1
)
FetchContent_MakeAvailable(glm)

# SDL2
FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-2.30.8  # Latest stable
)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)    # Static library
set(SDL_TEST OFF CACHE BOOL "" FORCE)      # No tests
set(SDL_STATIC ON CACHE BOOL "" FORCE)     # Enable static
FetchContent_MakeAvailable(SDL2)