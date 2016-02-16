#include <string>
#include <cstdint>

template<int> 
std::string GetPlatform();

template<>
std::string GetPlatform<4>() { return "32-bit"; }

template<>
std::string GetPlatform<8>() { return "64-bit"; }

// helper function just to hide clumsy syntax
inline std::string GetPlatform() { return GetPlatform<sizeof(size_t)>(); }

class Lib1
{
	public:
		std::string GetVersion()
		{
			return "Lib1 - " + GetPlatform();
		}
};

// DLL API

#if defined(LIB1_EXPORTS)
#define LIB1_API __declspec(dllexport)
#else
#define LIB1_API __declspec(dllimport)
#endif

extern "C"
{
	LIB1_API uint32_t GetVersion(char * buffer, uint32_t length)
	{
		Lib1 lib1;
		auto val = snprintf(buffer, length, lib1.GetVersion().c_str());

		return 0;
	}
}
