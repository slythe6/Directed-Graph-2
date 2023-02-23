// CS311 YOSHII FALL21

//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Simon Hausmaninger
// File type: g++  client hw7client.cpp 
//==========================================

// ** Be sure to include both dgraph  and stack
#include "dgraph.h"
#include "stack.h"
#include <iostream>
using namespace std;
// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // ** copy here the algorithm (read carefully) in the HW7
   // assignment sheet and use that for the comments. 
  /*
  Display the graph before DFS begins.
Push A onto the stack to start.
While the stack is not empty do:
{
    	Remove a vertex v from the stack.
Display the vertex name.  E.G. “Removed B from stack”
If v is not marked yet (visit number is 0) then 
•	mark it (visit it **) and inform the user E.G. “Visit B as 2”
•	get its adjacency list (slist)
o	if no adjacent ones inform the user E.G. “Deadend reached – backup”
o	else put adjacent ones on the stack (delete from the rear and push) informing the user
else inform the user E.G. “B had been visited already - backup.”
Display the stack clearly labeling it as the current stack
    }
    Display the Graph nicely with visit numbers for all vertices
*/
 dgraph table;
 slist tempList;
 stack tableStack;
 int visitNum = 0;
 char vertex;
 string stack = "";

 table.fillTable();
 table.displayGraph();
 tableStack.push('A');

 while(!tableStack.isEmpty())
 {
   tableStack.pop(vertex);
   cout << "\nRemoved " << vertex << " from stack";

   if(!table.isMarked(vertex))
   {
     visitNum++;
     cout << "\nVisit " << vertex << " as " << visitNum;

     table.visit(visitNum, vertex);
     tempList = table.findAdjacency(vertex);

     if(tempList.isEmpty())
     {
       cout << "\nDeadend reached - backup" << endl;
     }
     else
     {
       cout << "...pushing ";
       tempList.displayAll();
       cout << endl;
       while(!tempList.isEmpty())
       {
         tempList.deleteRear(vertex);
         if(!table.isMarked(vertex))
         tableStack.push(vertex); 

       }

     }
   }

   else
   {
     cout << "\n" << vertex << " had been visited already - backup." << endl;
   }
    tableStack.displayAll();
 }
table.displayGraph();
}
