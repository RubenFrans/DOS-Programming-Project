#include "game.h"
#include <iostream.h>
#include "timemana.h"

Game::Game()
	: m_IsRunning(1)
	, m_CurrentRunTime(0)
	, m_MaxRunTime(5)
	, m_Renderer()
{
}

Game::~Game() {

}

void Game::Run() {
	//Setup
	m_Renderer.SetVideoMode(VGA_256_COLOR_MODE);

	while(m_IsRunning){

		// Calculate delta time
		TimeMana::UpdateDeltaTime();
		cout << TimeMana::GetDeltaTime() << endl;

		// Run Update

		m_Renderer.PlotPixelFast(10, 10, 120);

		if(m_CurrentRunTime > m_MaxRunTime)
		{
			m_IsRunning = 0;
		}

		m_CurrentRunTime++;
		// Run FixedUpdate
	}

	// cleanup
	m_Renderer.SetVideoMode(TEXT_MODE);

}