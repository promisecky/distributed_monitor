
# set(SOURCES "*.cpp")
file(GLOB SOURCES "*.cpp")
add_executable(server ${SOURCES})

include_directories(/work/monitor_info_manager/)

target_link_libraries(server
            PUBLIC
            monitor_proto
            data_base_manager
)
