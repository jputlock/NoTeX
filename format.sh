find . -regex '.*\.\(cpp\|h\|hpp\|cxx\)' -exec clang-format -i {} \;
