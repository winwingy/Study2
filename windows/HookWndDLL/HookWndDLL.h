#include <Windows.h>

#ifndef DLLIMPLHOOK
#define HOOKWNDAPI __declspec(dllimport)
#else
#define HOOKWNDAPI __declspec(dllexport)
#endif



HOOKWNDAPI void injectWnd();

HOOKWNDAPI void unjectWnd();