cmake_minimum_required(VERSION 3.28)

project(Socket)

add_executable(Socket src/server.cpp)
add_executable(Client src/client.cpp)
target_link_directories(Socket PRIVATE src/socket/build/)
target_link_directories(Socket PRIVATE src/session/build/)
target_link_directories(Socket PRIVATE src/payload/build/)

target_link_directories(Client PRIVATE src/socket/build/)
target_link_directories(Client PRIVATE src/session/build/)
target_link_directories(Client PRIVATE src/payload/build/)

target_link_libraries(Socket socket-lib)
target_link_libraries(Socket session-lib)
target_link_libraries(Socket payload-lib)

target_link_libraries(Client socket-lib)
target_link_libraries(Client session-lib)
target_link_libraries(Client payload-lib)
