#pragma once
#include"pch.h"
template<class T>
struct Link_Node
{
	Link_Node<T>* rlink=nullptr;
	T data;
};
template<class T>
struct Seq_Node
{
	T* rlink = nullptr;
	int data = 0;
};
template<class T>
class list
{
public:
	list(){}
	~list(){}
	virtual bool insert(int a, T b) = 0;
	virtual bool insert(T a, T b, int c) = 0;
	virtual bool ins(T a, T b) = 0;
	virtual void reverse()=0;
	virtual bool del(int a) = 0;
	virtual bool deldata(T a) = 0;
	virtual bool deldata(T a, int b) = 0;
	virtual void push_back(T a) = 0;
	virtual Link_Node<T>* getlinkhead()=0;
	virtual Seq_Node<T>* getseqhead()=0;
	virtual int getlast() = 0;
	virtual T getworth(int n) = 0;
	virtual void delcf() = 0;
};
template<class T>
class Seqlist:public list<T>
{
private:
	Seq_Node<T>* head;
	int last;
public:
	Seqlist();
	~Seqlist();
	virtual void push_back(T a) ;
	virtual bool insert(int a, T b);
	virtual bool insert(T a, T b,int c);
	virtual bool ins(T a, T b);
	virtual void reverse();
	virtual bool del(int a);
	virtual bool deldata(T a);
	virtual bool deldata(T a, int b);
	virtual Seq_Node<T>* getseqhead();
	virtual Link_Node<T>* getlinkhead();
	virtual int getlast() { return last; }
	virtual T getworth(int n)
	{
		return head->rlink[n];
	}
	virtual void delcf()
	{

	}
};
template<class T>
class Linklist :public list<T>
{
private:
	Link_Node<T>* head;
	Link_Node<T>* last;
public:
	Linklist();
	~Linklist();
	virtual void push_back(T a);
	virtual bool insert(int a, T b);
	virtual bool insert(T a, T b, int c);
	virtual bool ins(T a, T b) ;
	virtual void reverse();
	virtual bool del(int a) ;
	virtual bool deldata(T a) ;
	virtual bool deldata(T a, int b) ;
	virtual Link_Node<T>* getlinkhead();
	virtual Seq_Node<T>* getseqhead();
	virtual int getlast() { return 0; }
	virtual T getworth(int n)
	{
		return head->rlink->data;
	}
	virtual void delcf();
};




//Ë³Ðò±í

template<class T>
Seqlist<T>::Seqlist()
{
	head = new Seq_Node<int>;
	head->data = 0;
	last = -1;
}

template<class T>
Seqlist<T>::~Seqlist()
{
	delete[] head->rlink;
	delete head;
}

template<class T>
void Seqlist<T>::push_back(T a)
{
	if (last == head->data - 1)
	{
		T* p = new T[head->data + 1];
		for (int i = 0; i <= last; i++)
		{
			p[i] = head->rlink[i];
		}
		p[head->data] = a;
		(head->data)++;
		last++;
		delete[] head->rlink;
		head->rlink = p;
	}
	else
	{
		head->rlink[++last] = a;
	}
}

template<class T>
bool Seqlist<T>::insert(int a, T b)
{
	if (last < head->data - 1)
	{
		for (int i = last + 1; i > a; i--)
		{
			head->rlink[i] = head->rlink[i - 1];
		}
		head->rlink[a] = b;
		last++;
		return true;
	}
	else
		return false;
}

template<class T>
bool Seqlist<T>::insert(T a, T b, int c)
{
	if (last < head->data - 1)
	{
		for (int j = 0; j <= last; j++)
		{
			if (head->rlink[j] == a)
			{
				for (int i = last + 1; i > j+1; i--)
				{
					head->rlink[i] = head->rlink[i - 1];
				}
				head->rlink[j+1] = b;
				last++;
				return true;
			}
		}
	}
	else
		return false;
}

template<class T>
inline bool Seqlist<T>::ins(T a, T b)
{
	bool flag = false;
	if (last < head->data - 1)
	{
		for (int j = 0; j <= last; j++)
		{
			if (head->rlink[j] == a&& last < head->data - 1)
			{
				for (int i = last + 1; i > j + 1; i--)
				{
					head->rlink[i] = head->rlink[i - 1];
				}
				head->rlink[j + 1] = b;
				last++;
				if (a == b)
					j++;
				flag = true;
			}
		}
	}
	return flag;
}

template<class T>
void Seqlist<T>::reverse()
{
	for (int i = 0; i < (last + 1) / 2; i++)
	{
		T temp = head->rlink[i];
		head->rlink[i] = head->rlink[last - i];
		head->rlink[last - i] = temp;
	}
}

template<class T>
bool Seqlist<T>::del(int a)
{
	if (a <= last)
	{
		for (int i = a; i < last; i++)
		{
			head->rlink[i] = head->rlink[i + 1];
		}
		--last;
		return true;
	}
	else
		return false;
}

template<class T>
bool Seqlist<T>::deldata(T a)
{
	for (int j = 0; j <= last; j++)
	{
		if (head->rlink[j] == a)
		{
			for (int i = j; i < last; i++)
			{
				head->rlink[i] = head->rlink[i + 1];
			}
			last--;
			return true;
		}
	}
	return false;
}

