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

typedef int (*MainFunction)(int argc, char** argv);

/*namespace std {
template <class _Ty>
class allocator;
template <class _Ty, class _Alloc = allocator<_Ty>>
class list; // bidirectional linked list
}*/

namespace llcpp {
namespace core {

class MainControllerSingelton : public llcpp::core::singleton::Singleton< MainControllerSingelton> {
	#pragma region Singleton
	private:
		friend class Singleton<MainControllerSingelton>;
		MainControllerSingelton();
		~MainControllerSingelton();
	#pragma endregion
	protected:
		//std::list<MainFunction>* mainList;
		std::list<MainFunction> mainList;
	public:
		// Return true if added to list
		// False if already exists in list
		ll_bool_t addMainToExec(MainFunction function);
		void runMains(int argc, char** argv) const;
};

} /* namespace core */
} /* namespace llcpp */

#endif // !LLCPP_CORE_MAINCONTROLLERSINGLETON_HPP_
