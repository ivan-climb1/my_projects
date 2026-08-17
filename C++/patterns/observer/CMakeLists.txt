cmake_minimum_required(VERSION 3.10)

project(Observer)

set(files_s
	main.cpp
	ISubject.h
	IParticipant.h

	Subject.h
	Subject.cpp
)

add_executable(observer ${files_s})