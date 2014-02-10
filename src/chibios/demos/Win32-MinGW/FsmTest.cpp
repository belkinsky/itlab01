#include "gtest/gtest.h"
#include <fsm.h>
#include "fsm.cpp"

enum StateE {
	STATE_NONE = -1, STATE1=1, STATE2 = 0

};

typedef StateE Fstate;

TEST(Fsm, HaveInitStateByDefault) {

  SimpleFsm<Fstate> f;
  ASSERT_EQ(STATE_NONE, f.getState());
}


TEST(Fsm1, CheckSetStateChange) {

	  SimpleFsm<Fstate> f;
	  f.setState(STATE1);
	  ASSERT_EQ(STATE1, f.getState());
	  f.setState(STATE2);
	  ASSERT_EQ(STATE2, f.getState());
}

