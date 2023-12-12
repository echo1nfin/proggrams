#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите нечётное значение n больше 2" << endl;
    cin >> n;
    while (n % 2 == 0 and n > 2) {
        cout << "Введите нечётное значение n больше 2" << endl;
    }
    int stars = 1;
    int space = n/2;
    for (int i = 0; i < n/2 + 1; i++){
        for (int j = 0; j < space; j++){
            cout << ' ';
        }
        for (int j = 0; j < stars; j++){
            cout << '*';
        }
        cout << endl;
        space -= 1;
        stars += 2;
    }
}
