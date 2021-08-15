#include <iostream>
#include <time.h>
using namespace std;

int arr[9] = {0}, vic = 0, e = 0;

void grafica() {
    
    int i;

    cout << "       |       |       \n";
        for (i = 0; i < 3; i++){

            if (arr[i] == 0){
            cout << "       |";
            } 
            else if (arr[i] == 1 ){
                cout << "   o   |";
            }
            else {
                cout << "   x   |";
            }
        }
        cout << "\n_______|_______|_______\n";

         cout << "       |       |       \n";
        for (i = 3; i < 6; i++){

            if (arr[i] == 0){
            cout << "       |";
            } 
            else if (arr[i] == 1 ){
                cout << "   o   |";
            }
            else {
                cout << "   x   |";
            }
        }
        cout << "\n_______|_______|_______\n";

         cout << "       |       |       \n";
        for (i = 6; i < 9; i++){

            if (arr[i] == 0){
            cout << "       |";
            } 
            else if (arr[i] == 1 ){
                cout << "   o   |";
            }
            else {
                cout << "   x   |";
            }
        }
        cout << "\n       |       |       \n";
}

void check () {
     if (arr[0] == 1 && arr[1] == 1 && arr[2] == 1 ||
		arr[3] == 1 && arr[4] == 1 && arr[5] == 1 ||
		arr[6] == 1 && arr[7] == 1 && arr[8] == 1 ||
		arr[0] == 1 && arr[3] == 1 && arr[6] == 1 ||
		arr[1] == 1 && arr[4] == 1 && arr[7] == 1 ||
		arr[2] == 1 && arr[5] == 1 && arr[8] == 1 ||
		arr[0] == 1 && arr[4] == 1 && arr[8] == 1 ||
		arr[2] == 1 && arr[4] == 1 && arr[6] == 1) {
    
        vic = 1;
        e =1;
    } 
        else if (arr[0] == 2 && arr[1] == 2 && arr[2] == 2 ||
		arr[3] == 2 && arr[4] == 2 && arr[5] == 2 ||
		arr[6] == 2 && arr[7] == 2 && arr[8] == 2 ||
		arr[0] == 2 && arr[3] == 2 && arr[6] == 2 ||
		arr[1] == 2 && arr[4] == 2 && arr[7] == 2 ||
		arr[2] == 2 && arr[5] == 2 && arr[8] == 2 ||
		arr[0] == 2 && arr[4] == 2 && arr[8] == 2 ||
		arr[2] == 2 && arr[4] == 2 && arr[6] == 2) {
            
            vic = 2;
            e =1;

        }
        else if (arr[0] != 0 &&
			 arr[1] != 0 &&
			 arr[2] != 0 &&
			 arr[3] != 0 &&
			 arr[4] != 0 &&
			 arr[5] != 0 &&
			 arr[6] != 0 &&
			 arr[7] != 0 &&
			 arr[8] != 0){

                 vic = 3;
                 e =1;

             }

}

int main () {
    srand( time(NULL));

    cout << "       |       |       \n";
    cout << "   1   |   2   |   3   \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |       \n";
    cout << "   4   |   5   |   6   \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |       \n";
    cout << "   7   |   8   |   9   \n";
    cout << "       |       |       \n";

    int num, p, c;

    cout << "Choose a game mode: \n 1.One Player    2.Two Players";
    cin >> c;

    if (c == 1){
        while (vic<1){
         while (e!=1){
             cout << "where do you want to position yourself?: ";
            cin >> num;
            
            if (num>9){
            cout << "overflow \n";
            }
            
            else if (arr[num - 1] == 0) {
            arr[num - 1] = 1;
            e = 1;
            }   
            
            else {
            cout << "Slot already taken, choose another one.\n";
            }
        
         }
        
        e = 0;
        
        grafica();

        while (e!=1){

            p = rand()%9;

            if (arr[p] == 0) {
            arr[p] = 2;
            e = 1;
            }
        }
        grafica();
        e = 0;

        check();

        }
    
    }
    else {
         while (vic<1){
         while (e!=1){
             cout << "PLayer 1, Where do you want to position yourself?: ";
            cin >> num;
            
            if (num>9){
            cout << "overflow \n";
            }
            
            else if (arr[num - 1] == 0) {
            arr[num - 1] = 1;
            e = 1;
            }   
            
            else {
            cout << "Slot already taken, choose another one.\n";
            }
        
         }
        
        e = 0;
        
        grafica();
        check();

        while (e!=1){
             cout << "PLayer 2, Where do you want to position yourself?: ";
            cin >> num;
            
            if (num>9){
            cout << "overflow \n";
            }
            
            else if (arr[num - 1] == 0) {
            arr[num - 1] = 2;
            e = 1;
            }   
            
            else {
            cout << "Slot already taken, choose another one.\n";
            }
        }
        grafica();
        e = 0;

        check();

        }

    }
    
    if (vic == 1){
        if (c == 1){
            cout << "You Win" << endl;
        } else {
            cout << "Player 1 Win" << endl;
        }
    }
    else if (vic == 2){
        if (c == 1){
            cout << "Pc Win" << endl;
        } else {
            cout << "Player 2 Win" << endl;
        }
    }
    else{
        cout << "Draw" << endl;
    }
    
}