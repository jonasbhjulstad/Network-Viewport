# - FindXCB
#
# Copyright 2015 Valve Coporation

find_package(PkgConfig)

if(NOT XCB_FIND_COMPONENTS)
    set(XCB_FIND_COMPONENTS XCB)
endif()

include(FindPackageHandleStandardArgs)
set(XCB_FOUND true)

pkg_check_modules(PC_${comp} QUIET ${comp})

find_path(${compname}_INCLUDE_DIR NAMES ${headername}
    HINTS
    ${PC_xcb_INCLUDEDIR}
    ${PC_xcb_INCLUDE_DIRS}
    )

find_library(XCB_LIBRARY NAMES ${libname}
    HINTS
    ${PC_${comp}_LIBDIR}
    ${PC_${comp}_LIBRARY_DIRS}
    )

find_package_handle_standard_args(${comp}
    FOUND_VAR ${comp}_FOUND
    REQUIRED_VARS ${compname}_INCLUDE_DIR ${compname}_LIBRARY)
mark_as_advanced(${compname}_INCLUDE_DIR ${compname}_LIBRARY)

list(APPEND XCB_INCLUDE_DIRS ${${compname}_INCLUDE_DIR})
list(APPEND XCB_LIBRARIES ${${compname}_LIBRARY})

if(NOT ${comp}_FOUND)
    set(XCB_FOUND false)
endif()