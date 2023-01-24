//
//  main.cpp
//  4-1 Up Down Left Right
//
//  Created by JinnyLim on 2023/01/24.
//

#include <iostream>
using  namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, x = 1, y = 1;
    cin>>n;
    
    char move;
    
    do {
        cin>>move;
        switch(move) {
            case 'U':
                if(x > 1) x--;
                break;
            case 'D':
                if(x < n) x++;
                break;
            case 'L':
                if(y > 1) y--;
                break;
            case 'R':
                if(y < n) y++;
                break;
        }
    } while (getc(stdin) == ' '); // no more char to read
    
    std::cout << x << " " << y << endl;
    return 0;
}
