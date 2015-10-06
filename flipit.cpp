//
// Assignment  :  #1
// Class       :  CST 136
//
// Author      :  Kendra Ash 
//
// File        :  flipit.cpp	
//
//
// Description : Implementation of member functions from flipit.h 
//

#include "flipit.h"

#include  <iostream>
#include <cstdlib>

using  namespace  std;

FlipIt::FlipIt(int nRows, int nCols, int gameNum, int complexity, Pattern	pattern, bool wrap)
	: m_Rows(nRows), m_Cols(nCols), m_wrap(wrap), m_grid(nRows, nCols), m_pattern(pattern)
{
	// Take the gameNum and Complexity and use the rand and srand to pick a starting position. 
	// the complexity determines the number of moves to complete the game. 

	srand(gameNum);
	
	for (int i = 1; i <= complexity; i++)
		FlipIt::click(rand() % m_Rows, rand() % m_Cols);

		cout << "check" << endl;
		cout << m_pattern;
	
}

int FlipIt:: numRows()  const
{
	return m_Rows;
}
int FlipIt::numCols()  const
{
	return m_Cols;
}
 FlipIt::Color FlipIt:: fetch(int row, int col) const
{
	if (m_grid.fetch(row,col))
			return solid_;
		else
			return clear_;
}
void FlipIt::click(int  row, int  col) 
{
	//cout << "Row " << row << " Column " << col<<endl;
	cout << m_pattern << endl;
	
	switch (m_pattern)
	{	
		case cross_:
			
			m_check(row - 1, col);
			m_check(row, col - 1);
			m_check(row, col);
			m_check(row, col + 1);
			m_check(row + 1, col);

			break;
		case x_:
			
			m_check(row - 1, col-1);
			m_check(row-1, col + 1);
			m_check(row, col);
			m_check(row+1, col - 1);
			m_check(row + 1, col+1);
			
			break;
			
		case square_:

			m_check(row - 1, col);
			m_check(row, col - 1);
			m_check(row, col);
			m_check(row, col + 1);
			m_check(row + 1, col);
			m_check(row - 1, col - 1);
			m_check(row - 1, col + 1);
			m_check(row + 1, col - 1);
			m_check(row + 1, col + 1);

			break;
			
		case hollowSquare_:
			

			m_check(row - 1, col);
			m_check(row, col - 1);
			m_check(row, col + 1);
			m_check(row + 1, col);
			m_check(row - 1, col - 1);
			m_check(row - 1, col + 1);
			m_check(row + 1, col - 1);
			m_check(row + 1, col + 1);

			break;
		case corners_:
			
			m_check(row - 1, col - 1);
			m_check(row - 1, col + 1);
			m_check(row + 1, col - 1);
			m_check(row + 1, col + 1);
			break;
			
		}
}

bool FlipIt:: done() const 
{
	bool temp = false;

	for (int i = 0; i >= m_Rows; i++)
	{
		for (int j = 0; j >= m_Cols; j++)
		{
			if (m_grid.fetch(i, j))// if true then means a cell is solid and we return false for done function
				temp = true;
				return temp;
		}
	}
	return temp;
	
}
