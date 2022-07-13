# CMakeList.txt : projet CMake pour RayGenProjet, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

project ("RayGenProjet")

# Ajoutez une source à l'exécutable de ce projet.
add_executable (RayGenProjet "RayGenProjet.cpp" "RayGenProjet.h" "Tools/Entity.h" "Tools/Vector.cpp" "Tools/Point.cpp" "Tools/Matrix.h" "Tools/Matrix.cpp" "Tools/Rayon.h" "Tools/Rayon.cpp" "Tools/Entity.cpp")

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
