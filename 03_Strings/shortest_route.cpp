#include <bits/stdc++.h>
using namespace std;

int main(){
    char inp[100];
    cin.getline(inp, 100);
    int x = 0, y = 0;
    for (int i = 0; inp[i] != '\0'; i++)
    {
        switch(inp[i]){
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;

            }
    }
    
    // cout << y << ", " << x << endl;
    // cout << y << ", " << x << endl;
    if (x>=0 && y>=0){
        while(y--){
            cout << "N";
        }
        while(x--){
            cout << "E";
        }
        x = 0;
        y = 0;
      
    }
    // cout << y << ", " << x << endl;
    if (x<0 && y>0){
        while(y--){
            cout << "N";
        }
        while(x++){
            cout << "W";
        }
        x = 0;
        y = 0;
    }
    // cout << y << ", " << x << endl;

    if (x<0 && y<0){
        while(y++){
            cout << "S";
        }
        while(x++){
            cout << "W";
        }
        x = 0;
        y = 0;
    }
    // cout << y << ", " << x << endl;

    if (x>0 && y<0){
        while(y++){
            cout << "S";
        }
        while(x--){
            cout << "E";
        }
        x = 0;
        y = 0;
    }
    cout << endl;
}