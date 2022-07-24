// RayGenProjet.cpp : définit le point d'entrée de l'application.
//

#include "RayGenProjet.h"
#include "Tools/Point.h"
#include "Tools/Vector.h"
#include "Tools/Rayon.h"
#include "Tools/Matrix.h"
#include "Tools/Entity.h"
#include "Tools/SceneLoader.h"
#include "Tools/Camera.h"

int main()
{
	SceneLoader loader("Scene/Template.json");

	Camera cam = loader.LoadCamera();

	cam.screenshot("Test", 1080, false, 2);
	/*Color col = Color(1, 1, 1);
	std::vector<Material> mat;
	Material matest= Material(col, col, col, 100);
	mat.push_back(matest);
	Cube testcube(Vector(0.0f, 0.0f, 0.0f), Vector(0.0f, 0.0f, 0.0f), Vector(1.0f, 1.0f, 1.0f), mat);
	if (testcube.intersect(Rayon(0.25, 0.25, 0.0f, -0.90, -0.90, -1.0f), Point(0.25, 0.25, 0.0f))==true) {
		std::cout << "okay";
	}*/

	return 0;
}
