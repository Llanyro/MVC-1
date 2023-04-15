/*
 * llanytypeslib.h
 *
 *  Created on: Feb 28, 2022
 *      Author: llanyro
 */

#ifndef LLPC_LIBS_CORE_HEADER_LLANYTYPESLIB_H_
#define LLPC_LIBS_CORE_HEADER_LLANYTYPESLIB_H_

 /// Adds, removes or creates defines and types depending the lib we are
#pragma region c_cpp_check
// Definitions and more depending of lib
#if defined(__cplusplus)
typedef bool ll_bool_t;
#define TRUE true
#define FALSE false

#define NULLPTR nullptr

#define C_LIB_START
#define C_LIB_END
#elif !defined(__cplusplus)
typedef char ll_bool_t;
#define TRUE 1
#define FALSE 0

#if !defined(NULL)
#define NULL 0
#endif // !defined(NULL)

#define NULLPTR NULL

#endif // defined(__cplusplus)
#pragma endregion

#pragma region GeneralTypes

/*
32 bits
char 		Bytes 1 : -128 to 127												-> 255
short 		Bytes 2 : -32,768 to 32,767											-> 65,535
int 		Bytes 4 : -2,147,483,648 to 2,147,483,647							-> 4,294,967,295
long 		Bytes 4 : -2,147,483,648 to 2,147,483,647							-> 4,294,967,295
long long	Bytes 8 : -9,223,372,036,854,775,808 to 9,223,372,036,854,775,808	-> 18,446,744,073,709,551,615

64 bits
char 		Bytes 1 : -128 to 127												-> 255
short 		Bytes 2 : -32,768 to 32,767											-> 65,535
int 		Bytes 4 : -2,147,483,648 to 2,147,483,647							-> 4,294,967,295
long 		Bytes 8 : -9,223,372,036,854,775,808 to 9,223,372,036,854,775,808	-> 18,446,744,073,709,551,615
long long	Bytes 8 : -9,223,372,036,854,775,808 to 9,223,372,036,854,775,808	-> 18,446,744,073,709,551,615

32 & 64 bits
float		Bytes 4 :
double		Bytes 8 :
long double	Bytes 16:
*/

// Signed
typedef char ll_char_t;						// Signed
typedef short ll_short_t;					// Signed
typedef int ll_int_t;						// Signed
typedef long ll_long_t;						// Signed
typedef long long ll_longlong_t;			// Signed

typedef unsigned char ll_uchar_t;			// Unsigned
typedef unsigned short ll_ushort_t;			// Unsigned
typedef unsigned int ll_uint_t;				// Unsigned
typedef unsigned long ll_ulong_t;			// Unsigned
typedef unsigned long long ll_ulonglong_t;	// Unsigned

// Flotantes
typedef float ll_float_t;
typedef double ll_double_t;
typedef long double ll_ldouble_t;

// Bits
typedef ll_char_t ll_int8_t;
typedef ll_uchar_t ll_uint8_t;
typedef ll_short_t ll_int16_t;
typedef ll_ushort_t ll_uint16_t;
typedef ll_int_t ll_int32_t;
typedef ll_uint_t ll_uint32_t;

#if defined(__x86_64__) && !defined(__ILP32__)
typedef ll_long_t ll_int64_t;
typedef ll_ulong_t ll_uint64_t;
#else
typedef ll_longlong_t ll_int64_t;
typedef ll_ulonglong_t ll_uint64_t;
#endif
#pragma endregion

#pragma region NonGeneralTypes1
typedef ll_uchar_t hex;		// Usado para guardar el valor numerico de un Hexadecimal

typedef ll_uint64_t len_t; 	// Usado para posiciones de listas y tamanios de listas -> es decir: cantidades de datos
typedef ll_uint32_t medlen_t; 	// Usado para posiciones de listas y tamanios de listas -> es decir: cantidades de datos

/// Tipos para control de bytes
typedef ll_uint8_t size_bytes8_t;	// Used to store the size of a object or memory
typedef ll_uint16_t size_bytes16_t;	// Used to store the size of a object or memory
typedef ll_uint32_t size_bytes32_t;	// Used to store the size of a object or memory
typedef ll_uint64_t size_bytes64_t;	// Used to store the size of a object or memory

