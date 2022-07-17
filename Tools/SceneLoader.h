#pragma once
#ifndef RAYGEN_SCENELOADER_H
#define RAYGEN_SCENELOADER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

#include "Objects/Include.h"
#include "../Image/Image.h"
#include "Vector.h"
#include "Entity.h"
#include "Scene.h"
#include "Light.h"
#include "Camera.h"
#include "../Libs/json.hpp"

using json = nlohmann::json;

class SceneLoader
{
	
	private :

		json sceneToLoad;

	public :

		SceneLoader(std::string file) {
			std::ifstream jsonFile(file, std::ifstream::binary);
			this->sceneToLoad = json::parse(jsonFile);
		}

		void SetSceneToLoad(std::string);
	
		template<typename T>
		std::vector<Object*> LoadObjects(json);

		std::vector<Light*> LoadLights();

		std::vector<std::shared_ptr<Image>> LoadTextures();

		std::vector<Material> LoadMaterials();

		Scene LoadScene();

		Camera LoadCamera();
		
};




#endif //RAYGEN_SCENELOADER_H