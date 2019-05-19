#include "OrderBook.h"

OrderBook::~OrderBook()
{
	return;
}

OrderBook::OrderBook(double price) : openPrice(price)
{
	return;
}

void OrderBook::FindOrderByRef(int ref, double& price, bool& isBid)
{
	REF::iterator it;
	it = refAndOrder.find(ref);
	if (it != refAndOrder.end())
	{
		price = it->second.price;
		isBid = it->second.isBid;
	}
	else return;
}

void OrderBook::ExecuteOrder(OrderType orderType, int size, double price, const char* time, bool isBid, int ref1, int ref2)
{
	Order order(price, size, ref1, isBid, time);
	if (orderType < 4)
	{
		refAndOrder.insert(std::pair<int, Order>(ref1, order));
	}

	switch (orderType)
	{
	case AuctionLong :
		if (price >= openPrice)
			return;
		else
			BidBook.push(order);
		break;
	case AuctionShort:
		if (price <= openPrice)
			return;
		else
			AskBook.push(order);
		break;
	case AuctionCancel:
		bool bid;
		double price;
		FindOrderByRef(ref1, price, bid);
		if (bid && price < openPrice) 

			LimitLong,
			LimitShort,
			MarketLong,
			MarketShort,
			Cancel
		break;
	}
	return;
}