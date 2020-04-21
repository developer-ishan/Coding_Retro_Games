#include<iostream>
#include<vector>
#include<math.h>
#include <windows.h>
#include <conio.h>
using namespace std;

class game{
    private:
        int x,y,food_x,food_y,score,width,height,LENGTH;
        vector <int> body_x,body_y;
        enum direction{STOP = 0 , LEFT , RIGHT , UP , DOWN};
        direction dir;

        void shift(int *a,int *b){
            int t;
            t=*a;
            *a=*b;
            *b=t;
        }
    public:
        bool gameOver;
        game(){
            system("cls");
            cout<<"**********WELCOME**********GAMER*********"<<endl;
            width=20;
            height=20;
            x = width/2;
            y = height/2;
            food_x = rand()%width;
            food_y = rand()%height;
            score=0;
            dir=STOP;
            gameOver = false;
            LENGTH=0;
            body_x.resize(LENGTH+2);
            body_y.resize(LENGTH+2);
        }
        void controls(){
            if(_kbhit()){
                switch(_getch()){
                    case 'a':
                    if(dir!=2)
                        dir=LEFT;
                        break;
                    case 'd':
                    if(dir!=1)
                        dir=RIGHT;
                        break;
                    case 'w':
                    if(dir!=4)
                        dir=UP;
                        break;
                    case 's':
                    if(dir!=3)
                        dir=DOWN;
                        break;
                    case 'x':
                        gameOver=true;
                }
            }
        }
        void draw(){
            system("cls");
            for(int i=-1;i<=width;i++)cout<<"#";
            cout<<"\n";
            for(int i=0;i<height;i++){
                for(int j=-1;j<=width;j++)
                {
                    bool space=true;
                    if(j==-1||j==width){
                            cout<<"#";
                            space=false;
                    }
                    else if(j==food_x&&i==food_y){
                            cout<<"@";
                            space=false;
                    }
                    else if(j==x&&y==i){
                            cout<<"0";
                            space=false;
                    }
                    for(int k=0;k<LENGTH;k++){
                        if(body_x[k]==j&&body_y[k]==i){
                            cout<<"o";
                            space=false;
                            break;
                        }
                    }
                    if(space)
                        cout<<" ";
                }
                cout<<"\n";
            }
            for(int i=-1;i<=width;i++)cout<<"#";
            cout<<"\n\n\t\tSCORE : "<<score<<"\n";
        }
        void game_working(){
            int prevX = x;
            int prevY = y;
            for(int i=0;i<LENGTH;i++){
                shift(&body_x[i],&prevX);
                shift(&body_y[i],&prevY);
            }
            switch(dir)
            {
                case LEFT:
                    x--;
                    break;
                case RIGHT:
                    x++;
                    break;
                case UP:
                    y--;
                    break;
                case DOWN:
                    y++;
                    break;
            }
            if(x>width||x<0||y>height||y<0)
                gameOver=true;
            for(int i=0;i<LENGTH;i++){
                if(x==body_x[i]&&y==body_y[i])
                    gameOver=true;
            }
            if(x==food_x&&y==food_y){
                score+=10;
                LENGTH++;
                food_x = rand()%width;
                food_y = rand()%height;
                body_x.resize(LENGTH);
                body_y.resize(LENGTH);
            }
        }
};

int main(){
    game snake;
    cout<<snake.gameOver;
    while(!snake.gameOver){
        Sleep(100);
        snake.controls();
        snake.game_working();
        snake.draw();
    }
    return 0;
}