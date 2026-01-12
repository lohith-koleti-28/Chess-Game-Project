#include<simplecpp>
struct Pos{
    int xpos,ypos;
    Pos(int a=0, int b=0): xpos(a), ypos(b){}
};
int check(Pos* p , int i,int j , Text* t){
    //FOr checking whether the character is captured or not
    //opposite player -> p and t
    //Same player i and j
    for(int k=0;k<16;k++){
        if(p[k].xpos == i && p[k].ypos == j){
            t[k].hide();
            return k;
        }
    }
    return -1;
}

int main(){
    initCanvas("Chess",1000,700);
    //Making board with all characters
    const int a=80,b=80,c = 230,d = 55;//Length and breadth
    //Having first block centre at (c,d);
    //Centre of a sq is c + i*a same for y
    Text pleft[16] , pRight[16];
    //Indices from 0 to 7
    //Rest are as the markings

    //Markings
    for(int i=0;i<8;i++){
        Text mark(c + i*a , 7 , i);
        mark.imprint();
    }
    for(int i=0;i<8;i++){
        Text mark(185 , d + i*b,i);
        mark.imprint();
    }

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            Rectangle r(c+i*a,d + j*b, a,b);
            if( (i+j)%2 ==0){
                r.setColor(COLOR("black"));
                r.setFill();
            }
            r.imprint();
        }
    }

    cout<<"Chart of Game:\n";
    cout<<"For character in 0 to 7 it is Soldier\n"
        <<"8 or 15 for Elephant\n"
        <<"9 or 14 for Horse\n"
        <<"10 or 13 for Camel\n"
        <<"11 for Queen\n"
        <<"12 for King\n";

    string chat[16];
    chat[0] = "P1";
    chat[1] = "P2";
    chat[2] = "P3";
    chat[3] = "P4";
    chat[4] = "P5";
    chat[5] = "P6";
    chat[6] = "P7";
    chat[7] = "P8";
    chat[8] = "ELEPHANT1";
    chat[15] = "ELEPHANT2";
    chat[9] = "HORSE1";
    chat[14] = "HORSE2";
    chat[10] = "CAMEL1";
    chat[13] = "CAMEL2";
    chat[11] = "QUEEN";
    chat[12] = "KING";

    Pos pL[16] , pR[16];
    //Putting characters
    for(int i=0;i<8;i++){
        pL[i].xpos = 1;
        pL[i].ypos = i;
        pR[i].xpos = 6;
        pR[i].ypos = i;
        pleft[i].reset(c + 1*a , d + i*b,chat[i]);
        pleft[i].setColor(COLOR("green"));

        pRight[i].reset(c + 6*a , d + i*b,chat[i]);
        pRight[i].setColor(COLOR("red"));
    }
    for(int i=8;i<16;i++){
        pL[i].xpos = 0;
        pL[i].ypos = i - 8;
        pR[i].xpos = 7;
        pR[i].ypos = i - 8;
        pleft[i].reset(c  , d + (i - 8)*b,chat[i]);
        pleft[i].setColor(COLOR("green"));

        pRight[i].reset(c + 7*a , d + (i - 8)*b,chat[i]);
        pRight[i].setColor(COLOR("red"));
    }

    while(true){
        int character;
        int x,y;
        cout<<"\nPlayer Left\n";
        cout<<"Enter character number: ";
        cin >> character;
        cout<<"Enter where to move: ";
        cin >> x >> y;
        pleft[character].reset(c + x*a,d+y*b , chat[character]);
        pL[character].xpos = x;
        pL[character].ypos = y;
        cout<<check(pR , x,y,pRight)<<endl;
        if(check(pR , x,y,pRight) == 12){
            cout<<"\nPlayer Left Wins!!\n";
            break;
        }

        cout<<"\nPlayer Right\n";
        cout<<"Enter character number: ";
        cin >> character;
        cout<<"Enter where to move: ";
        cin >> x >> y;
        pRight[character].reset(c + x*a,d+y*b , chat[character]);
        pR[character].xpos = x;
        pR[character].ypos = y;
        cout<<check(pL , x,y,pleft)<<endl;
        if(check(pL , x,y,pleft) == 12){
            cout<<"\nPlayer Right Wins!!\n";
            break;
        }
    }
    getClick();
}