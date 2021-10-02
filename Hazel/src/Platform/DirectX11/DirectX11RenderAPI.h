﻿#pragma once

#include "Hazel/Renderer/RendererAPI.h"

namespace Hazel {
	class DirectX11RenderAPI:public RendererAPI
	{
	public:
		virtual void Init() override;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const Ref<Hazel::VertexArray>& vertexArray, uint32_t indexCount = 0) override;
	};
}
