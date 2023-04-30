#pragma once
#include <math.h>
class v3
{
public:
	v3() : x(0.0), y(0.0), z(0.0) {}
	v3(float x, float y, float z) : x(x), y(y), z(z) {}
	float get_x() const{return x;};
	float get_y() const{return y;};
	float get_z() const{return z;};
	float dotProduct(const v3& v0) { return x * v0.x + y * v0.y + z * v0.z; }
	v3 crossProduct(const v3& v0) { return v3(y * v0.z - z * v0.y, z * v0.x - x * v0.z, x * v0.y - y * v0.x); }
	v3 operator- (const v3& v0) { return v3(x - v0.x, y - v0.y, z - v0.z); }
	v3 operator+ (const v3& v0) { return v3(x + v0.x, y + v0.y, z + v0.z); }
	v3 operator- (const v3& v0) const { return v3(x - v0.x, y - v0.y, z - v0.z); }
	v3 operator+ (const v3& v0) const { return v3(x + v0.x, y + v0.y, z + v0.z); }
	v3 operator* (float s) const { return v3(x * s, y * s, z * s); }
	float len() const { return sqrt(x * x + y * y + z * z); }
	v3& normalize() {
		float length = 1.0F / len();
		x *= length;
		y *= length;
		z *= length;

		return *this;
	}
private:
	float x;
	float y;
	float z;
};

