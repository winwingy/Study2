#pragma once

#ifndef DELAYCLASS
#define dllDelayFun __declspec(dllimport) 
#endif

dllDelayFun int fnLib(int a);

dllDelayFun int fnLib2(int a);

class DelayClass
{
public:
	DelayClass(void);
	~DelayClass(void);
};

