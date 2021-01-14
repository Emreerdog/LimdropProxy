cmake_minimum_required(VERSION 3.10)

project(LimProxy C CXX)

add_executable(LimProxy main.cpp)

find_package(Python COMPONENTS Interpreter Development)

message("Python_FOUND:${Python_FOUND}")
message("Python_VERSION:${Python_VERSION}")
message("Python_Development_FOUND:${Python_Development_FOUND}")
message("Python_LIBRARIES:${Python_LIBRARIES}")

add_subdirectory(limutils)


find_package(Drogon CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon limutils ${Python_LIBRARIES} -lpython3.9)

aux_source_directory(controllers CTL_SRC)
aux_source_directory(filters FILTER_SRC)
aux_source_directory(plugins PLUGIN_SRC)
aux_source_directory(models MODEL_SRC)
aux_source_directory(views VIEW_SRC)
aux_source_directory(limutils LIMUTIL_SRC)


#target_link_libraries(LimProxy ${Python_LIBRARIES} -lpython3.8)

target_include_directories(LimProxy PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/PyLib/python3.9/" "${PROJECT_SOURCE_DIR}")

target_sources(${PROJECT_NAME}
               PRIVATE
               ${SRC_DIR}
               ${CTL_SRC}
               ${FILTER_SRC}
               ${PLUGIN_SRC}
	       ${VIEW_SRC}
               ${MODEL_SRC}
	       ${LIMUTIL_SRC}
               )
