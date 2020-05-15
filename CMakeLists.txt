cmake_minimum_required(VERSION "3.17")

project("Solaris")

add_library(Ciala 
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
	Planetoida.h)
add_executable("${PROJECT_NAME}" "Main.cpp")
target_link_libraries("${PROJECT_NAME}" PRIVATE Ciala)



install(TARGETS "${PROJECT_NAME}" DESTINATION ${CMAKE_INSTALL_PREFIX}/bin) 
install(FILES "Main.cpp" DESTINATION ${CMAKE_INSTALL_PREFIX}/src)