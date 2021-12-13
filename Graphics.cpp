#include <iostream>
#include <vector>
#include <Windows.h>
#include "Graphics.h"

	GridNode::GridNode(int t_xIndex, int t_yIndex)
	{
		g_xIndex = t_xIndex;
		g_yIndex = t_yIndex;
	}

	Grid::Grid(int t_xSize,int t_ySize,int t_nodesNum)
	{
		//some default stuff to do when initializing the grid
		m_xSize = t_xSize;
		m_ySize = t_ySize;
		m_nodesNum = t_nodesNum;
        m_nodeSize[0] =  t_xSize / t_nodesNum;
		m_nodeSize[1] = t_ySize / t_nodesNum;

		for (int i = 0; i < t_nodesNum; i++)
		{
			for (int j = 0; j < t_nodesNum; j++) {
				m_nodes.push_back(GridNode(i,j));
			}
		}
    }
	void Grid::Update(int t_xSize, int t_ySize)
	{
		//updating the grid size
		m_xSize = t_xSize;
	    m_ySize = t_ySize;

		//updating the nodes sizes acording to the new grid size
		m_nodeSize[0] = t_xSize / m_nodesNum;
		m_nodeSize[1] = t_ySize / m_nodesNum;
	}
	int Grid::getNodeXSize()
	{
		return m_nodeSize[0];
	}
	int Grid::getNodeYSize()
	{
		return m_nodeSize[1];
	}
	int Grid::getNodesNum()
	{
		return m_nodesNum;
	}
	std::vector<GridNode> Grid::getNodes()
	{
		return m_nodes;
	}
	//this function is used to initialize a grid 
	 Grid SetUpGrid(int t_xSize, int t_ySize, int t_nodesNum)
	{
		return Grid(t_xSize, t_ySize, t_nodesNum);
	}

//used to draw the grid into the screen
void DrawGrid(Grid* t_grid, HDC* t_hdc, HWND* t_hWnd, PAINTSTRUCT* t_ps);

//this function is used whenever the screen size is updated
void UpdateGrid(Grid* t_grid,int t_xSize,int t_ySize,HDC* t_hdc,HWND* t_hWnd,PAINTSTRUCT* t_ps)
{
	t_grid->Update(t_xSize,t_ySize);
	DrawGrid(t_grid, t_hdc, t_hWnd, t_ps);
}
void DrawGrid(Grid* t_grid,HDC* t_hdc,HWND* t_hWnd,PAINTSTRUCT* t_ps)
{
	*t_hdc = BeginPaint(*t_hWnd, t_ps);


	for (int i = 0; i < t_grid->getNodesNum(); i++)
	{
		int leftXPosition = i * t_grid->getNodeXSize() + 4;
		int rightXPosition = (i + 1) * t_grid->getNodeXSize() + 4;

		for (int j = 0; j < t_grid->getNodesNum(); j++)
		{
			int topYPosition = j * t_grid->getNodeYSize() + 4                                                                                                                                                                      ;
			int buttonYPosition = (j + 1) * t_grid->getNodeYSize() + 4;

			 Rectangle(*t_hdc, leftXPosition, topYPosition, rightXPosition, buttonYPosition);
			// break;
		}
		//break;

	}
	EndPaint(*t_hWnd, t_ps);
}