#pragma once
#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else 
#define DLL_API __declspec(dllimport)
#endif // DLL_EXPORTS
extern "C" DLL_API double sortAscendingg(const char* word);
