#include <iostream>
#include<map>
#include<string>
#include<exception>

void printShop(std::map<std::string, int> &shop)
{
	for (auto a : shop)
	{
		std::cout << a.first << std::endl;
	}
}
void magazin(std::map<std::string, int>& shop)
{	
	bool ex = true;
	int quantity;
	std::string article;
	while (ex)
	{
		std::cout << "Enter the article of the product or the end to exit  : ";
		std::cin >> article;
		if (article != "end")
		{
			std::cout << "Enter the quantity of the product : ";
			std::cin >> quantity;
			if (shop.find(article) != shop.end())
			{
				shop[article] += quantity;
			}
			else
			{
				shop[article] = quantity;
			}
		}
		else
		{
			ex = false;
		}
	}
}
bool add(std::map<std::string, int>& shop,std::string art, int count)
{	
	if (count < 0)
	{
		throw std::invalid_argument("The quantity is negative");
	}
	std::map<std::string, int>::iterator it;
	if (shop.find(art) != shop.end())
	{
		it = shop.find(art);
		if (count > it->second)
		{
			throw std::invalid_argument("The specified quantity is more than in stock");
		}
		if (it->second == 0)
		{
			throw std::invalid_argument("The product is out of stock");
		}
		return true;
	}
	else
	{
		return false;
	}
	
}
bool remove(std::map<std::string, int>& shop,std::map<std::string, int>& basket, std::string art, int count)
{
	if (count < 0)
	{
		throw std::invalid_argument("The quantity is negative");
	}
	std::map<std::string, int>::iterator itBasket;
	std::map<std::string, int>::iterator itShop;
	if (basket.find(art) != basket.end())
	{
		itBasket = basket.find(art);
		itShop = shop.find(art);
		if (itBasket->second == count)
		{
			basket.erase(art);
			itShop->second += count;
			return true;
		}
		else 
		{
			itBasket->second -= count;
			itShop->second += count;
			return true;
		}
	}
	else
	{
		return false;
	}
	
}
int main()
{
	std::map<std::string, int> shop;
	std::map<std::string, int> basket;
	std::string article;
	int choise;
	int quantity;
	bool ex = true;
	magazin(shop);
	
	while (ex)
	{
		std::cout << "Select\n1-add\n2-remove\n3-print shop\n4-print basket\n5-exit\n";
		std::cin >> choise;
		switch (choise)
		{
		case(1):
		{	
			std::cout << "Input article :";
			std::cin >> article;
			std::cout << "Input quantity :";
			std::cin >> quantity;
		
			try 
			{
				if (add(shop, article, quantity))
				{
					basket[article] = quantity;
					shop[article] -= quantity;
				}
				else
				{
					std::cout << "There is no such article" << std::endl;
				}
			}
			catch(const std::invalid_argument& ex)
			{
				std::cerr << ex.what()<< std::endl;
			}
			catch (...)
			{
				std::cerr << "unknown error"<<std::endl;
			}
			break;
		}
		case(2):
		{
			std::cout << "Input article :";
			std::cin >> article;
			std::cout << "Input quantity :";
			std::cin >> quantity;

			try
			{
				if (remove(shop,basket, article, quantity))
				{
					std::cout << "The product has been removed" << std::endl;
				}
				else
				{
					std::cout << "There is no such article" << std::endl;
				}
			}
			catch (const std::invalid_argument& ex)
			{
				std::cerr << ex.what() << std::endl;
			}
			catch (...)
			{
				std::cerr << "unknown error" << std::endl;
			}
			break;
		}
		case(3):
		{
			printShop(shop);
			break;
		}
		case(4):
		{
			for (auto a : basket)
			{
				std::cout << a.first<<" - "<< a.second << std::endl;
			}
			break;
		}
		case(5):
		{
			ex = false;
			break;
		}
		default:
		{
			std::cout << "Incorect input\n";
			break;
		}
		}
	}
	return 0;
}
