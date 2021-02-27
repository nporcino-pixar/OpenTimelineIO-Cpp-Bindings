set(CPP_OPENTIMELINEIO_HEADER_FILES
    ${PROJECT_SOURCE_DIR}/src/OpenTimelineIO.hpp)

add_executable(cpp_opentimelineio
#$add_library(cpp_opentimelineio ${CPPOTIO_SHARED_OR_STATIC_LIB}
        ${PROJECT_SOURCE_DIR}/src/OpenTimelineIO.cpp
        ${COPENTIMELINEIO_HEADER_FILES})

target_include_directories(cpp_opentimelineio PUBLIC
        "${PROJECT_SOURCE_DIR}/src/"
        "${PROJECT_SOURCE_DIR}/OpenTimelineIO/src/"
        "${PROJECT_SOURCE_DIR}/OpenTimelineIO/src/deps/"
        "${PROJECT_SOURCE_DIR}/OpenTimelineIO/src/deps//optional-lite/include")

target_link_libraries(cpp_opentimelineio PUBLIC
        OTIO::opentime
        OTIO::opentimelineio)

set_target_properties(cpp_opentimelineio PROPERTIES 
        INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib"
        MACOSX_RPATH true 
        WINDOWS_EXPORT_ALL_SYMBOLS true)

install(TARGETS cpp_opentimelineio
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib)

install(FILES ${CPP_OPENTIMELINEIO_HEADER_FILES}
        DESTINATION include/copentimelineio)
