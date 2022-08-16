/*
  The timeManager class provides an interface to get
  the total elapsed time (how long the game is running)
  and the delta time (time since next frame).
*/

#ifndef __TIMEMANA_H
#define __TIMEMANA_H

class TimeMana {
public:
	static float GetDeltaTime() const;
	static float GetElapsedTime();
	void Update();
private:
	static void UpdateDeltaTime();
	static void UpdateElapsedTime();

	static float m_CurrentDeltaTime;
	static float m_CurrentElapsedTime;
};
#endif // __TIMEMANA_H