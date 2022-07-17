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

	cam.screenshot("Test", 1080, false, 0);

	return 0;
}
