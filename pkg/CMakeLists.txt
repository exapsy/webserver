project(pkg)

set(SRC_FILES
	./strings/string.c
	./errors/errors.c)

add_library(pkg ${SRC_FILES})
