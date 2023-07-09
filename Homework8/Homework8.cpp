﻿#include <iostream>
#include "../Homework7/Scene.h"
int main()
{
	Renderer renderer;
	SceneParser parser;

	//Problem 1
	Scene scene1;
	parser.parse("input/scene0.crtscene", scene1);
	renderer.render(scene1, "output/scene0.ppm");

	//Problem 2
	//Scene scene2;
	//parser.parse("input/scene1.crtscene", scene2);
	//renderer.render(scene2, "output/scene1.ppm");

	//Problem 3
	//Scene scene3;
	//parser.parse("input/scene2.crtscene", scene3);
	//renderer.render(scene3, "output/scene2.ppm");

	//Problem 4
	//Scene scene4;
	//parser.parse("input/scene3.crtscene", scene4);
	//renderer.render(scene4, "output/scene3.ppm");
	return 0;
}
