/*
 * mainBack.cpp
 *
 *  Created on: Apr 15, 2023
 *      Author: llanyro
 */

#include "mainBack.hpp"
#include "../core/MainControllerSingelton.hpp"

// Call the main controller to execute this main when necesary
ll_bool_t backInit = llcpp::core::MainControllerSingelton::getInstance()->addMainToExec(mainBack);

#pragma region MultiThreadExample
#include "../example/example.hpp"
#pragma endregion

int mainBack(int argc, char** argv) {
	thread::exampleThread();
	return 0;
}
