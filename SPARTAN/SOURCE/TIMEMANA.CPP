#include <dos.h>
#include <mem.h>

#include "timemana.h"
#include <iostream.h>

float TimeMana::m_CurrentDeltaTime=0;
float TimeMana::m_CurrentElapsedTime=0;

// Gets called every update to set new delta time
void TimeMana::UpdateDeltaTime()
{
	union REGS regs;
	regs.h.ah = 0X00;
	//regs.h.al = ;
	int86(0X1A, &regs, &regs);
	m_CurrentDeltaTime = regs.x.cx;
	short	 hours = regs.x.cx;
	short minutes = regs.x.dx;
	cout << hours << ":" << minutes << endl;

	// Tick count = high 16 bits in cx after 00H Function call (SetTickCount)
	// cx contains hour (and tickcount in high 16 bits)
	// dx contains minutes in hour (1 minute = 1092)
	// 1092 is 18.2 ticks per second for 60 seconds

	//int totalTicks = minutes
}

// Only gets calculated when the GetElapsedTime() gets called
void TimeMana::UpdateElapsedTime()
{

}

float TimeMana::GetDeltaTime() const
{
	return m_CurrentDeltaTime;
}

float TimeMana::GetElapsedTime()
{
	UpdateElapsedTime();
	return m_CurrentElapsedTime;
}

