#include "gtest/gtest.h"
#include <fsm.h>
#include "fsm.cpp"

enum StateE{
	        STATE_NONE = -1,
			STATE1

		} ;

typedef StateE Fstate;

TEST(Fsm, HaveInitStateByDefault) {

  SimpleFsm<Fstate> f;
  ASSERT_EQ(STATE_NONE, f.getState());
}
