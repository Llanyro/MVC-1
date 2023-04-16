/*
 * mainGUI.cpp
 *
 *  Created on: Apr 15, 2023
 *      Author: llanyro
 */

#include "../core/Subsciber.hpp"

#pragma region MultiThreadExample
#include "../example/example.hpp"
#include <iostream>
#include <mutex>
#pragma endregion

extern std::mutex coutMutex;

namespace GUI {

class MainGUI : public llcpp::core::Subscriber {
	public:
		MainGUI() : Subscriber(true) {}
		~MainGUI() {}
		virtual int run(int argc, char** argv) const {
			coutMutex.lock();
			std::cout << "GUI thread " << std::this_thread::get_id() << std::endl;
			coutMutex.unlock();
			thread::zzzThread();
			return 0;
		}
};

// Call the main controller to execute this main when necesary
MainGUI main;

} /* namespace backend */
