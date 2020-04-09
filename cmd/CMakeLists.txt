project(webserver)

set(SRC_FILES server.c)

add_library(cmd ${SRC_FILES})
