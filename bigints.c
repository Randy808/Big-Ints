#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef char stringC[256] ;


void initCArray(stringC b){


    for (int i = 0 ; i <256 ; i++)
    {
        b[i] = '0';
    }
}

int getSize(stringC a)
{
    int size = 0;
    for(int i = 0; i < 256 ; i++)
    {
         if(a[i] >= '0' && a[i] <= '9')
            size++;
         else
        {
            a[i] = '0';
            break;
        }

}


return size;

}


void add (stringC big1, stringC big2,int size, int size2)
{



    stringC bigSum;
    initCArray(bigSum);

    int remainder = 0;
    bool remainderOn = false;
    size2--;

    for(int i = size-1 ; i >= 0 ; i--)
    {

        int localSum = 0;

        if (size2 >=0)
        localSum = (big1[i] - '0') + (big2[size2] - '0');

        else
        localSum = (big1[i] - '0') ;

        size2--;

        //cout<< "BIG 1 :"<<(big1[i] - '0')<<endl;
       // cout<< "BIG 2 :"<<(big2[i] )<<endl;
        localSum+=remainder;


        if(localSum >= 10)
        {
            remainderOn = true;
            if(localSum == 10)
            remainder = 1;
            else
            remainder = localSum / 10;

            localSum-=remainder*10;
        }
        else
        {
        remainder = 0;
    }



        bigSum[i] = (char)(((int)'0') + localSum);




    }

    for(int i = 0 ; i < size; i++)
    {
       if(remainderOn && remainder > 0)
        {
            cout<<remainder;
            remainderOn = false;
        }
        cout<<bigSum[i];
       // else if(remainderOn)
         //cout<<"R"<<remainder;

    }

    cout<<endl;
}



int main()
{

stringC big1;
stringC big2;

initCArray(big1);
initCArray(big2);

cout<<"Enter a big int : ";

cin>>big1;

cout<<big1<<endl;;


cout<<"Enter a second big int : ";

cin>>big2;

cout<<big2<<endl;

//cout<<"\n Big 1 \n----------------------\n"<<getSize(big1)<<"\n Big 2 \n----------------\n"<<getSize(big2)<<"\n\n\n";

/***************ADD OUTPUT*********************/
cout<<endl<<big1<<endl;

cout<<"+"<<endl;

cout<<big2<<endl;

cout<<"\n ---------------------------\n";

int size1 = getSize(big1);
int size2 = getSize(big2);
//cout<<"A: \n"<<size<<endl;
//add(big1,big2,size, size2);


if(size1 > size2)
    add(big1,big2,size1,size2);
else
    add(big2,big1,size2,size1);





}




