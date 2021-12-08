#include <iostream>
#include <vector>
#include <Windows.h>
#include "Graphics.h"

	Node::Node(int xIndex, int yIndex)
	{
		m_xIndex = xIndex;
		yIndex = yIndex;
	}

	Grid::Grid(int xSize,int ySize,int nodesNum)
	{
		//some default stuff to do when initializing the grid
		m_xSize = xSize;
		m_ySize = ySize;
		m_nodesNum = nodesNum;
        nodeSize[0] =  xSize / nodesNum;
		nodeSize[1] = ySize / nodesNum;

		for (int i = 0; i < nodesNum; i++)
		{
			for (int j = 0; j < nodesNum; j++) {
				nodes.push_back(Node(i,j));
			}
		}
    }
	void Grid::Update(int xSize, int ySize)
	{
		//updating the grid size
		m_xSize = xSize;
	    m_ySize = ySize;

		//updating the nodes sizes acording to the new grid size
		nodeSize[0] = xSize / m_nodesNum;
		nodeSize[1] = ySize / m_nodesNum;
	}
	int Grid::getNodeXSize()
	{
		return nodeSize[0];
	}
	int Grid::getNodeYSize()
	{
		return nodeSize[1];
	}
	int Grid::getNodesNum()
	{
		return m_nodesNum;
	}
	std::vector<Node> Grid::getNodes()
	{
		return nodes;
	}
	//this function is used to initialize a grid 
	 Grid SetUpGrid(int xSize, int ySize, int nodesNum)
	{
		return Grid(xSize, ySize, nodesNum);
	}

//used to draw the grid into the screen
void DrawGrid(Grid* grid, HDC* hdc, HWND* hWnd, PAINTSTRUCT* ps);

//this function is used whenever the screen size is updated
void UpdateGrid(Grid* grid,int xSize,int ySize,HDC* hdc,HWND* hWnd,PAINTSTRUCT* ps)
{
	grid->Update(xSize,ySize);
	DrawGrid(grid, hdc, hWnd, ps);
}
void DrawGrid(Grid* grid,HDC* hdc,HWND* hWnd,PAINTSTRUCT* ps)
{
	*hdc = BeginPaint(*hWnd, ps);


	for (int i = 0; i < grid->getNodesNum(); i++)
	{
		int leftXPosition = i * grid->getNodeXSize() + 4;
		int rightXPosition = (i + 1) * grid->getNodeXSize() + 4;

		for (int j = 0; j < grid->getNodesNum(); j++)
		{
			int topYPosition = j * grid->getNodeYSize() + 4;
			int buttonYPosition = (j + 1) * grid->getNodeYSize() + 4;

			 Rectangle(*hdc, leftXPosition, topYPosition, rightXPosition, buttonYPosition);
			// break;
		}
		//break;

	}
	EndPaint(*hWnd, ps);
}