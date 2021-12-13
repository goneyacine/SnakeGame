#pragma once
#include <iostream>
#include <vector>
class GridNode
{
public:
	int g_xIndex, g_yIndex;
	//if the current node is a part of the snake body this boolean will be true
	bool g_isSnake;
	GridNode(int t_xIndex, int t_yIndex);
};
class Grid
{
private:
	int m_xSize, m_ySize, m_nodesNum;
	int m_nodeSize[2];
	std::vector<GridNode> m_nodes;
public:
	Grid(int t_xSize, int t_ySize, int t_nodesNum);
	void Update(int t_xSize, int t_ySize);
	int getNodeXSize();
	int getNodeYSize();
	int getNodesNum();
	std::vector<GridNode> getNodes();
};
Grid SetUpGrid(int t_xSize, int t_ySize, int t_nodesNum);
void UpdateGrid(Grid* t_grid, int t_xSize, int t_ySize, HDC* t_hdc, HWND* t_hWnd, PAINTSTRUCT* t_ps);

