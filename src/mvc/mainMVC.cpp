/*
 * mainMVC.cpp
 *
 *  Created on: Apr 15, 2023
 *      Author: llanyro
 */

#include "../core/Subsciber.hpp"

#pragma region MultiThreadExample
#include "../example/example.hpp"
#pragma endregion

namespace mvc {

class MainMVC : public llcpp::core::Subscriber {
	public:
		MainMVC() {}
		~MainMVC() {}
		virtual int run(int argc, char** argv) const {
			thread::zzzThread();
			return 0;
		}
};

// Call the main controller to execute this main when necesary
MainMVC main;

} /* namespace backend */
