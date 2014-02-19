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

class Test123: public SimpleFsm<EState>
{
public:
	bool called, called2;
	Test123(): called(false), called2(false){}
	   void beginState() {
		   called = true;
	   }
	   void endState() {
		   called2 = true;
	   }
};

TEST(Fsm2, a) {
	Test123 f;
	f.setState(STT_OFF);
	ASSERT_TRUE(f.called);
}
TEST(Fsm3, ab) {
	Test123 f;
	f.setState(STT_OFF);
	ASSERT_TRUE(f.called2);
}

template<int N, typename State> class Fsm: public SimpleFsm<State>
{
  int handlers[N];
  Fsm():
};
