#include<iostream>
#include<cstdio>
#include<conio.h>
#include<fstream>

using namespace std;
class product{
    int prno;
    float price,dis,qty,tax;
    char prname[50];
    public:
    void create_product(){
    cout<<"Please enter the no of product";
    cin>>prno;
    cout<<"Please enter name of product";
    cin>>gets(prname);
    cout<<"Enter price of product";
    cin>>price;
    cout<<"Enter discount of prouduct";
    cin>>dis;
    }
    void show_product(){
    cout<<"Enter the no of product"<<prno;
    cout<<"Name of product:";
    puts(prname);
    cout<<"price of product"<<price;
    cout<<"Discount of product"<<dis;

    }
    int retno(){
        return prno;

    }
    float retprice(){
        return price;
    }
    char * retname(){
        return prname;
    }
    int ratdis(){
        return dis;

    }

};
      fstream fp;
      product pr;

 
  void write_product(){
      fp.open("Shop.dat", ios::out | ios :: app);
      pr.create_product();
      fp.write((char *)& pr, sizeof(product));
      fp.close();
      cout<<"The proudct Has been created";
      getch();
  }