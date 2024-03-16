file(GLOB SOURCES "*.cpp")

add_library(data_base_manager ${SOURCES})
# set(MYSQL_INCLUDE_DIR "/usr/include/mysql/")
# 包含MySQL头文件目录

target_link_libraries(data_base_manager
            PUBLIC
            mysqlclient
            boost_system
            boost_chrono
            monitor_proto
)

target_include_directories(data_base_manager
            PUBLIC
            /usr/include/mysql
)

