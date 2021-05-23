#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;

bool isPrime(int);

int main(){
    int num;
    cin >> num;
    if(isPrime(num)){
        cout << "Prime" << endl;
    } else {
        cout << "Not prime" << endl;
    }
    return 0;
}

bool isPrime(int num){
    num = abs(num);
    if(num == 1) {return NULL;}
    if(num == 2) {return true;}
    if(num == 5) {return true;}

    string strNum = to_string(num);
    if(!(strNum.back() == '1' || strNum.back() == '3' || strNum.back() == '7' || strNum.back() == '9')) {return false;}
    
    vector<int> listPrimes;
    bool tempIsPrime = true;
    listPrimes.push_back(2);
    listPrimes.push_back(3);

    for(int i = 3; i <= num; i += 2){
        for(int j = 1; j < listPrimes.size(); j++){
            if(i % listPrimes[j] == 0){
                tempIsPrime = false;
                break;
            }
            if(listPrimes[j] > num/2+1){
                break;
            }
        }
        if(tempIsPrime){
            listPrimes.push_back(i);
        }
        tempIsPrime = true;
    }
    if(listPrimes.back() == num){
        return true;
    } else{
        return false;
    }
}