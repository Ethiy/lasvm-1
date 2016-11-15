include(cmake/3rdParty.cmake)

set(LaSVM_LINKER_LIBS "")
set(EXT_PROJECTS_DIR 3rdParty)

# ------------- Catch -------------

add_subdirectory(${EXT_PROJECTS_DIR}/catch)
include_directories(${CATCH_INCLUDE_DIR} ${COMMON_INCLUDES})