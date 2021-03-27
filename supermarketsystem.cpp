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
  void display_all(){
        

        cout<<"Display All RECORD"<<endl;
        fp.open("shop.dat", ios::in);
        while (fp.read((char* ) & pr, sizeof(product)))
        {
            pr.show_product();
            cout<<"\n\n========================\n"<<endl;
            getch();
        }
     fp.close();
     getch();
  }
  void display_sp(int n)
  {
      int flag =0;
      fp.open("shop.dat", ios:: in);
      while (fp.read((char *)& pr, sizeof(product)))
      {
          if(pr.retno() == n){


              pr.show_product();
              flag=1;
          }
      }
      fp.close();
      if (flag==0)
      cout<<"record not exist"<<endl;
      getch();
  }
  void modify_product(){
      int no,found=0;
      cout<<"Modify"<<endl;
      cout<<"Please Enter The Product NO.of the Product"<<endl;
    cin>>no;
    fp.open("Shop.dat", ios:: in | ios::out);
    while (fp.read((char *)& pr, sizeof(product)) && found ==0)
    {
        if (pr.retno() == no)
    }
  }