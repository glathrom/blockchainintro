
################################
# setting path to include files 
################################

include_directories( 
    ${CMAKE_SOURCE_DIR}/include
) 

######################
# compiled libraries
######################

#add_library(block STATIC block.cpp)

######################
# executables 
######################


set(MYTARGET myBlockChain)

find_library(OPENSSL crypto REQUIRED) 

add_executable(${MYTARGET} main.cpp block.cpp blockchain.cpp)
target_include_directories(${MYTARGET} BEFORE PUBLIC ${OPENSSL_INCLUDE_DIR})
target_link_libraries( ${MYTARGET} PUBLIC ${OPENSSL} )

#target_link_options(${PROJECT_NAME} PUBLIC "-Wl,-rpath,${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")

######################
# installation 
######################

#install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
#install(TARGETS booger LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}) # dynamic
#install(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}) # static
