/*
 * Singleton.hpp
 *
 *  Created on: Feb 28, 2022
 *      Author: llanyro
 */
#ifndef LLCPP_CORE_SINGLETON_SINGLETON_HPP_
#define LLCPP_CORE_SINGLETON_SINGLETON_HPP_

namespace llcpp {
namespace core {
namespace singleton {

/*
	#pragma region Singleton
	private:
		friend class Singleton<class>;
		class();
		~class();
	#pragma endregion
*/
template <class T>
class Singleton {
	protected:
		Singleton() {}
		virtual ~Singleton() {}
	public:
		static T* getInstance() {
			static T instance;
			return &instance;
		}
};

} /* namespace singleton */
} /* namespace core */
} /* namespace llcpp */

#endif // !LLCPP_CORE_SINGLETON_SINGLETON_HPP_
