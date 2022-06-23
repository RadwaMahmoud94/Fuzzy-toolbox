#include <iostream>
#include <bits/stdc++.h>
#include<fstream>
#include <iostream>
#include <sstream>
#include<cstring>
using namespace std;
int s3[20];
int counter=0;
double NegSm;
double NegMed;

//Operator AND returning the minimal value.
double AND(double a, double b)
{
    if(a < b)
        return a ;
    return b;
}
//Operator OR returning the maximal value
double OR(double a, double b)
{
    if(a > b)
        return a;
    return b;

}


double  fuzz(int x[],int n, int crisp)
{

    //0,0,10,35............4....................10
    //sort(x,x+n);
    int y[n];
    double M=0;

    if(n==3)
    {
        y[0]=0;
        y[1] =1;
        y[2]= 0;
        if(crisp>=x[0]&&crisp<x[1])
        {

            double m1= y[1]-y[0];
            double m2= x[1]-x[0];
            double m= m1/m2;

            double c= y[1]-(m*x[1]);
            M = (m*crisp)+c;

            s3[counter]=M;


        }
        else if(crisp>=x[1]&&crisp<x[2])
        {

            double m1= y[2]-y[1];
            double m2= x[2]-x[1];
            double m= m1/m2;


            double c= y[2]-(m*x[2]);
            M = (m*crisp)+c;

            s3[counter]=M;


        }





    }



    else if (n==4)
    {
        y[0]=0;
        y[1]=1;
        y[2]=1;
        y[3]=0;


        if(crisp>=x[0]&&crisp<x[1])
        {

            double m1= y[1]-y[0];
            double m2= x[1]-x[0];
            double m= m1/m2;

            double c= y[1]-(m*x[1]);
            M = (m*crisp)+c;

            s3[counter]=M;


        }
        else if(crisp>=x[1]&&crisp<x[2])
        {

            double m1= y[2]-y[1];
            double m2= x[2]-x[1];
            double m= m1/m2;

            double c= y[2]-(m*x[2]);
            M = (m*crisp)+c;

            s3[counter]=M;


        }

        else if(crisp>=x[2]&&crisp<x[3])
        {

            double m1= y[3]-y[2];
            double m2= x[3]-x[2];
            double m= m1/m2;

            double c= y[3]-(m*x[3]);
            M = (m*crisp)+c;

            s3[counter]=M;


        }

    }


    counter++;
    return M;
}


double  Inference(string s[], string s2[][10000],string line)
{


    int sizee= line.length();
    string arr[sizee];
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < sizee)
    {
        ssin >> arr[i];
        ++i;
    }


    if (s[0] == arr[0]&&s2[0][0]==arr[2]&&s2[1][0]==arr[6])
    {
        if(arr[3]=="AND")
            NegSm= AND(s3[0],s3[1]);
        else
            NegMed= OR(s3[0],s3[1]);


    }
    else if( s[0] == arr[4]&&s2[0][0]==arr[6]&&s2[1][0]==arr[2])
    {

        if(arr[3]=="AND")
            NegSm= AND(s3[0],s3[1]);
        else
            NegMed=OR(s3[0],s3[1]);

    }


}

double DEfuzzy(int x[])
{
    int centrouedNegBig=(( x[0]+ x[1]+ x[2])\3);
    int centrouedNegMed=(( x[0]+ x[1]+ x[2])\3);
    int centrouedNegSm=(( x[0]+ x[1]+ x[2])\3);
    int sumcentroued;
    sumcentroued=centrouedNegBig+centrouedNegMed+centrouedNegSm;




}


int main()
{
    ifstream  fee;
    fee.open("test1.txt") ;
    srand(time(NULL));

    int input;
    //cout<<"enter number of inputs"<<endl;
    fee>>input;
    string s[input];
    int arr[input];
    int nsets;
    string sets [input][10000];
    string shape;
    int p =0;
    for(int i=0; i<input+1; i++)
    {
        // cout<<"enter variable name"<<endl;
        fee>>s[i];
        // cout<<"enter value of crisp"<<endl;
        fee>>arr[i];
        //cout<<"enter number of sets"<<endl;
        fee>>nsets;

        int y =0;
        for(int k=0; k< nsets; k++)
        {

            // cout<<"enter 1 for triangular \n 2 for trapezoidal"<<endlcout<<"enter name of set"<<endl;;
            fee>>shape>>sets[k][y];

            if(shape=="triangle")
            {
                p=3;

            }
            else if(shape=="trapezoidal")
            {

                p=4;

            }
            int x[k][p];



            //  cout<<"enter value of points of set"<<endl;

            for(int j=0; j<p; j++)
            {

                fee>>x[k][j];

            }
            if(arr[i]>=x[k][0]&&arr[i]<x[k][p])
            {

                fuzz(x[k],p,arr[i]);

            }


            y++;

        }

    }
    string output ;
    fee>>output;

    int O;
    fee>>O;
    string setout[O];

    for(int k=0; k< O; k++)
    {

        // cout<<"enter 1 for triangular \n 2 for trapezoidal"<<endlcout<<"enter name of set"<<endl;;
        fee>>shape>>setout[k];

        if(shape=="triangle")
        {
            p=3;

        }
        else if(shape=="trapezoidal")
        {

            p=4;

        }
        int x[k][p];



        //  cout<<"enter value of points of set"<<endl;

        for(int j=0; j<p; j++)
        {

            fee>>x[k][j];

        }




        int num;
        // cout <<"inter number of rules";
        fee>>num;
        string line;
        for(int l=0; l<num; l++)
        {
            fee>>line;
            Inference(s,sets,line);


        }




    }

    return 0;

}
