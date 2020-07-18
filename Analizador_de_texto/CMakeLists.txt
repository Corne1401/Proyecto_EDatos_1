cmake_minimum_required(VERSION 3.16)
project(Analizador_de_texto)

set(CMAKE_CXX_STANDARD 14)

add_executable(Analizador_de_texto main.cpp Helpers/StringUtils.h Structures/CharList/CharNode.cpp Structures/CharList/CharNode.h Structures/CharList/CharList.cpp Structures/CharList/CharList.h Helpers/OptionMenu.h Helpers/Delimiters.h Helpers/Round.h Structures/WordList/WordNode.h Structures/WordList/WordNode.cpp Structures/WordList/WordList.h Structures/WordList/WordList.cpp Structures/WordList/PositionNode.cpp Structures/WordList/PositionNode.h Helpers/IsPrefix.h)