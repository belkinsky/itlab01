#ifndef _MYCLASS_H_
#define _MYCLASS_H_

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#ifdef __cplusplus

class MyClass
{
public:
	int p_;
	void method(int param);
};

#endif

typedef void C_MyClass;

EXTERNC void MyClass_method(C_MyClass *me, int param);
EXTERNC C_MyClass* MyClass_getSingletone(void);

#endif
