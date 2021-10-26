file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.hpp)

add_custom_target(
	clangf
	ALL
	COMMAND clang-format
	-style=LLVM
	-i
	${ALL_SOURCE_FILES}
	)