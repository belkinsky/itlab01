#include "gtest/gtest.h"
#include <fsm.h>


TEST(HelloTest, AlwaysOk) {
	typedef enum{
		STATE1
	}
	Fstate;
  SimpleFsm<Fstate> f;
}
