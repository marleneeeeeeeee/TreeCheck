cmake_minimum_required(VERSION 4.0)
project(TreeCheck)

set(CMAKE_CXX_STANDARD 20)

add_executable(TreeCheck treecheck.cpp
        TreeNode.cpp
        TreeNode.h
        Tree.cpp
        Tree.h)
