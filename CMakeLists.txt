cmake_minimum_required(VERSION 3.13)
project(payroll_riyo)

set(CMAKE_CXX_STANDARD 14)

add_executable(payroll_riyo main.cpp Employee.h EmployeeList.h)