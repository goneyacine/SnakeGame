#pragma once
#include <iostream>
#include <vector>
class Node
{
public:
	int m_xIndex, m_yIndex;
	//if the current node is a part of the snake body this boolean will be true
	bool isSnake;
	Node(int xIndex, int yIndex);
};
class Grid
{
private:
	int m_xSize, m_ySize, m_nodesNum;
	int nodeSize[2];
	std::vector<Node> nodes;
public:
	Grid(int xSize, int ySize, int nodesNum);
	void Update(int xSize, int ySize);
	int getNodeXSize();
	int getNodeYSize();
	int getNodesNum();
	std::vector<Node> getNodes();
};
Grid SetUpGrid(int xSize, int ySize, int nodesNum);
void UpdateGrid(Grid* grid, int xSize, int ySize, HDC* hdc, HWND* hWnd, PAINTSTRUCT* ps);

