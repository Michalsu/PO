cmake_minimum_required(VERSION "3.17")

project("Solaris")

#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/" ${CMAKE_MODULE_PATH})
# SFML
add_subdirectory(./SFML)
## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES FALSE)
set(BUILD_SHARED_LIBS FALSE)
#set(FreeType_LIB "SFML-2.5.1/lib/freetype")

## In most cases better set in the CMake cache
#set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")
#set(SFML_DIR "SFML/cmake")
set(SFML_DIR "SFML-build")

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


find_package(SFML 2.5.1 COMPONENTS system window graphics REQUIRED)


include_directories(${SFML_INCLUDE_DIR})
target_link_libraries("${PROJECT_NAME}"  sfml-system sfml-window sfml-graphics ${SFML_DEPENDENCIES})
#target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
#target_link_libraries("${PROJECT_NAME}" ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})


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