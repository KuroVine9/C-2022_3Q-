#include <iostream>

using namespace std;

class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int money;
public:
	FruitSeller(int APPLE_PRICE, int numOfApples, int Money) {
		this->APPLE_PRICE = APPLE_PRICE;
		this->numOfApples = numOfApples;
		this->money = Money;
	}

	int SaleApples(int money) {
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		this->money += money;
		return num;
	}

	void ShowSalesResult() {
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << money << endl;
	}
};

class FruitBuyer {
private:
	int money;
	int numOfApples;
public:
	FruitBuyer(int money) {
		this->money = money;
		numOfApples = 0;
	}

	void BuyApples(FruitSeller* seller, int money) {
		numOfApples += seller->SaleApples(money);
		this->money -= money;
	}

	void ShowBuyResult() {
		cout << "현재 잔액: " << money << endl;
		cout << "사과 개수: " << numOfApples << endl;
	}
};

int main() {
	FruitSeller* seller = new FruitSeller(100, 20, 0);
	FruitBuyer* buyer = new FruitBuyer(5000);

	cout << "과일 판매자의 현황" << endl;
	seller->ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer->ShowBuyResult();

	buyer->BuyApples(seller, 2000);
	cout << "==========" << endl;

	cout << "과일 판매자의 현황" << endl;
	seller->ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer->ShowBuyResult();

	delete(seller);
	delete(buyer);

	return 0;
}

