cmake_minimum_required(VERSION 3.23)
project(StudentSystem)

set(CMAKE_CXX_STANDARD 14)


add_executable(StudentSystem main.cpp src/Student.cpp include/Student.h src/Manager.cpp include/Manager.h src/DataService.cpp include/DataService.h include/Menu.h "src/Menu.cpp"  "src/Role.cpp" "include/Role.h" include/UserService.h src/UserService.cpp)
target_include_directories(StudentSystem PUBLIC include/json)
target_link_libraries(StudentSystem PUBLIC D:/Workspace/Cpp/StudentSystem/lib/libjsoncpp.a)