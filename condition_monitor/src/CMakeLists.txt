
file(GLOB SOURCES "monitor/*.cpp" "utils/*.cpp" "*.cpp")

add_executable(condition_monitor ${SOURCES})

target_include_directories(condition_monitor PUBLIC
    ${PROJECT_SOURCE_DIR}/condition_monitor/include
    ${PROJECT_SOURCE_DIR}/rpc_manager
)

target_link_libraries(condition_monitor
    PUBLIC
    monitor_proto
    rpc_client
    boost_system
    boost_chrono
)
