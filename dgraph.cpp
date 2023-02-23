//CS311 Yoshii FALL21 dgraph.cpp 
// INSTRUCTION:
//   Complete all the functions you listed in dgraph.h
//   Comment the file completely using How to Comment file.
//   Use HW6-help.docx to finish the functions.
//  NEVER delete my comments!!!
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Simon Hausmaninger
// File Type: g++
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"
#include <iomanip>

dgraph::dgraph()
 // initialize vertexName (blank) and visit numbers (0) for all slots of the table
 // initialize countUsed to be 0
{
  for(int x = 0; x < SIZE; x++)
  {
    Gtable[x].vertexName = ' ';
    Gtable[x].outDegree = 0;
    Gtable[x].visit = 0;
  }
  countUsed = 0;
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
}

void dgraph::fillTable()  // be sure to read from a specified file
// you will have to use a linked list function addRear. 
{
  string fname;
  char x;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname

  // the rest is in HW6-help
while(fin >> Gtable[countUsed].vertexName)  // IF I CAN READ THE NAME
    { 
      fin >> Gtable[countUsed].outDegree;

      //Then for the OutDegree times (for-loop):
      for(int i = 0; i < Gtable[countUsed].outDegree; i++)
	{
	  fin >> x;
	  (Gtable[countUsed].adjacentOnes).addRear(x);   // this is a slist function from HW3
        }
  
      // update
      countUsed++;
    }

  fin.close();
}


void dgraph::displayGraph() // be sure to display
// you will have to use a linked list function displayAll. 
{// in a really nice table format -- all columns but no unused rows and include the total number of edges at the top 
// display graph
  cout << "\n Out Visit\tAdj\n";
  cout << " ----------------------\n";

  // in a really nice table format -- all columns but no unused rows 
  for(int i = 0; i < countUsed; i++)
    {
      cout << " " << Gtable[i].vertexName << "   " << Gtable[i].outDegree;
      cout << "  \t" << Gtable[i].visit << "\t";
      (Gtable[i].adjacentOnes).displayAll();
    }
}

int dgraph::findOutDegree(char V)// throws exception if not found
{// does not use a loop - go directly to a slot using V
  int index = (int) V - 65;

  if(index < countUsed && index >= 0)
  {
    return Gtable[index].outDegree;
  }
  else throw BadVertex();
}

slist dgraph::findAdjacency(char V)// throws exception if not found
{// does not use a loop - go directly to a slot using V
  int index;
  index = (int) V - 65;

  slist list;
  list = Gtable[index].adjacentOnes;

  if(index < countUsed && index >= 0)
  {
    return list;
  }else
  throw BadVertex();
}

void dgraph::visit(int visitNum, char visitName)
{
  if(!isMarked(visitName))
  {
    Gtable[visitName -  65].visit = visitNum;
  }
}

bool dgraph ::isMarked(char visitCheck)
{
  if(Gtable[visitCheck - 65].visit != 0)
  {
    return true;
  } else return false;
}
