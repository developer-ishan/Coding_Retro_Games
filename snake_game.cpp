#include<bits/stdc++.h>
using namespace std;

class game{
    private:
        int x,y,food_x,food_y,score,width,height;
        enum direction{STOP = 0 , LEFT , RIGHT , UP , DOWN};
        direction dir;
    public:
        bool gameOver;
        game(){
            system("cls");
            cout<<"**********WELCOME**********GAMER*********"<<endl;
            width=40;
            height=20;
            x = width/2;
            y = height/2;
            food_x = rand()/width + 1;
            food_y = rand()/height + 1;
            score=0;
            dir=STOP;
            gameOver = false;
        }
        input(){
            
        }
        draw(){
            system("cls");
            for(int i=0;i<width;i++)cout<<"#";
            cout<<"\n";
            for(int i=0;i<height;i++){
                for(int j=0;j<width;j++)
                {
                    if(j==0||j==width-1)
                        cout<<"#";
                    else
                        cout<<" ";
                }
                cout<<"\n";
            }
            for(int i=0;i<width;i++)cout<<"#";
        }
        game_working(){

        }
};

int main(){
    game snake;
    cout<<snake.gameOver;
    while(!snake.gameOver){
        snake.draw();
    }
    return 0;
}