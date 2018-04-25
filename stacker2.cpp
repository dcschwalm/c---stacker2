#include <iostream>      

#include "stack.h"

/*********************************************
  A Stack Class implementation with testing main.
  
  Part A of Prog Ass#1.

   Last Updates: 10/30/14  Stacker1.cpp

********************************************/   

using namespace std;

//*****  TRACE FLAG *************
bool TRACE = false;  // turn TRACE on or off
//*******************************

//***** Prototypes **************
int main(void);
// **** STACK CLASS DEFINITIONS ****
//==== DEFAULT CONSTR =====================
STACK::STACK(void)
{ if (TRACE)
     cout << " === DEFAULT CONSTR ===" << endl; // a TRACE
  
  initStack(10);  // use utility method to set attributer values
}
//==== COPY CONSTR ========================
STACK::STACK(const STACK & s)
{
    if (TRACE)
	   cout << " === COPY CONSTR ===" << endl; // a TRACE

	//SHALLOW COPY STUFF TO REPLACE SYSTEM SHALLOW COPY
	top =  s.top;
	max = s.max;

	
    //DEEP COPY STUFF (if needed)
	rep = new int[max];  // create on HEAP
	for (int i=0; i < max; i++)
	{
	   rep[i] = s.rep[i];
	}  
}                                
//==== DESTRUCTOR =========================
STACK::~STACK(void)
{
  if (TRACE)
     cout << " === DESTRUCTOR ===" << endl; // a TRACE
}
//==== ASSIGNMENT OPERATOR =================
const STACK &  STACK::operator=(const STACK & s)
{
     if (TRACE)
         cout << " === ASSIGNMENT ===" << endl; // a TRACE
		 
    if ( this != &s)  // test for s = s
    {
	   // Shallow
	   top =  s.top;
	   max =  s.max;
	   // Deep
	   delete[] rep;    // Remove old stack from HEAP
	   rep = new int[max];  // create on HEAP
	   for (int i=0; i < max; i++)
	   {
	     rep[i] = s.rep[i];
	   }  
	   
	}   
	 
    return  *this;	 
}
//==== USER DEFINED CONSTRUCTORS ==========
STACK::STACK(const int size)
{
  initStack(size);
}

//==== UTILITY METHOD(S) ====================
void STACK::initStack(const int size)
{
  top = -1;   
  max = size;
  rep = new int[max];
}
//==== PUSH METHOD ========================
void STACK::push(int x)
{
   
   top = top + 1;  // set new top location
   rep[top] = x;   // push onto top of stack
}
//==== POP METHOD =========================
int STACK::pop(void)
{  top = top - 1;
   return rep[top + 1];
 }  
//==== isEmpty METHOD =====================
bool  STACK::isEmpty(void)
{
  if (getDepth() > 0)
     return false;
  return true;	 
}
//==== isFull METHOD =====================
bool  STACK::isFull(void)
{
  if (top < max - 1 )
     return false;
  return true;	 
}
//==== getDepth METHOD  (derived attr.) ==
int STACK::getDepth(void)
{
  return top + 1;
}
//==== getMAX METHOD =====================
int STACK::getSize(void)
{
  return max;
}
// ***** END STACK CLASS ******************

//=====================================================
//=====================================================
//==== NORMAL FUNCTIONS FOR TESTING STACK CLASS =======
//=====================================================
//=====================================================
// ==== Prototypes =======
int main(void);
void mypause();
void test1(void);

//========================
void mypause(void)
{ 
  int dummy;
  cout << endl <<  "pause -> " ;	
  cin >> dummy;  // pause 
  cout << endl;
}
//---- TEST 1 -------------------------------------
void test1(void)
{
  STACK s1(12);
  
  for (int i = 0; i < s1.getSize(); i++)
  {
    s1.push(i+1);
  }

  STACK s2(6);
  
   for (int i = 0; i < s2.getSize(); i++)
  {
    s2.push(i+1);
  }

  while (!s2.isEmpty())
  {
    cout << s2.pop() << " ";
  }
  cout << endl;
  
  s2 = s1;
  
    while (!s2.isEmpty())
  {
    cout << s2.pop() << " ";
  }
  cout << endl;
  
}


//----------  MAIN PROGRAM ----------------------------
int main(void)
{
  cout << endl;
  cout << "===================================" << endl;
  cout << "    Dave Schwalm   Prog Ass #1 a " << endl; 
  cout << "===================================" << endl << endl;  

  test1();
  
  cout << endl;
  cout << "===================================" << endl << endl;  
 
  return 0;  // EXIT_SUCCESS
}















