
aux_source_directory(. DIR_SRCS)

add_library(me.icefla.quantum SHARED ${DIR_SRCS})
target_link_libraries(me.icefla.quantum
  protos
  ${CMAKE_CURRENT_SOURCE_DIR}/CQP.lib)

install(TARGETS me.icefla.quantum DESTINATION ${CMAKE_SOURCE_DIR}/dist)
install(FILES me.icefla.quantum.json DESTINATION ${CMAKE_SOURCE_DIR}/dist)
