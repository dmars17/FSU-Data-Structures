#include <iostream>
#include <string>
#include "tlist.h"
using namespace std;
template <typename T>
void PrintList(const TList<T>& L, string label)
{
    cout << label << " size is: " << L.GetSize() << "\n"
         << label << " = ";
    L.Print(cout);
    cout << "\n\n";
}
int main(){

	cout << "\n**********Generating list with 10 numbers using InsertBack.**********" << endl;
	TList<int> L1; // integer list
  for (int i = 0; i < 10; i++)
		L1.InsertBack(i*2);
  PrintList(L1, "L1");

  cout << "**********Generating list with char using InsertFront.**********" << endl;
	char Alpha = 'Z';
	TList<char> L2;
	for (int i = 0; i < 26; i++){
		L2.InsertFront(Alpha);
		Alpha = (char(int(Alpha-1)));
	}
	PrintList(L2, "L2");
	
	cout << "**********Generating list with strings**********" << endl;
	TList<string> L3;
	L3.InsertFront("Dustin");
	L3.InsertFront("Courtney");
  L3.InsertFront("Kriss");
	L3.InsertBack("Brady");
	L3.InsertBack("Odin");
	L3.InsertBack("Rory");
	PrintList(L3,"L3");

  cout << "**********Testing RemoveBack and RemoveFront from L1, L2, and L3**********" << endl;

	L1.RemoveBack();
  L1.RemoveBack();
	L2.RemoveBack();
	L2.RemoveBack();
	L3.RemoveBack();

	L1.RemoveFront();
	L1.RemoveFront();
	L2.RemoveFront();
	L2.RemoveFront();
	L3.RemoveFront();

	PrintList(L1, "L1");
	PrintList(L2, "L2");
	PrintList(L3, "L3");

	cout << "\n**********Testing iterators traversing a list forwards.**********" << endl;
	TListIterator<int> itr1 = L1.GetIterator();
	cout << "L1 first = " << L1.GetFirst() << endl;
	cout << "L1 Iterator is at " << itr1.GetData() << endl;;
	for (int i = 0; i < L1.GetSize(); i++){
		itr1.Next();
	}
	cout << "\nAfter traveling the list forwards." << endl;
	cout << "L1 last = " << L1.GetLast() << endl;
	cout << "L1 Iterator is at " << itr1.GetData() << endl;

	cout << "\n**********Testing iterators traversing a list backwards.**********" << endl;
	TListIterator<char> itr2 = L2.GetIteratorEnd();
	cout << "L2 Last = " << L2.GetLast() << endl;
	cout << "L2 Iterator is at " << itr2.GetData() << endl;;
	for (int i = 0; i < L2.GetSize()-1; i++){
		itr2.Previous();
	}
	cout << "\nAfter traveling the list backwards." << endl;
	cout << "L2 First = " << L2.GetFirst() << endl;
	cout << "L2 Iterator is at " << itr2.GetData() << endl;


  cout << "\n**********Testing Insert() using iterators**********" << endl;
  itr2 = L2.GetIterator();
	itr1 = L1.GetIterator();

	PrintList(L2, "L2");
	
	itr2.Next();
	itr2.Next();
	cout << "*** Inserting A into L2 ***" << endl;
	L2.Insert(itr2, 'A');
	PrintList(L2, "L2");
	
	itr2.Next();
	itr2.Next();
	itr2.Next();
	itr2.Next();
	cout << "*** Inserting F into L2 ***" << endl;
	L2.Insert(itr2, 'F');
	PrintList(L2, "L2");
	
	itr2.Next();
	itr2.Next();
	itr2.Next();
	itr2.Next();
	itr2.Next();
	cout << "*** Inserting B into L2 ***" << endl;
	L2.Insert(itr2, 'B');
	PrintList(L2, "L2");


	cout << "*** Inserting 555 into L1 ***" << endl;
	L1.Insert(itr1, 555);
	PrintList(L1, "L1");

	itr1.Next();
	cout << "*** Inserting 111 into L1 ***" << endl;
	L1.Insert(itr1, 111);
	PrintList(L1, "L1");

	itr1.Next();
	itr1.Next();	
	cout << "*** Inserting 444 into L1 ***" << endl;
	L1.Insert(itr1, 444);
	PrintList(L1, "L1");
	

	cout << "\n**********Testing Iterator Removes**********" << endl;
	PrintList(L2, "L2");
  itr2 = L2.GetIterator();
	itr1 = L1.GetIterator();


	itr2.Next();
	itr2.Next();
	cout << "*** Removing from L2: " << itr2.GetData() << " ***" << endl;
	itr2 = L2.Remove(itr2);
	PrintList(L2, "L2");

	itr2.Next();
	itr2.Next();
	cout << "*** Removing from L2: " << itr2.GetData() << " ***" << endl;
	itr2 = L2.Remove(itr2);
	PrintList(L2, "L2");
	
	itr2.Next();
	itr2.Next();
	cout << "*** Removing from L2: " << itr2.GetData() << " ***" << endl;
	itr2 = L2.Remove(itr2);
	PrintList(L2, "L2");

	PrintList(L1, "L1");

	itr1.Next();
	cout << "*** Removing from L1: " << itr1.GetData() << " ***" << endl;
	itr1 = L1.Remove(itr1);
	PrintList(L1, "L1");

	itr1.Next();
	itr1.Next();
	cout << "*** Removing from L1: " << itr1.GetData() << " ***" << endl;
	itr1 = L1.Remove(itr1);
	PrintList(L1, "L1");

	itr1.Next();
	cout << "*** Removing from L1: " << itr1.GetData() << " ***" << endl;
	itr1 = L1.Remove(itr1);
	PrintList(L1, "L1");


}
