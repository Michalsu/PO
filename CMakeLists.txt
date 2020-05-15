cmake_minimum_required(VERSION "3.17")

project("Solaris")

add_library(
	Ciala 
	CialoNiebieskie.cpp
	CialoNiebieskie.h
	Gwiazda.cpp
	Gwiazda.h
	GwiazdaZdegradowana.cpp
	GwiazdaZdegradowana.h
	Planeta.cpp
	Planeta.h
	PlanetaGazowa.cpp
	PlanetaGazowa.h
	PlanetaSkalista.cpp
	PlanetaSkalista.h
	Planetoida.cpp
	Planetoida.h)
add_executable("${PROJECT_NAME}" "Main.cpp")
target_link_libraries("${PROJECT_NAME}" PRIVATE Ciala)



install(TARGETS "${PROJECT_NAME}" DESTINATION ${CMAKE_INSTALL_PREFIX}/bin) 
install(FILES "Main.cpp" DESTINATION ${CMAKE_INSTALL_PREFIX}/src)