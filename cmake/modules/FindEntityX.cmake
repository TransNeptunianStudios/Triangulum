
MESSAGE("ENTITYX_ROOT is ${ENTITYX_ROOT}")

find_path(ENTITYX_INCLUDE_DIR entityx/entityx.h
   PATHS
   /usr/local/include
   ${ENTITYX_ROOT}/include
)

#MESSAGE("ENTITYX_INCLUDE_DIR is ${ENTITYX_INCLUDE_DIR}")

find_library(ENTITYX_LIBRARY
   NAMES entityx libentityx
   HINTS
   /usr/local/lib
   ${ENTITYX_ROOT}/lib
)

#MESSAGE("ENTITYX_LIBRARY is ${ENTITYX_LIBRARY}")

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(EntityX  DEFAULT_MSG
                                  ENTITYX_LIBRARY ENTITYX_INCLUDE_DIR)
