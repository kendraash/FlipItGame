
//
// Assignment  :  #1
// Class       :  CST 136
//
// Author      :  Kendra Ash 
//
// File        :  flipIt.h
//
//
// Description :  Declarations for the FlipIt game class.
//

#ifndef  flipit_H
#define  flipit_H

#include  <iostream>

#include  "grid.h"
using namespace std; 

class  FlipIt
{
  public  :

    enum  Color  { clear_ = false, solid_ = true };

    enum  Pattern  { cross_, x_, square_, hollowSquare_, corners_ };

    FlipIt( int      nRows,
            int      nCols,
            int      gameNum,
            int      complexity,
            Pattern  pattern,
            bool     wrap );

    int  numRows()  const;
    int  numCols()  const;

    void  click( int  row, int  col );

    Color  fetch( int  row, int  col ) const;

    bool  done() const;

  private  :
	 Pattern m_pattern; 
	 int  m_Rows, m_Cols;
	 Grid m_grid;
	 bool m_wrap;

	 void m_check(int vRow, int vCol)
	 {
		 if (m_wrap == true)
		 {
			 if (vRow < 0)
				 vRow = m_Rows;
			 if (vRow>=m_Rows)
				 vRow = m_Rows - m_Rows;
			 if (vCol < 0)
				 vCol = m_Cols;
			 if (vCol >= m_Cols)
				 vCol = m_Cols - m_Cols;
		 }

		 if (m_wrap == false)
		 {
			 if (vRow < 0)
				 return;
			 if (vRow >= m_Rows)
				 return;
			 if (vCol < 0)
				 return;
			 if (vCol >= m_Cols)
				 return;
		 }
		 cout << "Row " << vRow << " Column " << vCol << endl; // if solid/true then set to clear

		 if (m_grid.fetch(vRow, vCol))
			m_grid.clear(vRow, vCol);
		 else
			 m_grid.set(vRow, vCol); // else/false set solid 

	 }
};


#endif
