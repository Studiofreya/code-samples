#include <iostream>		// Provides cout
#include <vector>		// Provides our basic container
#include <algorithm>	// Provides std::sort


using namespace std;

// Structures I'll sort with 1 template function
//
//
struct A
{
	A(size_t i, size_t t) : id(i), time(t), other_data(false){}
	size_t	id;
	size_t	time;
	bool	other_data;
};

struct B
{
	B(size_t i, size_t t) : id(i), time(t), other_data("string data"){}
	size_t	id;
	size_t	time;
	string	other_data;
};

struct C
{
	C(size_t i, size_t t) : id(i), time(t), other_data("character array data"){}
	size_t	id;
	size_t	time;
	char*	other_data;
};

// Our predicate
//
template<typename CLASS>
bool timeSortPredicate( const CLASS &a, const CLASS &b )
{
	return a.time < b.time;
}

template<typename CLASS>
bool idSortPredicate( const CLASS &a, const CLASS &b )
{
	return a.id < b.id;
}

// Our collection printer
//
template<typename CLASS>
void print( const CLASS &c )
{
	typedef typename CLASS::const_iterator cit;

	for ( cit it = c.begin(); it != c.end(); ++it )
	{
		cout << it->id << " " << it->time << endl;
	}
}

int main()
{
	// Construct the objects ... tedious I know
	A a1(1,15),	a2(2,20), 	a3(3,14);
	B b1(3,4),	b2(2,10),	b3(1,12);
	C c1(11,0),	c2(12,0),	c3(13,0);

	// Construct collections
	vector<A> alist;
	alist.push_back(a1);
	alist.push_back(a2);
	alist.push_back(a3);

	vector<B> blist;
	blist.push_back(b1);
	blist.push_back(b2);
	blist.push_back(b3);

	vector<C> clist;
	clist.push_back(c1);
	clist.push_back(c2);
	clist.push_back(c3);


	// Print stuff
	cout << "Collection A" << endl;
	print(alist);

	cout << "Collection B" << endl;
	print(blist);

	cout << "Collection C" << endl;
	print(clist);

	cout << "Sorting collections by time" << endl;

	sort(alist.begin(), alist.end(), timeSortPredicate<A> );
	sort(blist.begin(), blist.end(), timeSortPredicate<B> );
	sort(clist.begin(), clist.end(), timeSortPredicate<C> );

	// Print stuff
	cout << "Collection A" << endl;
	print(alist);

	cout << "Collection B" << endl;
	print(blist);

	cout << "Collection C" << endl;
	print(clist);


	cout << "Sorting collections by id" << endl;

	sort(alist.begin(), alist.end(), idSortPredicate<A> );
	sort(blist.begin(), blist.end(), idSortPredicate<B> );
	sort(clist.begin(), clist.end(), idSortPredicate<C> );

	// Print stuff
	cout << "Collection A" << endl;
	print(alist);

	cout << "Collection B" << endl;
	print(blist);

	cout << "Collection C" << endl;
	print(clist);

	return 0;
}


