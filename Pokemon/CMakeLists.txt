# CMakeList.txt: projeto de CMake para Pokemon, incluir origem e definir
# lógica específica a um projeto aqui.
#

# Adicione a origem ao executável deste projeto.
add_executable (Pokemon "Pokemon.cpp" "Pokemon.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pokemon PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.
