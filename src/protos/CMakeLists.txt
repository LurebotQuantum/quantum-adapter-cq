
file(GLOB PROTOS ${PROTOS_DIR}/*.proto)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTOS})

include_directories(${Protobuf_INCLUDE_DIR})

add_library(protos STATIC ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(protos ${Protobuf_LIBRARY})
target_include_directories(protos
  PUBLIC
  ${CMAKE_CURRENT_BINARY_DIR}
  ${Protobuf_INCLUDE_DIR})
