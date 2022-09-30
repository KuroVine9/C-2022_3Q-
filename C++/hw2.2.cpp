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
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << money << endl;
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
		cout << "���� �ܾ�: " << money << endl;
		cout << "��� ����: " << numOfApples << endl;
	}
};

int main() {
	FruitSeller* seller = new FruitSeller(100, 20, 0);
	FruitBuyer* buyer = new FruitBuyer(5000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller->ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer->ShowBuyResult();

	buyer->BuyApples(seller, 2000);
	cout << "==========" << endl;

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller->ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer->ShowBuyResult();

	delete(seller);
	delete(buyer);

	return 0;
}

