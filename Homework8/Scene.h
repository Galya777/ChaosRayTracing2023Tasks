#pragma once
#include <vector>
#include "../Homework6/Camera.h"
#include "../Homework5/Triangle.h"
#include <string>
#include "../Homework7/Objects.h"
#include <cassert>
#include <iostream>
#include "rapidjson/document.h";
#include "rapidjson/istreamwrapper.h";
#include <fstream>
#include "Light.h"
	class Scene
	{
	public:
		std::vector<Objects> items;
		Camera camera;
		color bgc; // background color;
		int imageWidth;
		int imageHeight;
		std::string filename;
		const std::vector<Light>& getPointLights() const {
			return pointLights;
		}
		void ParseScene(const std::string& filename) {

			rapidjson::Document doc = getJsonDoc(filename);
			const rapidjson::Value& settingsVal = doc.FindMember("settings")->value;

			if (!settingsVal.IsNull() && settingsVal.IsObject()) {

				const rapidjson::Value& bg = settingsVal.FindMember("background_color")->value;
				assert(!bg.IsNull() && bg.IsArray());
				my_v3 bgColVec = loadVec(bg.GetArray());
				bgc.red = bgColVec.get_x() * 255;
				bgc.green = bgColVec.get_y() * 255;
				bgc.blue = bgColVec.get_z() * 255;

				


				const rapidjson::Value& imgSettings = settingsVal.FindMember("image_settings")->value;
				assert(!imgSettings.IsNull() && imgSettings.IsObject());
				const rapidjson::Value& width = imgSettings.FindMember("width")->value;
				const rapidjson::Value& height = imgSettings.FindMember("height")->value;
				assert(!width.IsNull() && width.IsInt() && !height.IsNull() && height.IsInt());
				imageWidth = width.GetInt();
				imageHeight = height.GetInt();
				const rapidjson::Value& cam = doc.FindMember("camera")->value;
				if (!cam.IsNull() && cam.IsObject()) {
					const rapidjson::Value& pos = cam.FindMember("position")->value;
					assert(!pos.IsNull() && pos.IsArray());
					camera.origin = loadVec(pos.GetArray());

					const rapidjson::Value& orient = cam.FindMember("matrix")->value;
					assert(!orient.IsNull() && orient.IsArray());
					camera.orient = loadMat(orient.GetArray());
				}
				const rapidjson::Value& obj = doc.FindMember("objects")->value;
				if (!obj.IsNull() && obj.IsArray()) {

					for (int i = 0; i < obj.Size(); i++) {
						const rapidjson::Value& vert = obj[i].FindMember("vertices")->value;
						assert(!vert.IsNull() && vert.IsArray());

						items.push_back(Objects());

						for (int j = 0; j < vert.GetArray().Size() / 3; j++) {
							items.back().vertices.emplace_back(
								vert.GetArray()[3 * j].GetFloat(),
								vert.GetArray()[3 * j + 1].GetFloat(),
								vert.GetArray()[3 * j + 2].GetFloat());
						}
						const rapidjson::Value& tri = obj[i].FindMember("triangles")->value;
						assert(!tri.IsNull() && tri.IsArray());
						for (int j = 0; j < tri.GetArray().Size() / 3; j++) {
							items.back().indicies.emplace_back(
								tri.GetArray()[3 * j].GetInt(),
								tri.GetArray()[3 * j + 1].GetInt(),
								tri.GetArray()[3 * j + 2].GetInt());
						}
					}
				}
			}

		}
		void addPointLight(const Light& pointLight) {
			pointLights.push_back(pointLight);
		}
	private:
		rapidjson::Document getJsonDoc(const std::string& filename) {
			std::ifstream input(filename);
			assert(input.is_open());

			rapidjson::IStreamWrapper inStream(input);
			rapidjson::Document doc;
			doc.ParseStream(inStream);

			if (doc.HasParseError()) {
				std::cout << "Error Parsing: " << doc.GetParseError() << "\n";
				std::cout << "Error Getting Offset: " << doc.GetErrorOffset() << "\n";
				assert(false);
			}

			assert(doc.IsObject());
			return doc;
		}
		my_v3 loadVec(const rapidjson::Value::ConstArray& val) {
			my_v3 vec(val[0].GetFloat(), val[1].GetFloat(), val[2].GetFloat());
			return vec;
		}
		initMatrix loadMat(const rapidjson::Value::ConstArray& val) {
			return initMatrix(
				val[0].GetFloat(), val[3].GetFloat(), val[6].GetFloat(),
				val[1].GetFloat(), val[4].GetFloat(), val[7].GetFloat(),
				val[2].GetFloat(), val[5].GetFloat(), val[8].GetFloat());
		}

		std::vector<Light> pointLights;
	};



