#include "SceneLoader.h"

void SceneLoader::SetSceneToLoad(std::string f) {

	std::ifstream jsonFile(f, std::ifstream::binary);
	this->sceneToLoad = json::parse(jsonFile);

}

template<typename T>
std::vector<Object*> SceneLoader::LoadObjects(json& ob, std::vector<Material>& materialList) {

	std::vector<Object*> objs;
	std::vector<Material> materialToAdd;

	for (const auto& obj : ob) {
		Vector transform(
			obj["transform"]["x"],
			obj["transform"]["y"],
			obj["transform"]["z"]);

		Vector rotation(
			obj["rota"]["x"],
			obj["rota"]["y"],
			obj["rota"]["z"]);

		Vector scale(
			obj["scale"]["x"],
			obj["scale"]["y"],
			obj["scale"]["z"]);

		for (const int& mat : obj["mIds"]) {
			materialToAdd.push_back(materialList[mat]);
		}

		objs.push_back(new T(transform, rotation, scale, materialToAdd));
		materialToAdd.clear();
	}


	//std::cout << "loadobj" << std::endl;
	return objs;
}

std::vector<Light*> SceneLoader::LoadLights() {
	std::vector<Light*> l;
	for (const auto& light : this->sceneToLoad["Lights"]) {
		Color id(
			light["id"]["r"],
			light["id"]["g"],
			light["id"]["b"]);

		Color is(
			light["is"]["r"],
			light["is"]["g"],
			light["is"]["b"]);

		Vector trans(
			light["transform"]["x"],
			light["transform"]["y"],
			light["transform"]["z"]);

		Vector rot(
			light["rota"]["x"],
			light["rota"]["y"],
			light["rota"]["z"]);

		Vector sca(
			light["scale"]["x"],
			light["scale"]["y"],
			light["scale"]["z"]);

		l.emplace_back(new Light(id, is, trans, rot, sca));
	}
	//std::cout << "loadligth" << std::endl;
	return l;
}

std::vector<std::shared_ptr<Image>> SceneLoader::LoadTextures() {
	std::vector<std::shared_ptr<Image>> texture;
	for (const auto& text : this->sceneToLoad["Textures"]) {
		texture.push_back(std::make_shared<Image>(text));
	}
	return texture;
}

std::vector<Material> SceneLoader::LoadMaterials(std::vector<std::shared_ptr<Image>>& textures) {
	std::vector<Material> material;
	float shininess;
	int textId;


	for (const auto& mat : this->sceneToLoad["Materials"]) {

		Color amb(
			mat["amb"]["r"],
			mat["amb"]["g"],
			mat["amb"]["b"]);

		Color dif(
			mat["dif"]["r"],
			mat["dif"]["g"],
			mat["dif"]["b"]);

		Color spec(
			mat["spec"]["r"],
			mat["spec"]["g"],
			mat["spec"]["b"]);

		shininess = mat["Shininess"];

		if (mat["TexId"] != "") {
			textId = mat["TexId"];
			material.emplace_back(textures[textId], amb, dif, spec, shininess);
		}
		else {
			material.emplace_back(amb, dif, spec, shininess);
		}

	}
	//std::cout << "load mat" << std::endl;
	return material;
}

Scene SceneLoader::LoadScene(std::vector<Material>& materialList) {

	std::vector<Light*> lights;
	std::vector<Object*> objects;
	std::string name = this->sceneToLoad["Name"];

	Color back(
		this->sceneToLoad["Back"]["r"],
		this->sceneToLoad["Back"]["g"],
		this->sceneToLoad["Back"]["b"]
	);

	Color ambiante(
		this->sceneToLoad["Ambiante"]["r"],
		this->sceneToLoad["Ambiante"]["g"],
		this->sceneToLoad["Ambiante"]["b"]
	);

	auto cubes = LoadObjects<Cube>(this->sceneToLoad["Objects"]["Cubes"], materialList);
	objects.insert(objects.end(), cubes.begin(), cubes.end());

	auto plans = LoadObjects<Plan>(this->sceneToLoad["Objects"]["Plans"], materialList);
	objects.insert(objects.end(), plans.begin(), plans.end());

	auto cylinders = LoadObjects<Cylinder>(this->sceneToLoad["Objects"]["Cylinders"], materialList);
	objects.insert(objects.end(), cylinders.begin(), cylinders.end());

	auto squares = LoadObjects<Square>(this->sceneToLoad["Objects"]["Squares"], materialList);
	objects.insert(objects.end(), squares.begin(), squares.end());

	auto spheres = LoadObjects<Sphere>(this->sceneToLoad["Objects"]["Spheres"], materialList);
	objects.insert(objects.end(), spheres.begin(), spheres.end());

	lights = LoadLights();

	return Scene(back, ambiante, lights, objects, name);
}

Camera SceneLoader::LoadCamera(std::vector<Material>& materialList) {

	json cam = this->sceneToLoad["Camera"];

	int height;
	float focal;
	Scene scene = LoadScene(materialList);

	Vector trans(
		cam["transform"]["x"],
		cam["transform"]["y"],
		cam["transform"]["z"]);

	Vector rot(
		cam["rota"]["x"],
		cam["rota"]["y"],
		cam["rota"]["z"]);

	focal = cam["Focal"];
	height = cam["Height"];
	return Camera(focal, height, scene, trans, rot);
}