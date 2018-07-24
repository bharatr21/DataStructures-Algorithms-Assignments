#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
using namespace std;

class LRU
{
	ll csize, pgf;
	list<ll> dq;
	unordered_map<ll, list<ll>::iterator> ma;
public:
	LRU()
	{
		csize = 3; //Default capacity of 3
		pgf = 0;
	}
	LRU(ll cap)
	{
		csize = cap;
		pgf = 0;
	}
	void refer(ll x)
	{
		if(ma.find(x) == ma.end())
		{
			cout << "Page Fault for: " << x << nl;
			pgf++;
			if(dq.size() == csize)
			{
				// Remove/Kick out the least recently used(LRU) entry
				ma.erase(dq.back());
				dq.pop_back();
			}
		}
		else
			dq.erase(ma[x]);
		dq.push_front(x);
		ma[x] = dq.begin();
	}
	void display()
	{
		cout << "Displaying the contents of the cache" << nl;
		for(auto it:dq)
		{
			cout << it << ' ';
		}
		cout << nl;	
	}
	ll pagefaults()
	{
		return pgf;
	}
};

// Basic Testing
int main()
{
	ll cap, t;
	vector<ll> v;
	cout << "Enter array of Pages: ";
	while(cin.peek() != nl)
	{
		cin >> t;
		v.pb(t);
	}
	cout << "Enter Page Frame Capacity: ";
	try 
	{
		cin >> cap;
		if(cap <= 0)
			throw cap;
	}
	catch(ll x)
	{
		cout << "This is an invalid page cache" << nl;
		cout << "Cannot have " << x << " pages in frame" << nl;
		return 0;
	}
	LRU lru = LRU(cap);
	for(auto u:v)  {lru.refer(u);}
	lru.display();
	cout << "Number of pagefaults: " << lru.pagefaults() << nl;
	return 0;
}
