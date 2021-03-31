cmake_minimum_required(VERSION 3.17)
project(littleBigGame)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/AbstractEntity.cpp
        src/AbstractEntity.hh
        src/Character.cpp
        src/Character.hh
        src/IObservable.hh
        src/IObserver.hh
        src/ISerializable.hh
        src/MonsterFactory.cpp
        src/MonsterFactory.hh
        src/SprinterMonster.cpp
        src/SprinterMonster.hh
        src/TimeManager.cpp
        src/TimeManager.hh
        src/ZombieMonster.cpp
        src/ZombieMonster.hh
        src/json.hpp
        src/main.cpp
        src/menu.cpp
        src/menu.h
        src/Engine.cpp src/Engine.h src/Console.cpp src/Console.h src/Map.cpp src/Map.h src/TileMap.cpp src/TileMap.h src/Pacman.cpp src/Pacman.h src/Entity.cpp src/Entity.h src/ResourceManager.cpp src/ResourceManager.h)
add_executable(littleBigGame ${SOURCE_FILES})

include_directories(${INCLUDE_DIRS})
if(WIN32)
    include_directories(c:/SFML/include)
    set(SFML_ROOT c:/SFML)
#    set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
else()
    include_directories(/usr/include /usr/local/include)
endif()

#find_package(SFML REQUIRED system window graphics network audio)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR} ${SFML_INCLUDE_DIRS})
    target_link_libraries(littleBigGame ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
target_link_libraries(littleBigGame sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# copy assets to build
#file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()