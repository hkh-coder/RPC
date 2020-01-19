set(CLIENT_SRC ./testrpcclient.cpp ./Message.pb.cc)
set(SERVER_SRC ./testrpcserver.cpp ./Message.pb.cc)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib/myrpc)
include_directories(${PROJECT_SOURCE_DIR}/thirdparty/tinyxml)
link_directories(${PROJECT_SOUREC_DIR}/lib/tinyxml)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


add_executable(rpc_server ${SERVER_SRC})
target_link_libraries(rpc_server myrpc)
add_executable(rpc_client ${CLIENT_SRC})
target_link_libraries(rpc_client myrpc)
