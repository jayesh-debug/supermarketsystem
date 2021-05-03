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
    int retdis(){
        return dis;

    }

};
      fstream fp;
      fstream fp2;
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
        if (pr.retno() == no){
            pr.show_product();
            cout<<"please Enter The New Details of Product"<<endl;
            pr.create_product();
            int pos = -1 * sizeof(pr);
            fp.seekp(pos, ios::cur);
            fp.write((char* ) & pr,sizeof(product));
            cout<<"Record Updated";
            found=1;
        }
    }
    fp.close();
    if(found==0)
    cout<<"Record Not found";
    getch();
  }

  void delete_product(){
      int no;
      cout<<"DELETE RECORD";
      cout<<"Please Enter The product No.of the product YOu want to DELETE";
      cin>>no;
      fp.open("Temp.dat",ios::out);
      fp.seekg(0, ios::beg);
      while (fp.read((char * )& pr, sizeof(product)))
      {
          if(pr.retno() !=no)
          {
              fp2.write((char * ) & pr, sizeof(product));

          }
      }
      fp2.close();
      fp.close();
      remove("shop.dat");
      rename("Temp.dat", "shop.dat");
      cout<<"Reor deleted..";
      getch();

  } 
   
   void menu(){
       fp.open("shop.dat", ios:: in);
       if(!fp){
           cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n GO TO ADMIN MENU TO create File";
           cout<<"\n\n\n Programis closing ...";
           getch();
       }
       cout<<"Product Menu";
       cout<<"=========================="<<endl;
       cout<<"P.NO.\t\tName\t\tPRICE\n";
       cout<<"============================="<<endl;
       while (fp.read((char* ) & pr, sizeof(product)))
       {
           cout<<pr.retno()<<endl<<pr.retname()<<endl<<pr.retprice()<<endl;

       }
       fp.close();
   }
    void place_order()
    {
        int order_arr[50], quan[50], c = 0;
        float amt, damt, total=0;
        char ch='Y';
       menu();
       cout<<"\n====================";
       cout<<"\n PLACE YOUR ORDER"<<endl;
       cout<<"\n====================="<<endl;

       do {
           cout<<"Enter the poduct No. of The product :";
           cin>>order_arr[c];
           cout<<"Quantity in number"<<endl;
           cin>>quan[c];
           c++;
           cout<<"Do you Want to Order Another  Product? (y/n"<<endl;
           cin>>ch;

       } 
       while (ch=='y' || ch=='y');
       cout<<"Thank You For Placing The Order";
       getch();
       cout<<"\n\n****************************** INVOICE ****************************\n"<<endl;
    cout<<"\npr No.\tpr Name\tQuatntity\tPrice\tAmount \tAmount after discount\n"<<endl;
    for (int x=0;x<=c;x++){
        fp.open("shop.dat" ,ios::in);
        fp.read((char*) & pr, sizeof(product));
        while (!fp.eof()){
            if(pr.retno() == order_arr[x])
            {
                 amt=pr.retprice() * quan[x];
                 damt=amt-(amt * pr.retdis() /100);
                 cout<<"\n "<<order_arr[x]<<"\t"<<pr.retname()<<"\t"<<quan[x]<<"\t\t"<<pr.retprice()<<"\t"<<amt<<"\t\t"<<damt;
                 total +=damt;

            }
            fp. read((char* ) & pr, sizeof(product));

        }
        fp.close();
    }
    cout<<"Total ="<<total<<endl;
    getch();

    }
    void intro () {

        cout<<endl<<endl<<"SUPER MARKET";
        cout<<endl<<endl<<"BILLING";
        cout<<endl<<endl<<"PROJECT";
        cout<<"MADE BY : SUPERMARKET SYS";
        cout<<endl<<"Website : WWW.PupapersBook.com";
        getch();

    }
     void admin_menu() {
         char ch2;
         cout<<"ADMIN MENU";
         cout<<"CREATE PRODUCT";
         cout<<"DISPLAY ALL PRODUCTS"<<endl;
         cout<<"QUERIY"<<endl;
         cout<<"MODIFY PRODUCT"<<endl;
         cout<<"DELETE PRODUCT"<<endl;
         cout<<"VIEW PRODUCT MENU"<<endl;
         cout<<"BACK To MAIN MENU";
         cout<<"PLEASE Enter your choice(1-7)";
         ch2=getche();
         switch (ch2){
             case '1':
             write_product();
             break;
             case '2':
             display_all();
             break;
             case '3':
             int num;
             cout<<"Please Enter The Product No."<<endl;
             cin>>num;
             display_sp(num);
             break;
             case '4':
             modify_product();
             break;
             case '5':
             delete_product();
             break;
             case '6' :
             menu();
             getch();
             case '7':
             break;
             default:
             cout<<"\a";
               admin_menu();

        
         }
    
    
     }



     int main(){
         char ch;
         intro ();
         do 
         {
             cout<<"MAIL MENU";
             cout<<"CUSTOMER";
             cout<<"ADMINISITRATOR";
             cout<<"EXIT";
             cout<<"PLEASE SELECT Your Option (1-3)";
             ch=getche();
             switch(ch){
                 case '1':
                 place_order();
                 getch();
                 break;
                 case '2':
                 admin_menu();
                 break;
                 case '3' :
                 return 0;
                 default :
                 cout<<"\a";

    
             }

         }while (ch != '3');
     }