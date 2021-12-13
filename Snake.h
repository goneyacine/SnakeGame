#pragma once
#include "Node.h"
#include<iostream>
#include<vector>

class Snake 
{
private: 
	std::vector<Node> m_nodes;

public:
	void update();
	void changeDirection(int t_directionX, int t_directionY);

};