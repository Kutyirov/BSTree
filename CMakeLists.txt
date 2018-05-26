cmake_minimum_required(VERSION 3.0)
	
	set(CMAKE_CXX_STANDARD 11)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
	
	option(BUILD_EXAMPLES "Build examples" OFF)
	option(BUILD_TESTS "Build tests" OFF)
	option(BUILD_BENCHMARK "Build benchmarks" ON)
	
	project(BStree)
	
	add_library(BStree STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/BSTree.cpp)
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
	
	add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp)
	target_link_libraries(main BStree)
	
	install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
	install(EXPORT BStree-config DESTINATION cmake)
	
	if(BUILD_EXAMPLES)
	  file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
	  foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
	    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
	    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
	    target_link_libraries(${EXAMPLE_NAME} BStree)
	    install(TARGETS ${EXAMPLE_NAME}
	      RUNTIME DESTINATION bin
	    )
	  endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
	endif()
	
	install(TARGETS BStree
	    EXPORT BStree-config
	    ARCHIVE DESTINATION lib
	    LIBRARY DESTINATION lib
	)
		
	if(BUILD_TESTS)
		enable_testing()
		file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
		add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
		add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes") 
	endif()
	
	if(BUILD_BENCHMARK)
		add_executable(benchmark1 ${CMAKE_CURRENT_SOURCE_DIR}/benchmark/benchmark1.cpp)
		add_executable(benchmark2 ${CMAKE_CURRENT_SOURCE_DIR}/benchmark/benchmark2.cpp)
		add_executable(benchmark3 ${CMAKE_CURRENT_SOURCE_DIR}/benchmark/benchmark3.cpp)
		add_executable(benchmark4 ${CMAKE_CURRENT_SOURCE_DIR}/benchmark/benchmark4.cpp)
		add_executable(benchmark5 ${CMAKE_CURRENT_SOURCE_DIR}/benchmark/benchmark5.cpp)
		add_executable(benchmark6 ${CMAKE_CURRENT_SOURCE_DIR}/benchmark/benchmark6.cpp)
	endif()
