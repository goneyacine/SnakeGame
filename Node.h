#pragma once

#include<iostream>
#include<vector>


class Node
{
private:
   	std::vector<int> m_directionsX,m_directionsY,m_time;
public:
	int g_currentDirectionX, g_currentDirectionY, g_posX, g_posY;


	void addDirection(int t_directionX,int t_directionY,int t_delay);
	void update();
};