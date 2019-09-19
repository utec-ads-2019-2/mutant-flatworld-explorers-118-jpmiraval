#include <iostream>
#include <string>
#include "vector"

using namespace std;

int main() {
    char instruction;
    char Orientation[4] = {'N', 'E', 'S', 'W'};
    char Ori;
    int index;
    bool caida = false;
    vector<int> fall_x;
    vector<int> fall_y;
    int lim_x, lim_y;
    int pos_x, pos_y;

    cin >> lim_x >> lim_y;


    cin >> pos_x >> pos_y;

    cin >> Ori;

    for(int i = 0; i < 4; i++){
        if( Orientation[i] == Ori ){
            index = i;
            break;
        }
    }

    while(cin >> instruction){
        caida = false;
        if(instruction == 'L'){
            index--;
            if(index < 0)
                index = 3;
        }else if(instruction == 'R'){
            index++;
            if(index > 3)
                index = 0;
        }else if(instruction == 'F')

            switch(index){
            case 0:
                pos_y++;
                break;
            case 1:
                pos_x++;
                break;
            case 2:
                pos_y--;
                break;
            case 3:
                pos_x--;
                break;
        }

        for(auto c : fall_x){
            if(c == pos_x){
                caida = true;
                break;
            }
        }

        for(auto c : fall_y){
            if(c == pos_y){
                caida = true;
                break;
            }
        }

        if(caida){
            goto Print;
            break;
        }

    }

    Print:
    cout << pos_x << " " << pos_y << " " << Orientation[index];
    if(caida)
        cout << " " << "LOST" << endl;



    return 0;
}