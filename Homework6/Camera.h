#pragma once
#include "../Homework2/v3.h"
#include <corecrt_math_defines.h>
class trasposeMatrix {
public:
	trasposeMatrix() {
		for (int i = 0; i < 9; ++i) {
			a[i] = 0.0F;
		}
	}
	trasposeMatrix(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8) {
		a[0] = a0;
		a[1] = a1;
		a[2] = a2;
		a[3] = a3;
		a[4] = a4;
		a[5] = a5;
		a[6] = a6;
		a[7] = a7;
		a[8] = a8;
	}
	v3 operator*(const v3& v) const {
		return v3(
			a[0] * v.get_x() + a[1] * v.get_y() + a[2] * v.get_z(),
			a[3] * v.get_x() + a[4] * v.get_y() + a[5] * v.get_z(),
			a[6] * v.get_x() + a[7] * v.get_y() + a[8] * v.get_z());
	}
	trasposeMatrix operator*(const trasposeMatrix& m) const {
		v3 row0(a[0], a[1], a[2]);
		v3 row1(a[3], a[4], a[5]);
		v3 row2(a[6], a[7], a[8]);
		v3 col0(m.a[0], m.a[3], m.a[6]);
		v3 col1(m.a[1], m.a[4], m.a[7]);
		v3 col2(m.a[2], m.a[5], m.a[8]);
		return trasposeMatrix(row0.dotProduct(col0), row0.dotProduct(col1), row0.dotProduct(col2),
			row1.dotProduct(col0), row1.dotProduct(col1), row1.dotProduct(col2),
			row2.dotProduct(col0), row2.dotProduct(col1), row2.dotProduct(col2));
	}
	trasposeMatrix Transpose() {
		return trasposeMatrix(a[0], a[3], a[6], a[1], a[4], a[7], a[2], a[5], a[8]);
	}
	float a[9];
};
class Camera {
public:
	Camera() {
		orient.a[0] = 1.0F;
		orient.a[4] = 1.0F;
		orient.a[8] = 1.0F;
	}
	trasposeMatrix orient;
	v3 origin;
	void dolly(float distance) {
		v3 fwdVec = v3(-orient.a[2], -orient.a[5], -orient.a[8]);
		origin = origin + fwdVec.normalize() * distance;
	}
	void truck(float distance) {
		v3 rightVec = v3(orient.a[0], orient.a[3], orient.a[6]);
		origin = origin + rightVec.normalize() * distance;
	}
	void pedestal(float distance) {
		v3 upVec = v3(orient.a[1], orient.a[4], orient.a[7]);
		origin = origin + upVec.normalize() * distance;
	}
	void pan(float angle) {
		float cos = cosf(angle * M_PI / 180.0F);
		float sin = sinf(angle * M_PI / 180.0F);
		trasposeMatrix rotation(cos, 0.0F, sin, 0.0F, 1.0F, 0.0F, -sin, 0.0F, cos);
		orient = rotation * orient;
	}
};

