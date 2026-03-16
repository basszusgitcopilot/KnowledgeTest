cmake_minimum_required(VERSION 3.28)

project(knowledgeTest)

add_library(${PROJECT_NAME} SHARED
src/KnowledgeTestDialogImpl.cpp
src/KnowledgeTestDialogRunner.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC 
include
)