﻿# CMakeList.txt : projet CMake pour RayGenProjet, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

project ("RayGenProjet")
set (CMAKE_CXX_STANDARD 17)
# Ajoutez une source à l'exécutable de ce projet.
add_executable (RayGenProjet "RayGenProjet.cpp" "RayGenProjet.h" "Tools/Entity.h" "Tools/Vector.cpp" "Tools/Point.cpp" "Tools/Matrix.h" "Tools/Matrix.cpp" "Tools/Rayon.h" "Tools/Rayon.cpp" "Tools/Entity.cpp" "Tools/Material.h" "Tools/Color.h" "Tools/Color.cpp" "Image/Image.h" "Image/ImgType.h" "Tools/Serializer.h" "Libs/stb_image.h" "Libs/stb_image_write.h" "Image/Image.cpp" "Tools/StringRW.h" "Tools/Material.cpp" "Tools/Object.h" "Tools/Object.cpp" "Tools/Light.h" "Tools/Light.cpp" "Tools/Scene.h" "Tools/Scene.cpp"  "Libs/json.hpp" "Tools/Objects/Cube.h" "Tools/Objects/Cube.cpp" "Tools/Objects/Cylinder.h" "Tools/Objects/Cylinder.cpp" "Tools/Objects/Plan.h" "Tools/Objects/Plan.cpp" "Tools/Objects/Sphere.h" "Tools/Objects/Sphere.cpp" "Tools/Objects/Square.h" "Tools/Objects/Square.cpp" "Tools/Objects/Include.h" "Tools/SceneLoader.h" "Tools/SceneLoader.cpp" "Tools/Camera.h"  "Tools/Camera.cpp")

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
