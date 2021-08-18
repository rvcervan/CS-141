#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <initializer_list>
#include <iterator>
#include <string>
using namespace std;

template
	<typename T> //Assume Vector only takes in int or double for T

class Vector
{
private:
	int sz; //the number of elements in this Vector
	T* buf; //the base of the array of T's, you must allocate it
public:
	Vector(int n) //Vector v1(10); -- create a 10 element Vector
		: sz{0}, buf(new T[n])
	{
	}
	Vector(initializer_list<T> L) // Vector v1{T1, T2, T3};
	{
		int i = 0;
		buf = new T[L.size()];
		typename initializer_list<T>::iterator it;
		for(it=L.begin(); it!=L.end(); ++it)
		{
			//cout << "from L " << *it << endl;
			buf[i] = *it;
			//cout << "from i " << i << endl;
			if(i < L.size()){++i;}
		}
		sz = L.size();
		/*
		for(int x = 0; x < L.size(); ++x)
		{
			cout << buf[x] << endl;
		}
		*/
		
	}
	~Vector() // destructor called automatically when a Vector dies
	{
		delete[] buf;
	}
/*	Destructor should free memory used. Your program should have no
 *	leak/lost/still-reachable/errors(suppressed or not), besides
 *	72704 bytes in one still-reachable block (a g++/valgrind bug on some versions).
*/
	Vector(const Vector & v) // Vector v2(v1); deep-copy
	{
		//delete[] buf;
		buf = new T[v.size()];
		for(int i = 0; i < v.size(); ++i)
		{
			buf[i] = v[i];
		}
		sz = v.size();
	
	}
	int size() const // v1.size() returns 10 for v1 example above
	{
		return sz;	
	}
	T & operator [] (const int i) // T x = V[i];
	{
		//im not sure
		return buf[i];
		//throw error if out of bounds
	}
	
	T & operator [] (const int i) const // T x = V[i];
	{
		//im not sure
		return buf[i];
		//throw error if out of bounds
	}


	//Access out-of-bound index should throw an error to be caught in outside scope
	T operator * (const Vector & v) const
	{
		
		// if any vector is size 0 return 0
		if(v.size() == 0 || sz == 0){return 0;}

		int smollest = 0;
		T dot = 0;

		if(v.size()<sz){smollest = v.size();}
		else{smollest = sz;}
	
		for(int i = 0; i < smollest; ++i)
		{
			T temp = 0;
			temp = v[i] * buf[i];
			dot += temp;
		}
		return dot;	
	}
	//T x = V1 * V2; dot product
	//e.g. [1, 2] * [3, 4, 5] = 1 * 3 + 2 * 4 + 0 = 11
	//Assume an empty Vector will cause the product to be 0
	Vector operator + (const Vector & v) const
	// V3 = V1 + V2; [1, 2, 3] + [4, 5, 6, 7] = [5, 7, 9, 7]
	{	
		if(sz < v.size())
		{
			for(int i = 0; i < sz; ++i)
			{
				v[i] = buf[i] + v[i];
			}
			return v;
		}
		else
		{
			for(int i = 0; i < v.size(); ++i)
			{
				buf[i] = buf[i] + v[i];
			}
			return *buf;
		}
	}
	const Vector & operator = (const Vector & v) // V1 = V2;
	{
		delete[] buf;
		buf = new T[v.size()];
		for(int i = 0; i < v.size(); ++i)
		{
			buf[i] = v[i];
		}
		sz = v.size();
		return v;
	}
	bool operator == (const Vector & v) const // if (V1 == V2)...
	{
		if(v.size() != sz){return false;}
		else
		{
			for(int i = 0; i < v.size(); ++i)
			{
				if(v[i] != buf[i]){return false;}
			}
		}
		return true;
	}	
	bool operator != (const Vector & v) const // if (V1 != V2)...
	{
		if(v == buf){return false;}
		return true;
	}


	friend Vector operator * (const int n, const Vector & v)
	// V1 = 20 * V2; -- each element of V1 is element of V2 * 20
	{
		for(int i = 0; i < v.size(); ++i)
		{
			v[i] = v[i] * n;
		}
		return v;
	}
	friend Vector operator + (const int n, const Vector & v)
	// V1 = 20 + V2; -- each element of V1 is element of V2 + 20
	{
		
		for(int i = 0; i < v.size(); ++i)
		{
			v[i] = v[i] + n;
		}
		return v;
	}

	friend ostream& operator << (ostream & o, const Vector & v)
	// cout << V2; -- prints the vector in this format
	// (v0, v1, v2, ... vn-1);
	{
		string content = "(";	
		
		for(int i = 0; i < v.size(); ++i)
		{ 
			content += to_string(v[i]);
			content += ", ";
		}
		content.pop_back();
		content.pop_back();
		content += ")";
		return o << content;
	}
	

};
#endif
	
