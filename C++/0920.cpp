#include <iostream>

using std::cout;
using std::endl;

bool mySum(int x[], int num, int &val) {    //val�� ���� �ܺο��� �����ϱ� ���� ������ ���
    val = 0;
    if (num >= 0) {
        for (; num > 0; num--) {    //���->�迭�� �� ���� val�� ���� �� true ����
            val += x[num-1];
        }
        return true;
    }
    else {  //������� false ����
        return false;
    }
}

int main(){
    int x[] = { 3, 7, 10, 12 };
    int val = 0;

    if (mySum(x, 4, val)) {
        cout << val << endl;
    }
    else {
        cout << "�Ű����� ����" << endl;
    }
    
    if (mySum(x, -2, val)) {
        cout << val << endl;
    }
    else {
        cout << "�Ű����� ����" << endl;
    }

    return 0;
}

/*
    mySum()�� �ι�° �Ű������� ���� ������ ���� ����󿡴� �迭�� ���̸� �޴� �� ���� �ٸ� ���̽� ��� ���� val�� �迭�� ���� �������� ���ϵ��� �Ͽ���
*/