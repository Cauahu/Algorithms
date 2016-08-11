#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void renderPixel(vector<int> &screen, int x, int y) {
        // write code here
        int base[] = {0, 1, 3, 7, 15, 31, 63, 127, 255};
        int st = x / 8, en = y / 8;
        cout << "st: " << st << " en: " << en << endl;
        for(int i=st+1;i<en-1;++i){
            screen[i] = 255;
            //cout << screen[i] << endl;
        }
        int cir = 8 - (x % 8);
        //cout << screen[st] << ": " << cir << endl;
        screen[st] = base[cir];
        cir = 8 - (y % 8);
        //cout << screen[st] << ": " << cir << endl;
        screen[en] = base[cir];
}

void renderPixel(vector<int> &screen, int x, int y) {
    for(int i = x ; i <= y ; i ++)
            {
                int k = i % 8 ;
                int t = i / 8 ;
                screen[t] = screen[t] | (1<< k);
            }
}


int main()
{
    vector<int> screen(8,0);
    //cout << "construct successful" << endl;
    for(int i=0;i<8;++i)
        cout << screen[i] << " ";
    cout << endl;
    renderPixel(screen, 0, 47);
    for(int i=0;i<8;++i)
        cout << screen[i] << " ";
    cout << endl;
    return 0;
}
