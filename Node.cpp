#include "Node.h"


void Node::addDirection(int t_directionX, int t_directionY, int t_delay)
{
	m_directionsX.push_back(t_directionX);
	m_directionsY.push_back(t_directionY);
	m_time.push_back(t_delay);
}
void Node::update()
{
	//updating the node's position
	g_posX += g_currentDirectionX;
	g_posY += g_currentDirectionY;

	if (m_time[0] == 0)
	{
		//updating the node's direction
		g_currentDirectionX = m_directionsX[0];
		g_currentDirectionY = m_directionsY[0];
		//erasing the updated direction data
		m_directionsX.erase(m_directionsX.begin());
		m_directionsY.erase(m_directionsY.begin());
		m_time.erase(m_time.begin());
	}
	//updating the time
	for (int i = 0; i < m_time.size(); i++)
	{
		m_time[i]--;
	}
}