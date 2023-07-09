#pragma once
#include <vector>
#include "../Homework2/v3.h"

struct TriangleIdxes {
	int v0;
	int v1;
	int v2;
	TriangleIdxes(int v0, int v1, int v2) : v0(v0), v1(v1), v2(v2) {}
};
class Objects
{
public:
	std::vector<my_v3> vertices;
	std::vector<TriangleIdxes> indicies;
};

