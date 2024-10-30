#include "string_array.h"

using namespace std;


myStr::myStr(const char* ch){
    length = 0;
    data = new char [1000];
    memset(data, 0, sizeof(data[0])*1000);
    while (ch [length]){
    	//cout <<ch[length];
        data[length] = ch[ length ];
        length ++;
    }
    //cout <<endl;
    //for (int i=0; i< length; i++)
    //	cout <<data[i];
    //cout <<endl;
    //data[length] = ch[ --length ];  
    next = NULL;
    nextVal = NULL;
}
myStr::~myStr(){
    data = NULL;
    length = 0;
    next = 0;
    nextVal =0;
}
void myStr::print(){
    for(int i = 0; i < this->length; i++)
        cout << this->data[i];

    cout << endl;
}

void myStr::kmp_next(){
    int i = 1, j = 0;
    next [i] = 0;
    while (i < length){
        if (j==0 && data[i] == data [j]){
            i++; j++;
            next [i] = j;
        }else
        j = next[j];
    }
}

void myStr::kmp_nextVal(){
    int i = 1, j = 0;
    nextVal [i] = 0;
    while (i < length){
        if (j==0 && data[i] == data[j]){
            i++; j++;
            if (data[i] != data[j] ) nextVal [i] = j;
            else nextVal[i] = nextVal[j];
        }else
        j = nextVal[j];
    }
}


bool replaceStr(myStr& S, const int& start_id, const myStr& T, const myStr& V){
    if (start_id > S.length ) return 0;
    int i = start_id, j = 1;
    S.kmp_nextVal();
    while (i < S.length && j < T.length){
        if (j==0 || S.data[i] == T.data[j]){
            i++;j++;
        }else
        j = S.nextVal[j];
    }
    if (j <= T.length) return 0;
    char* ch0= new char [S.length];
    for (int i=0; i < start_id; i++)
        ch0[i] = S.data[i];
    for (int i=start_id; i< start_id + V.length;i++)
        ch0[i] = V.data [i - start_id];
    for (int i=start_id + T.length; i<S.length; i++)
        ch0[i - T.length + V.length] = S.data [i];
    S.data = ch0;
    return 1;
}
    
int kmpMatch(const myStr&, const myStr&);
// friend int simpleMatch(const myStr&, const myStr&);




void myStr::printNext(){
    for(int i = 0; i < length; i++)
        cout << next[i];
    cout << endl;
}

void myStr::printNextVal(){
    for(int i = 0; i < length; i++)
        cout << nextVal[i];
    cout << endl;
}

void myMatrix::printMatrix(){
    cout << rowNum << "," << colNum << "," << nodeNum << endl;

    for(int i = 0; i < nodeNum; i++)
        cout << nodeList[i].row << "," << nodeList[i].col << "," << nodeList[i].value << endl;
}

int main()
{
    myStr S("hello TJU!");
    myStr T("TJU");
    myStr T1("NKU");
    myStr T2("future");

//    S.print();
//    T.print();
//    T1.print();
//    T2.print();

    //int isFind;
    //isFind=replaceStr(S,8,T1,T2);
    //cout<<isFind<<endl;//0
    // isFind=replaceStr(S,1,T, T2);
    // cout<<isFind<<endl;//1
    // S.print();//hello future!
    // isFind=replaceStr(S,1,T1, T2);
    // cout<<isFind<<endl;//0

    // myStr matchS("aabaabaabaac");
    // myStr matchT("aabaac");

    // isFind=simpleMatch(matchS,matchT);
    // cout<<isFind<<endl;//7

     matchS.kmp_next();
     matchS.kmp_nextVal();
     matchS.printNext();//012123456789
     matchS.printNextVal();//002002002009

    // matchT.kmp_next();
    // matchT.kmp_nextVal();
    // matchT.printNext();//012123
    // matchT.printNextVal();//002003

    // isFind=kmpMatch(matchS,matchT);
    // cout<<isFind<<endl;//7

    return 0;
}