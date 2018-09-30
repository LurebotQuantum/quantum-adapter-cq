
# all source files
aux_source_directory(. DIR_SRCS)

# build
add_library(me.icefla.quantum SHARED ${DIR_SRCS})
target_link_libraries(me.icefla.quantum
  ${CMAKE_CURRENT_SOURCE_DIR}/CQP.lib)

# install
install(TARGETS me.icefla.quantum DESTINATION ${DIST_DIR})
install(FILES me.icefla.quantum.json DESTINATION ${DIST_DIR})
