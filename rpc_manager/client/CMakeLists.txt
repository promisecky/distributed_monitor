file(GLOB RPC_CLIENT_FILES "*.cpp")

# set(RPC_CLIENT_FILES "*.cpp")

add_library(rpc_client ${RPC_CLIENT_FILES})

target_link_libraries(
    rpc_client
    PUBLIC
    monitor_proto
)