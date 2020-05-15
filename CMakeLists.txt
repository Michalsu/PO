cmake_minimum_required(VERSION "3.17")

project("Solaris")

add_executable("${PROJECT_NAME}" "Main.cpp" 
	CialoNiebieskie.cpp
	Gwiazda.cpp
	GwiazdaZdegradowana.cpp
	GwiazdaZyjaca.cpp
	Planeta.cpp
	PlanetaGazowa.cpp
	PlanetaSkalista.cpp
	Planetoida.cpp
	CialoNiebieskie.h
	Gwiazda.h
	GwiazdaZdegradowana.h	
	GwiazdaZyjaca.h	
	Planeta.h	
	PlanetaGazowa.h	
	PlanetaSkalista.h	
	Planetoida.h
	Vec2.cpp 
	Vec2.h
)


install(TARGETS "${PROJECT_NAME}" DESTINATION ${CMAKE_INSTALL_PREFIX}/bin) 
install(FILES "Main.cpp" 
	CialoNiebieskie.cpp
	Gwiazda.cpp
	GwiazdaZdegradowana.cpp
	GwiazdaZyjaca.cpp
	Planeta.cpp
	PlanetaGazowa.cpp
	PlanetaSkalista.cpp
	Planetoida.cpp
	CialoNiebieskie.h
	Gwiazda.h
	GwiazdaZdegradowana.h	
	GwiazdaZyjaca.h	
	Planeta.h	
	PlanetaGazowa.h	
	PlanetaSkalista.h	
	Planetoida.h
			DESTINATION ${CMAKE_INSTALL_PREFIX}/src)