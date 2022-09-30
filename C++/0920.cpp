#include <iostream>

using std::cout;
using std::endl;

bool mySum(int x[], int num, int &val) {    //val의 값을 외부에서 수정하기 위해 참조자 사용
    val = 0;
    if (num >= 0) {
        for (; num > 0; num--) {    //양수->배열의 합 구해 val에 저장 후 true 리턴
            val += x[num-1];
        }
        return true;
    }
    else {  //음수라면 false 리턴
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
        cout << "매개변수 오류" << endl;
    }
    
    if (mySum(x, -2, val)) {
        cout << val << endl;
    }
    else {
        cout << "매개변수 오류" << endl;
    }

    return 0;
}

/*
    mySum()의 두번째 매개변수에 대한 설명이 없고 결과상에는 배열의 길이를 받는 것 같아 다른 케이스 고려 없이 val에 배열의 값을 역순으로 더하도록 하였음
*/