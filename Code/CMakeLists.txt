cmake_minimum_required(VERSION 3.16)
project(ChatTcpGui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT WIN32)
  message(FATAL_ERROR "This project uses Winsock and only supports Windows builds.")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(chat_protocol STATIC
  Shared/Protocol.cpp
)
target_include_directories(chat_protocol PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/Shared"
)

find_package(Threads REQUIRED)

add_executable(server Server/server.cpp)
target_link_libraries(server PRIVATE chat_protocol ws2_32 Threads::Threads)

add_executable(client Client/client.cpp)
target_link_libraries(client PRIVATE chat_protocol ws2_32 Threads::Threads)

add_executable(protocol_demo Shared/main.cpp)
target_link_libraries(protocol_demo PRIVATE chat_protocol)
