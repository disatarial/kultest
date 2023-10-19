cmake_minimum_required (VERSION 2.6)

set (PROJECT kultest)
project (${PROJECT})
include_directories (../)
find_package(PkgConfig)

find_library(PTHREAD_LIBRARY pthread)



set (LIBRARIES)

set (HEADERS

)

set (SOURCES 

../main.c

)

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})



add_executable (${PROJECT} ${HEADERS} ${SOURCES}   )

target_link_libraries(${PROJECT}  ${PTHREAD_LIBRARY})


if (PKG_CONFIG_FOUND)
  pkg_check_modules(GTK "gtk+-3.0")
  if (GTK_FOUND)    
	target_link_libraries (${PROJECT} ${LIBRARIES} ${GTK_LIBRARIES} )

    add_definitions(${GTK_CFLAGS} ${GTK_CFLAGS_OTHER})
  endif()
endif() 

 
