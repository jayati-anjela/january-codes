#include <iostream>
using namespace std;

int R;
int C;

void printMatrix(char input[][50]){

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<input[i][j];
        }
        cout<<endl;
    }
}

// W,N,E,S -> West North East South
int dx[] = {-1,0,1,0}; // these define positions
int dy[] = {0,-1,0,1};

// ch is the character to be replaced
// color is the character to be added
void floodFill(char mat[][50], int i, int j, char ch, char color){
    // Base case - Matrix bounds
    if(i<0 || j<0 || i>=R || j>=C){
        return;
    }
    // Boundary of figure
    if(mat[i][j] != ch){
        return; 
    }

    // Recursive call

    mat[i][j] = color;
    for(int k = 0; k<4; k++){
        floodFill(mat, i+dx[k], j+dy[k], ch, color);
    }

}

int main() {

    cin>>R>>C;
    char input[15][50];

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>input[i][j];
        }
    }

    printMatrix(input);
    floodFill(input,8,13,'.','r');
    printMatrix(input);

}
