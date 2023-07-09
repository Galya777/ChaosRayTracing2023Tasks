#pragma once
#include <math.h>
class my_v3
{
public:
	my_v3() : x(0.0), y(0.0), z(0.0) {}
	my_v3(float x, float y, float z) : x(x), y(y), z(z) {}
	float get_x() const{return x;};
	float get_y() const{return y;};
	float get_z() const{return z;};
	float dotProduct(const my_v3& v0) { return x * v0.x + y * v0.y + z * v0.z; }
	my_v3 crossProduct(const my_v3& v0) { return my_v3(y * v0.z - z * v0.y, z * v0.x - x * v0.z, x * v0.y - y * v0.x); }
	my_v3 operator- (const my_v3& v0) { return my_v3(x - v0.x, y - v0.y, z - v0.z); }
	my_v3 operator+ (const my_v3& v0) { return my_v3(x + v0.x, y + v0.y, z + v0.z); }
	my_v3 operator- (const my_v3& v0) const { return my_v3(x - v0.x, y - v0.y, z - v0.z); }
	my_v3 operator+ (const my_v3& v0) const { return my_v3(x + v0.x, y + v0.y, z + v0.z); }
	my_v3 operator* (float s) const { return my_v3(x * s, y * s, z * s); }
	float len() const { return sqrt(x * x + y * y + z * z); }
	my_v3& normalize() {
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
	
	
	

