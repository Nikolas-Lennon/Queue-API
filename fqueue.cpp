#include <iostream>
#include <string>
#include "tqueue.h"

void DisplayMenu();

template <typename Queue>
void Assign(const Queue& q);

template <typename Queue>
void Copy(Queue& q);

template <typename Queue>
void Const(const Queue& q);

template <typename Queue>
void Const(Queue& q);


//
//const char* type = "int";
//typedef int ElementType;
//
//const char* type = "char";
//typedef char ElementType;

const char* type = "string";
typedef std::string ElementType;

typedef fsu::Queue <ElementType> QueueType;

QueueType q;

int main()
{

  bool displayMenu = true;
  char selection;
  ElementType tVal;
  q.SetOFC(' ');

  std::cout << "This is a Queue < " << type << " > test program\n";
  DisplayMenu();

  while (displayMenu) {
    std::cout << "Enter [command][argument] ('M' for menu, 'Q' to quit): ";
    std::cin >> selection;
    
    switch (selection)
    {
      case 'M': case 'm': //Menu
        DisplayMenu();
        break;

      case 'q': case 'Q': //Exit
        displayMenu = false;
        std::cout << "\nHave a nice day.\n";
        break;

      case 'd': case 'D':
        std::cout << "Queue Display(): ";
        q.Display(std::cout);
        std::cout << "\n";
        break;
        
      case '+': case '1':
        std::cin >> tVal;
        q.Push(tVal);
        break;

      case '-': case '2':
        q.Pop();
        break;

      case '=':
        Copy(q);
        Assign(q);
        Const(q);
        break;

      case 'c': case 'C':
        q.Clear();
        break;

      case 'S': case 's':
        std::cout << "Queue size     = " << q.Size() << "\n";
        break;

      case 'e': case 'E':
        if (q.Empty()) {
          std::cout << "Queue is empty\n";
        }
        else
          std::cout << "Queue is not empty\n";
        break;

      case 'f': case 'F':
        if (q.Empty()) {
          std::cout << "Front of Queue: " << q.Front() << "\n";
        }
        else {
          std::cout << "Front of Queue: " << q.Front() << "\n";
        }
        break;

      case 'o': case 'O':
        char ofc;
        std::cin >> ofc;

        if (ofc == '0')ofc = '\0';
        else if (ofc == 'b' || ofc == 'B')ofc = ' ';
        else if (ofc == 't' || ofc == 'T')ofc = '\t';
        else if (ofc == 'n' || ofc == 'N')ofc = '\n';
        else {
          std::cerr << " ** bad ofc: only 0, b|B, t|T, n|N accepted\n";
        }
        q.SetOFC(ofc);
        break;

      case 'u': case 'U':
        std::cout << "Queue    Dump(): ";
        q.Dump(std::cout);
        std::cout << "\n";
        break;

      default: //Error
        std::cerr << "** Unrecognized command -- please try again.\n";
        break;
    }
    
  }
  
  //  std::cout << "\n";
  //return 0;

}

void DisplayMenu()
{

  std::cout << "Push (Tval)   .............  + tval or 1 tval\n";
  std::cout << "Pop()  ..................  - or 2\n";
  std::cout << "Clear()  ................  C\n";
  std::cout << "Front()  ................  F\n";
  std::cout << "Empty()  ................  E\n";
  std::cout << "Size()  .................  S\n";
  std::cout << "Copy tests  .............  =\n";
  std::cout << "Display()  ..............  D\n";
  std::cout << "SetOFC(ofc)  ............  O 0|b|t|n\n";
  std::cout << "Dump()  .................  U\n";
  std::cout << "Display this menu  ......  M\n";

}

template<typename Queue>
void Assign(const Queue & q)
{
  Queue q2;

  q2 = q;

  std::cout << "AssignTest:" << "\n";
  std::cout << "Original object     size: " << q.Size();
  std::cout << "\n";
  std::cout << "                contents: "; q.Display(std::cout);

  std::cout << "\n";

  std::cout << "Assignee object     size: " << q2.Size() << "\n";
  std::cout << "                contents: "; q2.Display(std::cout);
  std::cout << "\n";
}

template<typename Queue>
void Const(Queue & q)
{
  if (q.Size() != 0)
  {
    std::cout << "ConstTest: OK" << "\n";
  }
  else {
    std::cout << "ConstTest: inactive on an empty queue\n";
  }
}

template<typename Queue>
void Copy(Queue & q)
{
  std::cout << "Copy Test:\n";
  std::cout << "Copied object       size: " << q.Size();
  std::cout << "\n";
  std::cout << "                contents: "; q.Display(std::cout);
  std::cout << "\n";
}
