#pragma once

#include "Core.h"

class SampleLayer : public Pictos::Layer
{
public:
	SampleLayer();
	virtual ~SampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(float dt) override;
	void OnRender() override;
	void OnEvent(Pictos::Event& event) override;

};