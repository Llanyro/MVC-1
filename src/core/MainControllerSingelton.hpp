/*
 * MainControllerSingelton.hpp
 *
 *  Created on: Apr 15, 2023
 *      Author: llanyro
 */

#ifndef LLCPP_CORE_MAINCONTROLLERSINGLETON_HPP_
#define LLCPP_CORE_MAINCONTROLLERSINGLETON_HPP_

#include "../utils/Singleton.hpp"
#include <list>

namespace llcpp {
namespace core {

class Subscriber;

//int (Subscriber::*Main)(int argc, char** argv);

class MainControllerSingelton : public llcpp::core::singleton::Singleton<MainControllerSingelton> {
	#pragma region Singleton
	private:
		friend class Singleton<MainControllerSingelton>;
		MainControllerSingelton();
		~MainControllerSingelton();
	#pragma endregion
	protected:
		//std::list<MainFunction>* mainList;
		std::list<Subscriber*> mainList;
	public:
		// Return true if added to list
		// False if already exists in list
		ll_bool_t add(Subscriber* sub);
		void run(int argc, char** argv) const;
};

} /* namespace core */
} /* namespace llcpp */

#endif // !LLCPP_CORE_MAINCONTROLLERSINGLETON_HPP_
