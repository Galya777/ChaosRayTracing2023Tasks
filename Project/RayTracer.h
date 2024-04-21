#pragma once

#include "Ray.h"
#include "../Homework5/Triangle.h"
#include "HitInformation.h"
#include "../Homework8/Scene.h"

namespace CRT {
	class RayTracer {
	public:
		RayTracer(std::shared_ptr<Scene> scene) : m_Scene(scene) {}
		void Render();
		CRT::Color CalculateColor(CRT::Ray& ray, int depth);
		bool HasRayIntersection(CRT::Ray& ray, CRT::HitInformation& hitInfo);
	private:
		std::shared_ptr<Scene> m_Scene;
	};
}