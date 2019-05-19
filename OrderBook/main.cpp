
#include <functional>
#include "OrderBook.h"
#include <fstream>

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
	std::string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}

int main() {
	std::priority_queue<Order, std::deque<Order>, BidCmp> book;
	Order x(30.0, 10, 1, "10:00");
	Order x2(31.0, 10, 2, "10:00");
	Order x4(30.0, 10, 4, "10:00");
	Order x3(30.0, 10, 3, "10:01");

	book.push(x);
	book.push(x2);
	book.push(x4);
	book.push(x3);

	const char * file = "C:\\Users\\Administrator\\PycharmProjects\\HFT\\Data\\300136.20190417-20190430\\300136.20190417.txt";
	std::ifstream f;
	f.open(file);
	char data[128];
	std::string delims = " ";
	while (f.getline(data, 128))
	{
		std::vector <std::string> splitStrs;
		SplitString(data, splitStrs, delims);
		int x = splitStrs.size();   //done
		
	}

	return 0;
}