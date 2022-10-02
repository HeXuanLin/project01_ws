# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "helloword: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ihelloword:/home/cave/project01_ws/src/helloword/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(helloword_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/cave/project01_ws/src/helloword/msg/person.msg" NAME_WE)
add_custom_target(_helloword_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "helloword" "/home/cave/project01_ws/src/helloword/msg/person.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(helloword
  "/home/cave/project01_ws/src/helloword/msg/person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/helloword
)

### Generating Services

### Generating Module File
_generate_module_cpp(helloword
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/helloword
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(helloword_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(helloword_generate_messages helloword_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cave/project01_ws/src/helloword/msg/person.msg" NAME_WE)
add_dependencies(helloword_generate_messages_cpp _helloword_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(helloword_gencpp)
add_dependencies(helloword_gencpp helloword_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS helloword_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(helloword
  "/home/cave/project01_ws/src/helloword/msg/person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/helloword
)

### Generating Services

### Generating Module File
_generate_module_eus(helloword
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/helloword
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(helloword_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(helloword_generate_messages helloword_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cave/project01_ws/src/helloword/msg/person.msg" NAME_WE)
add_dependencies(helloword_generate_messages_eus _helloword_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(helloword_geneus)
add_dependencies(helloword_geneus helloword_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS helloword_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(helloword
  "/home/cave/project01_ws/src/helloword/msg/person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/helloword
)

### Generating Services

### Generating Module File
_generate_module_lisp(helloword
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/helloword
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(helloword_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(helloword_generate_messages helloword_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cave/project01_ws/src/helloword/msg/person.msg" NAME_WE)
add_dependencies(helloword_generate_messages_lisp _helloword_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(helloword_genlisp)
add_dependencies(helloword_genlisp helloword_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS helloword_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(helloword
  "/home/cave/project01_ws/src/helloword/msg/person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/helloword
)

### Generating Services

### Generating Module File
_generate_module_nodejs(helloword
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/helloword
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(helloword_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(helloword_generate_messages helloword_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cave/project01_ws/src/helloword/msg/person.msg" NAME_WE)
add_dependencies(helloword_generate_messages_nodejs _helloword_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(helloword_gennodejs)
add_dependencies(helloword_gennodejs helloword_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS helloword_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(helloword
  "/home/cave/project01_ws/src/helloword/msg/person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/helloword
)

### Generating Services

### Generating Module File
_generate_module_py(helloword
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/helloword
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(helloword_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(helloword_generate_messages helloword_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cave/project01_ws/src/helloword/msg/person.msg" NAME_WE)
add_dependencies(helloword_generate_messages_py _helloword_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(helloword_genpy)
add_dependencies(helloword_genpy helloword_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS helloword_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/helloword)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/helloword
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(helloword_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/helloword)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/helloword
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(helloword_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/helloword)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/helloword
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(helloword_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/helloword)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/helloword
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(helloword_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/helloword)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/helloword\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/helloword
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(helloword_generate_messages_py std_msgs_generate_messages_py)
endif()
