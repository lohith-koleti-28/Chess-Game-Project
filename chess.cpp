#include<simplecpp>
const int a = 80, c = 230,d=55; 
//a is dimension of square 
//c and d are centre of first box
void board(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            Rectangle r(c+i*a,d + j*a, a,a);
            if( (i+j)%2 ==0){
                r.setColor(COLOR("black"));
                r.setFill();
            }
            r.imprint();
        }
    }
}

class Character{
    //x and y are actual pixel co ords
    public:
    int x , y;
    string msg;
    Text t;
    void set(int i , int j){
        x = c + i*a;
        y = d + j*a;
        t.reset(x,y,msg);
    }
    int geti(){
        return round((x - c + 40)/a);
    }
    int getj(){
        return  round((y - d + 40)/a);
    }
    // void str(char a[]){
    //     for(int i=0;i<9;i++){
    //         if(a[i] == '\0') break;
    //         msg[i] = a[i];
    //     }
    // }
};
int capL=0 , capR = 0;
int capture(Character* player, int xp , int yp, bool right){
    //xp is int of x and same for yp
    int i;
    for(i=0;i<16;i++){
        if(player[i].geti() ==xp && player[i].getj() == yp){
            if(right){
                player[i].set( 8, capR++);
            }
            else{
                player[i].set(-1,capL++);
            }
            break;
        }
    }
    return i;
}

//0 to 7 Pawn
//8 and 15 Ele
//9 and 14 Horse
//10 and 13 Camel
//11 Q and 12 King

int main(){
    initCanvas("Chess",1000,700);
    board();

    Character pLeft[16] , pRight[16];
    // pLeft[0].msg = "P1";
    pLeft[1].msg = "P2";
    pLeft[0].msg = "P1";
    pLeft[2].msg = "P3";
    pLeft[3].msg = "P4";
    pLeft[4].msg = "P5";
    pLeft[5].msg = "P6";
    pLeft[6].msg = "P7";
    pLeft[7].msg = "P8";
    pLeft[8].msg = "ELEPHANT1";
    pLeft[15].msg = "ELEPHANT2";
    pLeft[9].msg = "HORSE1";
    pLeft[14].msg = "HORSE2";
    pLeft[10].msg = "CAMEL1";
    pLeft[13].msg = "CAMEL2";
    pLeft[11].msg = "QUEEN";
    pLeft[12].msg = "KING";

    pRight[1].msg = "P2";
    pRight[0].msg = "P1";
    pRight[2].msg = "P3";
    pRight[3].msg = "P4";
    pRight[4].msg = "P5";
    pRight[5].msg = "P6";
    pRight[6].msg = "P7";
    pRight[7].msg = "P8";
    pRight[8].msg = "ELEPHANT1";
    pRight[15].msg = "ELEPHANT2";
    pRight[9].msg = "HORSE1";
    pRight[14].msg = "HORSE2";
    pRight[10].msg = "CAMEL1";
    pRight[13].msg = "CAMEL2";
    pRight[11].msg = "QUEEN";
    pRight[12].msg = "KING";

    for(int i=0;i<8;i++){
        pLeft[i].set(1,i);
        pRight[i].set(6,i);
        pLeft[8+i].set(0,i);
        pRight[8+i].set(7,i);
    }
    for(int i=0;i<16;i++){
        pLeft[i].t.setColor(COLOR("green"));
        pRight[i].t.setColor(COLOR("red"));
    }

    int xPix , yPix;
    bool left = false;
    while(1){
        left = (left)? 0 : 1;
        if(left){
            cout<<"\nPlayer Left\n";
        }
        else{
            cout<<"\nPlayer Right\n";
        }
        unsigned long long int v = getClick();
        xPix = v/65536;
        yPix = v%65536;
        int p,q;
        if(left){
            for(int i=0;i<16;i++){
                if((pLeft[i].x  - a/2) <xPix && xPix <(pLeft[i].x  + a/2)  && (pLeft[i].y  - a/2) <yPix && yPix <(pLeft[i].y  + a/2)){
                    v = getClick();
                    p = v/65536;
                    q = v%65536;
                    p = round((p - c + 40)/a);
                    q = round((q - d + 40)/a);
                    pLeft[i].set(p,q);
                    if((i>=0 && i<=7) && (p == 7) ){
                        cout<<"What you want to make your P\n"
                            <<"Queen press 1\n"
                            <<"Elephant press 2\n"
                            <<"Horse press 3\n"
                            <<"Camel press 4\n";
                            int promote;
                            cin >> promote;
                            if(promote == 1){
                                pLeft[i].msg = "QUEEN_N";
                            }
                            else if(promote == 2){
                                pLeft[i].msg = "ELEPHANT_N";
                            }
                            else if(promote == 3){
                                pLeft[i].msg = "HORSE_N";
                            }
                            else if(promote == 4){
                                pLeft[i].msg = "CAMEL_N";
                            }
                            pLeft[i].set(p,q);
                    }
                    break;
                }
            }
            if(capture(pRight , p,q,0) == 12){
                cout<<"\nPlayer Left Wins!!\n";
                break;
            }

        }
        else{
            for(int i=0;i<16;i++){
                if((pRight[i].x  - a/2) <xPix && xPix <(pRight[i].x  + a/2)  && (pRight[i].y  - a/2) <yPix && yPix <(pRight[i].y  + a/2)){
                    v = getClick();
                    p = v/65536;
                    q = v%65536;
                    p = round((p - c + 40)/a);
                    q = round((q - d + 40)/a);
                    pRight[i].set(p,q);
                    if((i>=0 && i<=7) && (p == 7) ){
                        cout<<"What you want to make your P\n"
                            <<"Queen press 1\n"
                            <<"Elephant press 2\n"
                            <<"Horse press 3\n"
                            <<"Camel press 4\n";
                            int promote;
                            cin >> promote;
                            if(promote == 1){
                                pRight[i].msg = "QUEEN_N";
                            }
                            else if(promote == 2){
                                pRight[i].msg = "ELEPHANT_N";
                            }
                            else if(promote == 3){
                                pRight[i].msg = "HORSE_N";
                            }
                            else if(promote == 4){
                                pRight[i].msg = "CAMEL_N";
                            }
                            pRight[i].set(p,q);
                    }
                    break;
                }
            }
            if(capture(pLeft , p,q,1) == 12){
                cout<<"\nPlayer Right Wins!!\n";
                break;
            }
        }
    }
    getClick();
}