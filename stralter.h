#include <vcl.h>
#include <windows.h>
#ifdef DLL_FILE
extern "C" __declspec(dllexport) AnsiString __stdcall DeleteBefore(AnsiString subStr, AnsiString srcStr);
extern "C" __declspec(dllexport) AnsiString __stdcall DeleteBeforeW(AnsiString subStr, AnsiString srcStr);
extern "C" __declspec(dllexport) AnsiString __stdcall DeleteAfter(AnsiString subStr, AnsiString srcStr);
extern "C" __declspec(dllexport) AnsiString __stdcall DeleteAfterW(AnsiString subStr, AnsiString srcStr);
#else
#pragma comment(lib, "stralter.lib")
extern "C" __declspec(dllimport) AnsiString __stdcall DeleteBefore(AnsiString subStr, AnsiString srcStr);
extern "C" __declspec(dllimport) AnsiString __stdcall DeleteBeforeW(AnsiString subStr, AnsiString srcStr);
extern "C" __declspec(dllimport) AnsiString __stdcall DeleteAfter(AnsiString subStr, AnsiString srcStr);
extern "C" __declspec(dllimport) AnsiString __stdcall DeleteAfterW(AnsiString subStr, AnsiString srcStr);
#endif