typedef size_bytes8_t s_b8_t;	// Used to store the size of a object or memory
typedef size_bytes16_t s_b16_t;	// Used to store the size of a object or memory
typedef size_bytes32_t s_b32_t;	// Used to store the size of a object or memory
typedef size_bytes64_t s_b64_t;	// Used to store the size of a object or memory

typedef ll_char_t ll_bytes_t;
typedef ll_uchar_t ll_ubytes_t;

typedef ll_int8_t ll_singleton_priority_t;
typedef ll_singleton_priority_t ll_singleton_prio_t;

typedef void* ll_any_t;

//typedef char const* const ll_constchar_t;
//typedef void ll_void_t;
typedef const char* ll_str_t;
typedef const unsigned char* const ll_ustr_t;

typedef struct {
	len_t size;
	ll_any_t arr;
} ll_array_t;

#pragma endregion

#pragma region DEFINES
#define TRUE_STRING "True"
#define TRUE_STRING_LEN 4
#define FALSE_STRING "False"
#define FALSE_STRING_LEN 5
#define GET_BOOL_STR(a) ((a == TRUE) ? TRUE_STRING : FALSE_STRING)

//#define and &&
//#define or ||
#define elif else if
#define as =

#pragma region INLINES

// Al hypersmall functions
#define INLINE0 inline

// ???
#define I1
// All funtions of c struct libs
#define I2
// All functions of C libs
#define I3

#if defined(I1)
/// Only when I1 is defined
#define INLINE1 inline
#else
/// Only when I1 is defined
#define INLINE1
#endif // I1

#if defined(I2)
/// Only when I2 is defined
#define INLINE2 inline
#else
/// Only when I2 is defined
#define INLINE2
#endif // I2

#if defined(I3)
/// Only when I3 is defined
#define INLINE3 inline
#else
/// Only when I3 is defined
#define INLINE3
#endif // I3

#pragma endregion

#pragma endregion

#pragma region DefFunctions
typedef ll_int_t (*Compare_int)(const void* item_a, const void* item_b);
typedef ll_bool_t (*Compare_bool)(const void* item_a, const void* item_b);
typedef ll_int_t (*CompareChar_int)(const char* caracter1, const char* caracter2);
//typedef ll_uint32_t (*Range_uint32)(const ll_uint32_t& value);
typedef void (*DoAnything)(void*, ...);
typedef void (*Destructor)(void*);
/*
* History and information
* This function inheritances from Compare_int
*	Compare_int is a function of general comparations
*	Compare_int compares 2 objects and return a int
*		0 -> Same item
*		1 -> a > b
*	   -1 -> a < b
*	That means, that this function compares 2 items
*	But sometimes is not enough, sometimes we need more data
*	So this function poposes a solution, a third data, that can contains an struct or other data (int, char, ...)
*/
typedef ll_int_t(*Compare)(const void* item_a, const void* item_b, void* extra_data);

#pragma region InlineFunctions

// Function that does nothing
INLINE0 void do_nothing(void* a, ...) {}
INLINE0 void default_destructor(void** c) {}

#pragma endregion

#pragma endregion

#pragma region IncludesByDefines

#if defined(_DEBUG)
#include <assert.h>
#else
#define assert
#endif // _DEBUG

#pragma endregion

#if defined(_WIN32) or defined(_WIN64)
#define WINDOWS_SYSTEM
#endif // _WIN32


/// Win dll
#if defined(WINDOWS_SYSTEM)
//#define LL_DLL_BUILD
#ifdef LL_DLL_BUILD
#define LL_SHARED_LIB __declspec(dllexport)
#else
//#define LL_SHARED_LIB __declspec(dllimport)
#define LL_SHARED_LIB
#endif
#else
#define LL_SHARED_LIB
#endif // WINDOWS_SYSTEM

/// C / C++ Compatibility
/*
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus




#ifdef __cplusplus
}
#endif // __cplusplus
*/

// Disables del pesao de windows
#if defined(WINDOWS_SYSTEM)

#pragma warning(disable:6011)
#pragma warning(disable:6387)
#pragma warning(disable:4996)


#pragma warning(disable:4244)
#pragma warning(disable:6031)

// Socket
#pragma warning(disable:4309)
#pragma warning(disable:4477)
#pragma warning(disable:26439)
#endif // defined(WINDOWS_SYSTEM)


#endif /* LLPC_LIBS_CORE_HEADER_LLANYTYPESLIB_H_ */
