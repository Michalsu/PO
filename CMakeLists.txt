cmake_minimum_required(VERSION "3.17")

project("Solaris")

#include_directories(${SFML_INCLUDE_DIR})
#find_package(SFML 2.5.1 COMPONENTS system window graphics REQUIRED)
#set(SFML_STATIC_LIBRARIES TRUE)

add_executable("${PROJECT_NAME}" "Main.cpp" "Main.h"
	CialoNiebieskie.cpp
	Gwiazda.cpp
	GwiazdaZdegradowana.cpp
	GwiazdaZyjaca.cpp
	Planeta.cpp
	PlanetaGazowa.cpp
	PlanetaSkalista.cpp
	Planetoida.cpp
	UkladPlanetarny.cpp

	CialoNiebieskie.h
	Gwiazda.h
	GwiazdaZdegradowana.h	
	GwiazdaZyjaca.h	
	Planeta.h	
	PlanetaGazowa.h	
	PlanetaSkalista.h	
	Planetoida.h
	UkladPlanetarny.h
)


#target_link_libraries("${PROJECT_NAME}"  sfml-system sfml-window sfml-graphics ${SFML_DEPENDENCIES})