template<class T>
bool Seqlist<T>::deldata(T a, int b)
{
	bool flag = false;
	for (int j = 0; j <= last; j++)
	{
		if (head->rlink[j] == a)
		{
			for (int i = j; i < last; i++)
			{
				head->rlink[i] = head->rlink[i + 1];
			}
			last--;
			j--;
			flag = true;
		}
	}
	return flag;
}

template<class T>
inline Seq_Node<T>* Seqlist<T>::getseqhead()
{
	return head;
}

template<class T>
inline Link_Node<T>* Seqlist<T>::getlinkhead()
{
	return NULL;
}



//Á´±í
template<class T>
Linklist<T>::Linklist()
{
	head = new Link_Node<T>;
	last = new Link_Node<T>;
	head->data = 0;
	last->rlink = head;
}

template<class T>
Linklist<T>::~Linklist()
{
	delete head->rlink;
	delete last;
	delete head;
}

template<class T>
void Linklist<T>::push_back(T a)
{
	last->rlink->rlink = new Link_Node<T>;
	last->rlink->rlink->data = a;
	last->rlink = last->rlink->rlink;
}

template<class T>
bool Linklist<T>::insert(int a, T b)
{
	int n = 0;
	Link_Node<T>* current = head;
	while (current->rlink != nullptr)
	{
		if (a == n)
		{
			Link_Node<T>* p = new Link_Node<T>;
			p->data = b;
			p->rlink = current->rlink;
			current->rlink = p;
			return true;
		}
		++n;
		current = current->rlink;
	}
	return false;
}

template<class T>
bool Linklist<T>::insert(T a, T b, int c)
{
	bool flag = false;
	Link_Node<T>* current = head->rlink;
	while (current->rlink != nullptr)
	{
		if (current->data == a&&!flag)
		{
			Link_Node<T>* p = new Link_Node<T>;
			p->data = b;
			p->rlink = current->rlink;
			current->rlink = p;
			flag = true;
		}
		current = current->rlink;
	}
	last->rlink = current;
	return flag;
}

template<class T>
inline bool Linklist<T>::ins(T a, T b)
{
	bool flag = false;
	Link_Node<T>* current = head->rlink;
	while (current->rlink != nullptr)
	{
		if (current->data == a)
		{
			Link_Node<T>* p = new Link_Node<T>;
			p->data = b;
			p->rlink = current->rlink;
			current->rlink = p;
			flag = true;
		}
		if (a == b)
		{
			current = current->rlink;   
		}
		current = current->rlink;
	}
	if (current->data == a)
	{
		Link_Node<T>* p = new Link_Node<T>;
		p->data = b;
		p->rlink = current->rlink;
		current->rlink = p;
		current = current->rlink;
		flag = true;
	}
	last->rlink = current;
	return flag;
}

template<class T>
void Linklist<T>::reverse()
{
	last->rlink = head->rlink;
	Link_Node<T>* current = head->rlink;
	Link_Node<T>* pre;
	Link_Node<T>* next = current->rlink;
	while (next != nullptr)
	{
		pre = current;
		current = next;
		next = current->rlink;
		current->rlink = pre;
	}
	head->rlink = current;
	last->rlink->rlink = nullptr;
}

template<class T>
bool Linklist<T>::del(int a)
{
	bool flag = false;
	int n = 0;
	Link_Node<T>* current = head;
	while (current->rlink != nullptr)
	{
		if (a == n)
		{
			Link_Node<T>* p = current->rlink;
			current->rlink = current->rlink->rlink;
			p->rlink = nullptr;
			delete p;
			flag = true;
		}
		++n;
		if (current->rlink != nullptr)
			current = current->rlink;
	}
	last->rlink = current;
	current->rlink = nullptr;
	return flag;
}

template<class T>
bool Linklist<T>::deldata(T a)
{
	bool flag = false;
	Link_Node<T>* current = head;
	while (current->rlink != nullptr)
	{
		if (current->rlink->data == a && !flag)
		{
			Link_Node<T>* p = current->rlink;
			current->rlink = current->rlink->rlink;
			p->rlink = nullptr;
			delete p;
			flag = true;
		}
		if(current->rlink != nullptr)
			current = current->rlink;
	}
	last->rlink = current;
	current->rlink = nullptr;
	return flag;
}

template<class T>
bool Linklist<T>::deldata(T a, int b)
{
	bool flag = false;
	Link_Node<T>* current = head;
	while (current->rlink != nullptr)
	{
		if (current->rlink->data == a)
		{
			Link_Node<T>* p = current->rlink;
			current->rlink = current->rlink->rlink;
			p->rlink = nullptr;
			delete p;
			flag = true;
			continue;
		}
		if (current->rlink != nullptr)
			current = current->rlink;
	}
	last->rlink = current;
	return flag;
}

template<class T>
inline Link_Node<T>* Linklist<T>::getlinkhead()
{
	return head;
}

template<class T>
inline Seq_Node<T>* Linklist<T>::getseqhead()
{
	return NULL;
}

template<class T>
inline void Linklist<T>::delcf()
{
	Link_Node<T>* current = head->rlink;
	while (current->rlink != nullptr)
	{
		Link_Node<T>* current2 = current;
		while (current2->rlink != nullptr)
		{
			if (current2->rlink->data == current->data)
			{
				Link_Node<T>* p = current2->rlink;
				current2->rlink = current2->rlink->rlink;
				p->rlink = nullptr;
				delete p;
				continue;
			}
			if (current2->rlink != nullptr)
				current2 = current2->rlink;
		}
		if (current->rlink != nullptr)
			current = current->rlink;
	}
	last->rlink = current;
}
