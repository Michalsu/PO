cmake_minimum_required(VERSION "3.17")

project("Solaris")

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