// RayGenProjet.cpp : définit le point d'entrée de l'application.
//

#include "RayGenProjet.h"
#include "Tools/Point.h"
#include "Tools/Vector.h"

int main()
{
	std::cout << "Hello CMake." << std::endl;
	Point p(1, 2, 3);
	std::cout << p.X() << " " << p.Y() << " " << p.Z() << std::endl;
	p.X(5);
	std::cout << p.X() << std::endl;
	Vector v (p);
	v = v * 2;
	std::cout << v.X() << " " << v.Y() << " " << v.Z() << std::endl;
	return 0;
}
