add_library(Core STATIC
	"src/Core.cpp"
	"src/Core/Application.cpp"
	"src/Core/Log.cpp"
	"src/Core/Layer.cpp"
	"src/Core/LayerStack.cpp"
  )

target_include_directories(Core PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Core PUBLIC glm SDL2::SDL2main SDL2::SDL2)