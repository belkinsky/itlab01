#include "myclass.h"
#include <ch.hpp> //TODO use this classes to access ChibiOS features

using chibios_rt;

MyClass g_myInstance;

void MyClass::method(int param)
{
	p_ = param;
}

void MyClass_method(C_MyClass* me, int param)
{
	MyClass *obj = static_cast<MyClass*>(me);
	obj->method(param);
}

C_MyClass* MyClass_getGMyInstance()
{
	return static_cast<C_MyClass*>(&g_myInstance);
}
