#pragma once
#include "../Project/Vector3.h"

namespace CRT {
	enum class MaterialType {
		Diffuse,
		Reflective
	};

	class Material {
	public:
		Material() {
			m_Type = MaterialType::Diffuse;
			m_Albedo = CRT::Color(0, 0, 0);
			m_ShouldUseSmoothShading = false;
		}
		Material(MaterialType& type, CRT::Color& color, bool smoothShading) : m_Type(type), m_Albedo(color), m_ShouldUseSmoothShading(smoothShading) {}
		CRT::Color GetColor();
		MaterialType GetMaterialType();
		bool GetSmoothShading();
	private:
		MaterialType m_Type;
		CRT::Color m_Albedo;
		bool m_ShouldUseSmoothShading;
	};

}