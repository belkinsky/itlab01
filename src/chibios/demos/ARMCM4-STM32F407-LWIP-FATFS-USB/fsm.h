#ifndef _FSM_H_
#define _FSM_H_




template<typename T>
class SimpleFsm
{
public:
  SimpleFsm() : _time_in_cur_state(0.0f), _cur_state(-1)
  {
  }

  virtual void beginState( T state ) {}
  virtual void updateState( T state ) {}
  virtual void endState( T state ) {}

  void setState( T state )
  {
    endState( (T)_cur_state );
    _cur_state = state;
    _time_in_cur_state = 0.0f;
    beginState( (T)_cur_state );
  }

  void updateFsm( float delta_time )
  {
    if( _cur_state != -1 )
    {
      _time_in_cur_state+=delta_time;
      updateState( (T)_cur_state );
    }
  }

  float getTimeInCurState() { return _time_in_cur_state; }
  T getState() { return (T)_cur_state; }

private:
  float _time_in_cur_state;
  int _cur_state;
};

enum EState
{
  STT_OFF = -1, // optional, -1 is the initial state of the fsm
  STT_WALK,
  STT_RUN,
  STT_STOP,
  STT_EAT
};

class MainFsm: public SimplesFsm<EState>
{
public:
  // ...
  void updateState( EState t );
  void beginState( EState t );
  void endState( EState t );
  // ...
};
extern MainFsm g_fsm;
#endif
