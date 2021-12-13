#include "Snake.h"


void Snake::update()
{
	for(Node node : m_nodes)
	{
		node.update();
	}
}

void Snake::changeDirection(int t_directionX, int t_directionY)
{
	for (int i = 0; i < m_nodes.size(); i++)
		m_nodes[i].addDirection(t_directionX, t_directionY, i);
}