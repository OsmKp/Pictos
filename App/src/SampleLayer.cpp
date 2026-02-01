#include "Core.h"

#include "SampleLayer.h"

#include <iostream>

SampleLayer::SampleLayer()
	: Layer("SampleLayer")
{
}

void SampleLayer::OnUpdate(float dt)
{
	std::cout << "SampleLayer Update: " << dt << " seconds" << std::endl;
}

void SampleLayer::OnRender()
{
	std::cout << "SampleLayer Render" << std::endl;
}

void SampleLayer::OnAttach()
{
	std::cout << "SampleLayer Attached" << std::endl;
}

void SampleLayer::OnDetach()
{
	std::cout << "SampleLayer Detached" << std::endl;
}

void SampleLayer::OnEvent(Pictos::Event& event)
{
	std::cout << "SampleLayer Event: " << event.ToString() << std::endl;
}