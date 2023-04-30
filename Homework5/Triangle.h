#pragma once
#include "../Homework2/v3.h"
#include <cmath>
const float epsilon = 0.00001F;
class Ray {
public:
	v3 Origin;
	v3 Dir;
	Ray(const v3& origin, const v3& dir) : Origin(origin), Dir(dir) { Dir.normalize(); }
};
class Triangle {
public:
	v3 v0;
	v3 v1;
	v3 v2;

	Triangle(const v3& v0, const v3& v1, const v3& v2) : v0(v0), v1(v1), v2(v2) {}
	v3 getNormal() {
		v3 normal = (v1 - v0).crossProduct(v2 - v0);
		normal.normalize();
		return normal;
	};
	bool intersection(const Ray& ray) {
		v3 normal = getNormal();
		if (std::abs(normal.dotProduct(ray.Dir)) > epsilon) {
			if ((v0 - ray.Origin).dotProduct(normal) < -epsilon) {
				float rpDist = (ray.Origin - v0).dotProduct(normal);
				float f = ((v3)ray.Dir).dotProduct(normal);
				float rProj = std::abs(f);
				float t = rpDist / rProj;
				v3 p = ray.Dir * t;
				bool test1 = normal.dotProduct((v1 - v0).crossProduct(p - v0)) > 0.0F;
				bool test2 = normal.dotProduct((v2 - v1).crossProduct(p - v1)) > 0.0F;
				bool test3 = normal.dotProduct((v0 - v2).crossProduct(p - v2)) > 0.0F;
				return test1 && test2 && test3;
			}
		}
		return false;
	}
};

struct color {
	int red;
	int blue;
	int green;
};