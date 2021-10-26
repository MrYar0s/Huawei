file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.hpp)
list(REMOVE_ITEM ALL_SOURCE_FILES "./bin/")

add_custom_target(
	clangf
	COMMAND clang-format
	-style=LLVM
	-i
	${ALL_SOURCE_FILES}
	)
