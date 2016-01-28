//==============================================================================
//	VariadicTemplate.cpp:
//==============================================================================

#include <iostream>
#include <memory>

struct SomeStruct
{
	SomeStruct()
	{
		std::cout << "SomeStruct()" << std::endl;
	}

	SomeStruct(int a)
	{
		std::cout << "SomeStruct(int a)" << std::endl;
	}

	SomeStruct(const std::string & str)
	{
		std::cout << "SomeStruct(const std::string & str)" << std::endl;
	}

	SomeStruct(const std::string & str, int a)
	{
		std::cout << "SomeStruct(const std::string & str, int a)" << std::endl;
	}

};


template<typename T>
class ClassWrapper
{
	public:
		typedef T					type;
		typedef std::unique_ptr<T>	type_ptr;
		typedef ClassWrapper<T>		this_type;

	public:
		template<typename ... Args>
		static type_ptr Create(Args ...args)
		{
			return type_ptr(new T(args...));
		}

};

int main(int args, char ** argv, char ** arge)
{
	// Create a typedef to safe typing
	typedef ClassWrapper<SomeStruct>	CWSS;

	// Exercise the different SomeStruct constructors (ctor) through ClassWrapper  
	auto p1 = CWSS::Create();
	auto p2 = CWSS::Create(123);
	auto p3 = CWSS::Create("string");
	auto p4 = CWSS::Create("string", 234);

	/*
	Output should be:
	SomeStruct()
	SomeStruct(int a)
	SomeStruct(const std::string & str)
	SomeStruct(const std::string & str, int a)
	*/

	return 0;
}

