#pragma once
#include <queue>
#include <functional>
#include <map>

struct Order {
	double price;
	int size;
	char time[32];
	int ref;
	bool isBid;
	Order(double p, int s, int r, bool bid, const char * c) :price(p), size(s),ref(r),isBid(bid)
	{
		std::strcpy(time, c);
	}
};

struct BidCmp
{
	bool operator( )  ( const Order &a, const Order &b)
	{
		int r = std::strcmp(a.time, b.time);
		if (a.price < b.price)
			return true;
		else if (a.price == b.price)
		{
			if (r > 0)
				return true;
			else if (r == 0)
			{
				if (a.ref > b.ref) return true;
				else return false;
			}
			else return false;
		}
		else return false;
	}
};

struct AskCmp
{
	bool operator( )  (const Order &a, const Order &b)
	{
		int r = std::strcmp(a.time, b.time);
		if (a.price > b.price)
			return true;
		else if (a.price == b.price)
		{
			if (r > 0)
				return true;
			else if (r == 0)
			{
				if (a.ref > b.ref) return true;
				else return false;
			}
			else return false;
		}
		else return false;
	}
};

struct ExeCmp
{
	bool operator( )  (const Order &a, const Order &b)
	{
		if (a.ref > b.ref) return true;
		else return false;
	}
};

class OrderBook {

private:
	typedef std::map<int, Order> REF;
	enum OrderType {
		AuctionLong = 0,
		AuctionShort,
		LimitLong,
		LimitShort,
		AuctionCancel,
		MarketLong,
		MarketShort,
		Cancel
	} orderType;
	double openPrice;
	std::priority_queue<Order, std::deque<Order>, BidCmp> BidBook;
	std::priority_queue<Order, std::deque<Order>, AskCmp> AskBook;
	std::priority_queue<Order, std::deque<Order>, AskCmp> ExeBook;
	REF refAndOrder;
	void FindOrderByRef(int ref, double& price, bool& isBid);
public:
	OrderBook(double price);
	~OrderBook();
	void ExecuteOrder(OrderType orderType, int size, double price, const char* time, bool isBid, int ref1, int ref2);
};