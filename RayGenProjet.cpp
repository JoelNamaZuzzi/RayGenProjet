// RayGenProjet.cpp : définit le point d'entrée de l'application.
//

#include "RayGenProjet.h"
#include "Tools/Point.h"
#include "Tools/Vector.h"
#include "Tools/Rayon.h"
#include "Tools/Matrix.h"
#include "Tools/Entity.h"
#include "Tools/SceneLoader.h"

int main()
{
	SceneLoader loader("Scene/Template.json");

	Camera monSuperProjetNonMdrJaiMenti = loader.LoadCamera();

	monSuperProjetNonMdrJaiMenti.screenshot("Template", 1080, true, 1);

	return 0;
}
