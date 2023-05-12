#include <iostream>
#include<map>
#include<string>

void printShop(std::map<std::string, int> &shop)
{
	for (auto a : shop)
	{
		std::cout << a.first << std::endl;
	}
}
bool add(std::map<std::string, int>& shop,std::string art, int count)
{	
	std::map<std::string, int>::iterator it;
	if (shop.find(art) != shop.end())
	{
		it = shop.find(art);
		count <= it->second ? true : false;
	}
	else
		return false;
}
bool remove(std::map<std::string, int>& basket, std::string art, int count)
{
	return true;
}
int main()
{
	std::map<std::string, int> shop;
	std::map<std::string, int> basket;
	std::string article;
	int quantity;
	bool ex = true;
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
			printShop(shop);
		}
	}
	ex = true;
	int choise;
	while (ex)
	{
		std::cout << "Select\n1-add\n2-remove\n3-print shop\n4-exit\n";
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
				}
			}
			catch()
			{

			}
			break;
		}
		case(2):
		{
			break;
		}
		case(3):
		{
			printShop(shop);
			break;
		}
		case(4):
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
