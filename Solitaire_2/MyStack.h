#pragma once
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

template<typename T>
class MyStack
{
private:
	stack<T*> un_rev;
	vector<T*>rev;
	Texture CB;
	Sprite CardBAck;

public:


	MyStack() :un_rev(), rev()
	{

	}

	MyStack(int siz) :un_rev(siz - 1), rev(1)
	{
	}

	void PushRevealed(vector<T*>& A)
	{
		for (int i = 0; i < A.size(); i++)
		{
			rev.push_back(A[i]);
		}
		A.clear();
	}

	void PushElem(T* A)
	{
		if (!rev.empty())
		{
			T* temp = rev[0];
			rev.pop_back();
			un_rev.push(temp);
			rev.push_back(A);
		}
		else
			rev.push_back(A);
	}

	void PopElement()
	{
		if (rev.empty() && un_rev.empty())
			abort;

		if (!rev.empty())
			rev.pop_back();		
	}
	void PopRange(int si)
	{

		if (rev.empty() && un_rev.empty())
			abort();

		if (!rev.empty())
			rev.erase(rev.begin() + si, rev.end());

		if (rev.empty() && !un_rev.empty())
		{
			T* temp = un_rev.top();
			rev.push_back(temp);
			un_rev.pop();
		}
	}

	T* operator[] (int i)
	{
		//int index = un_rev.size() - i - 1;
		return rev[i];
	}
	
	int getRevealedSize()
	{
		return rev.size();
	}
	int getUnRevealedSize()
	{
		return un_rev.size();
	}
	void RevealNext()
	{
		if (rev.empty() && !un_rev.empty())
		{
			T* temp = un_rev.top();
			rev.push_back(temp);
			un_rev.pop();
		}
	}
	T* Top()
	{
		return rev.back();
	}

	bool IsEmpty()
	{
		if (rev.empty() && un_rev.empty())
			return true;
		return false;
	}

};


