#pragma once
#include "../Homework2/v3.h"
#include <cmath>
const float epsilon = 0.00001F;
class Ray {
public:
	my_v3 Origin;
	my_v3 Dir;
	Ray(const my_v3& origin, const my_v3& dir) : Origin(origin), Dir(dir) { Dir.normalize(); }
};
class Triangle {
public:
	my_v3 v0;
	my_v3 v1;
	my_v3 v2;

	Triangle(const my_v3& v0, const my_v3& v1, const my_v3& v2) : v0(v0), v1(v1), v2(v2) {}
	my_v3 getNormal() {
		my_v3 normal = (v1 - v0).crossProduct(v2 - v0);
		normal.normalize();
		return normal;
	};
	bool intersection(const Ray& ray) {
		my_v3 normal = getNormal();
		if (std::abs(normal.dotProduct(ray.Dir)) > epsilon) {
			if ((v0 - ray.Origin).dotProduct(normal) < -epsilon) {
				float rpDist = (ray.Origin - v0).dotProduct(normal);
				float f = ((my_v3)ray.Dir).dotProduct(normal);
				float rProj = std::abs(f);
				float t = rpDist / rProj;
				my_v3 p = ray.Origin + ray.Dir * t;
				bool test1 = normal.dotProduct((v1 - v0).crossProduct(p - v0)) > 0.0F;
				bool test2 = normal.dotProduct((v2 - v1).crossProduct(p - v1)) > 0.0F;
				bool test3 = normal.dotProduct((v0 - v2).crossProduct(p - v2)) > 0.0F;
				return test1 && test2 && test3;
			}
		}
		return false;
	}
	bool intersection(const Ray& ray, float& distance) {
		my_v3 normal = getNormal();
		if (std::abs(normal.dotProduct(ray.Dir)) > epsilon) {
			if ((v0 - ray.Origin).dotProduct(normal) < -epsilon) {
				float rpDist = (ray.Origin - v0).dotProduct(normal);
				float rProj = std::abs(((my_v3)ray.Dir).dotProduct(normal));
				float t = rpDist / rProj;
				my_v3 p = ray.Dir * t + ray.Origin;
				bool test1 = normal.dotProduct((v1 - v0).crossProduct(p - v0)) > 0.0F;
				bool test2 = normal.dotProduct((v2 - v1).crossProduct(p - v1)) > 0.0F;
				bool test3 = normal.dotProduct((v0 - v2).crossProduct(p - v2)) > 0.0F;
				distance = t;
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