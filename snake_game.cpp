#include<iostream>
#include<vector>
#include<math.h>
#include <windows.h>
#include <conio.h>
using namespace std;

class game{
    protected:
        int x,y,food_x,food_y,score,width,height,LENGTH,snake_speed;
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
        int speed(){
            return snake_speed;
        }
        game()
        {
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
            int choice = 0;
            mainMenu:
            system("cls");
            cout<<"\t\t\t\tWELCOME GAMER"<<endl;
                cout<<"\n\t1. Start";
                cout<<"\n\t2. Settings";
                cout<<"\n\t3. View Scores";
                cout<<"\n\t4. EXIT";
                cout<<"\nYour Choice : ";
            cin>>choice;
            while(choice!=1)
            {
                switch(choice)
                {
                    case(1):
                        break;
                    case(2):
                    while(1)
                    {
                        cout<<"\n\t\tSETTINGS";
                        cout<<"\n\t1. Change Snake Speed";
                        cout<<"\n\t2. Change The Arena";
                        cout<<"\n\t3. Back";
                        int set;
                        cout<<"\nYour Choice : ";
                        cin>>set;
                        switch (set)
                        {
                        case 1:
                            cout<<"\nEnter The Snake Speed (From 1 to 5)";
                            cin>>snake_speed;
                            if(snake_speed>5||snake_speed<=0)
                                {
                                    cout<<"\nNo Cheating Dude!!!!!!";
                                    snake_speed=5;
                                }
                            break;
                        case 2:
                            cout<<"\nEnter the height of Arena (From 10 to 50 only): ";
                            cin>>height;
                            cout<<"\nEnter the width of Arena (From 10 to 50 only): ";
                            cin>>width;
                            if(height<10||height>50||width<10||height>50)
                            {
                                cout<<"Follow the instructions please.";
                                height=20;
                                width=20;
                            }
                        case 3:
                            goto mainMenu;
                        case 4:
                            break;
                        default:
                            goto mainMenu;
                        }
                    }    
                    case 3 :
                        cout<<"Not availabe?\nWe are working on it.";
                    default :
                        goto mainMenu;

                }
            }
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
    while(!snake.gameOver)
    {
        Sleep(50*(5-snake.speed()));
        snake.controls();
        snake.game_working();
        snake.draw();
    }
    return 0;
}