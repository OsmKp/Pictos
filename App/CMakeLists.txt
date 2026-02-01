add_executable(App
	"src/App.cpp"
	"src/SampleLayer.cpp"
)

target_link_libraries(App PRIVATE Core)