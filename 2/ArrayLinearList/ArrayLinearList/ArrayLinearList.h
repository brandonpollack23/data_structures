/* Brandon Pollack
Section 1087
UFID 2375-4365
Assignment 2
*/
#include <sstream>
#include <string> //used for tostring
#include <algorithm> //need this for copy
#include <stdexcept> //throw exceptions when necessary in constructors

using namespace std;

#ifndef ARRLINLIST
#define ARRLINLIST

template <class T>
class ArrayLinearList
{
	int size, capacity;
	T *elements;
public:
	/*ArrayLinearList() dead code, obsolete by default value of next constructor
	{
		capacity = 10; //constructed, default number of elements is 10
		size = 0; //there are no elements in the array now so size is 0
		elements = new T[capacity]; //make a new array of that capacity
	}*/ 

	ArrayLinearList(int const cap = 10) //declare with a specific initial capacity, default of 10
	{
		if(cap <= 0) throw domain_error("Capacity must be a natural number\n");
		capacity = cap;
		size = 0;
		elements = new T[capacity];
	}

	template <int N>
	ArrayLinearList(T (&initArray)[N]) //template so that any size array can be taken
	{
		size = N; //size is equal to size of array
		if (size < 0) throw domain_error("Must input an array of size greater than or equal to 1\n");
		capacity = size*3/2; //make the total capacity 50% bigger
		elements = new T[capacity]; //allocate that many on the heap
		copy(initArray,initArray+N,elements); //copy the initArray over
	}

	~ArrayLinearList()
	{
		delete[] elements;
	}

	void ensureCapacity(int const newSize)
	{
		if (newSize <= 0) throw domain_error("The new size must be a natural number\n");
		if(newSize > capacity)
		{
			int newCap = capacity*3/2; //make the capacity 50% larger
			T *newElements = new T[newCap]; //allocate a new array of that size, thanks OS!
			copy(elements,elements+size,newElements); //this copy function operates the same as the for loop
			/*for(int i  = 0; i < newCap; i++)
			{
				newElements[i] = elements[i]; //copy all the elements to the new array
			}*/
			delete[] elements;
			elements = newElements;
			capacity = newCap;
		}
	}

	void insertElement(T const element, int const index)
	{
		if(index <= size && index >= 0) //checks if that index is in bounds
		{
			ensureCapacity(++size); // make sure there is enough capacity for this new size
			for(int i = size-1; i > index; i--) //from the last element in the array to the index
			{
				elements[i] = elements[i-1]; //copy all elements up the list to make room
			}
			elements[index] = element; //put element in that index
		}
		else cout << "That index is out of bounds\n"; //if there isnt space, say so
	}

	void deleteElement(int const index)
	{
		if(index < size) //if that element is in this array
		{
			for(int i = index; i < size; i++) //for everything from this element to the last
			{
				elements[i] = elements[i+1]; //copy from the next to the left, over the element
			}
			size--; //one less in size
			if (size == 0) //if there was only one element null out the first index and set the size to 0
			{
				elements[0] = NULL;
			}
		}
		else cout << "That index is out of bounds\n"; //no element of that index, say so
	}

	void toString() const
	{
		if(size == 0) cout << "The ArrayLinearList is empty\n";
		else
		{
			stringstream str;
			str << '[';
			for(int i = 0; i < size; i++)
			{
				str << elements[i];
				str << ", ";
			}
			string tostring = str.str();
			tostring.erase(tostring.size()-1);
			tostring.erase(tostring.size()-1); //erase the extra comma and space
			tostring += ']';
			cout << tostring << endl; //no need to delete tostring because it was not allocated with new, automatically deconstructed at the end of the function
		}
	}

	void printElement(int const index) const
	{
		if (index < size)
		{
			cout << elements[index] << endl;
		}
		else cout << "That index is out of bounds\n";
	}

	void printSize() const
	{
		cout << size << endl;
	}

	void printMax() const
	{
		T answer = elements[0];
		for(int i = 1; i < size; i++)
		{
			if(answer > elements[i]) answer = elements[i];
		}
		cout << answer << endl;
	}

	void printMin() const
	{
		T answer = elements[0];
		for(int i = 1; i < size; i++)
		{
			if(answer < elements[i]) answer = elements[i];
		}
		cout << answer << endl;
	}

	/*T operator[] (int const i) const //getter
	{
		return elements[i];
	}*/

	T& operator[] (int const i) //set, returns a reference to the location, so when you say list[x] = y then the list[x] breaks down to a reference to that location and puts y there
	{
		if(i >= size)
		{
				ensureCapacity(++size);
		}
		return elements[i];
	}

	T* const copyToArray() //make a copy of the internal array and then return the ponter to that
	{
		T answer[size];
		copy(elements, elements + size, answer);
		return answer;
	}

	bool const isEmpty()
	{
		if (size == 0) return true;
		else return false;
	}

	int const indexOf(T& element) const //returns the index where this element first occurs
	{
		for (int i = 0; i < size; i++)
		{
			if (elements[i] == element)
			{
				return i;
			}
		}
		return -1; //return -1 if it does not exist
	}

};
#endif