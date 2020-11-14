#include<bits/stdc++.h>
#include <Windows.h>
using namespace std; 
void welcome()
{
    ifstream in("welcome.txt"); 
   
    if(!in) {
       cout << "Cannot open input file.\n";
    }
    char str[1000];
    while(in) {
       in.getline(str, 1000);  // delim defaults to '\n' cp
       if(in) cout << str << endl;
    }
    in.close();
    Sleep(1000);
    cout<<"\nStarting the program please wait....."<<endl;
    Sleep(1000);
    cout<<"\nloading up files....."<<endl;
    Sleep(1000); //function which waits for (n) seconds
    system ("CLS"); //cleares screen
}

void art()
{   
    system ("CLS");
    ifstream in("art.txt"); 
   
    if(!in) {
       cout << "Cannot open input file.\n";
    }
    char str[1000];
    while(in) {
       in.getline(str, 1000);  // delim defaults to '\n' cp
       if(in) cout << str << endl;
    }
    in.close();
    cout<<"\n\n\n";
}

void T_and_C()
{
    system ("CLS");
    ifstream in("T&C.txt"); 
   
    if(!in) {
       cout << "Cannot open input file.\n";
    }
    char str[1000];
    while(in) {
       in.getline(str, 1000);  // delim defaults to '\n' cp
       if(in) cout << str << endl;
    }
    in.close();
}

void thanks()
{   
    system ("CLS");

    ifstream in("thanks.txt"); 
   
    if(!in) {
       cout << "Cannot open input file.\n";
    }
    char str[1000];
    while(in) {
       in.getline(str, 1000);  // delim defaults to '\n' cp
       if(in) cout << str << endl;
    }
    in.close();
}

void displayCar()
{
    fstream f;
    f.open("car rental.txt" , ios::in);
    if(!f)
    cout<<"File not open\n";
    string str;
    cout<<"\tPlate Number";
    cout<<"  Brand";
    cout<<"\tName";
    cout<<"\t  Year";
    cout<<"  Seats";
    cout<<" Colour";
    cout<<"\tAC";
    cout<<"   A/M";
    cout<<"  Rent/D";
    cout<<endl<<endl;
    while (getline(f, str))
    {
        cout<<"\t"<<str<<endl;
    }
    cout<<"\n\n";
}

class car
{
    private:
	char plate_num[10];
	char brand[20];
	char name[20];
	char model[20];
	int capacity;
	char colour[20];
	char AC[6];
	char transmission;
	float rate_per_day;

    public:
    // operator overloading using friend function
    friend istream& operator >> (istream& in, car&);
};
istream & operator >> (istream& is,car& c){
    fstream ofs;
    ofs<<endl;
	ofs.open("car rental.txt" , ios::app | ios::out);
    cout<<"\n\t\t Please Enter Car Data Below : ";
    cout<<"\n\t\t Enter Plate Number : ";
    is>>c.plate_num;
    ofs<<c.plate_num<<"    ";
    cout<<"\n\t\t Enter Brand Name : ";
    is>>c.brand;
    ofs<<c.brand<<"    ";
    cout<<"\n\t\t Enter Name of the Car : ";
    is>>c.name;
    ofs<<c.name<<"    ";
    cout<<"\n\t\t Enter Model Year : ";
    is>>c.model;
    ofs<<c.model<<"    ";
    cout<<"\n\t\t Enter Capacity : ";
    is>>c.capacity;
    ofs<<c.capacity<<"    ";
    cout<<"\n\t\t Enter Colour : ";
    is>>c.colour;
    ofs<<c.colour<<"    ";
    cout<<"\n\t\t Enter AC/NON-AC : ";
    is>>c.AC;
    ofs<<c.AC<<"    ";
    cout<<"\n\t\t Enter Transmission (A/M) : ";
    is>>c.transmission;
    ofs<<c.transmission<<"    ";
    cout<<"\n\t\t Enter Rate/day : ";
    is>>c.rate_per_day;
    ofs<<c.rate_per_day<<"    ";
    ofs.close();
    cout<<"\n\n";
    return is;
}
class user
{
    private:
    string custName;
    int id;
    string pNo;
    
    protected:
    void showRent(int rent,vector<string> info,int days);

    public:
    user()
    {
        this->custName = "Admin";
        id = 1;
        pNo = "0123456789";
    }
    void showCar(){
        displayCar();
    }
    void getUserInfo();
    void rentCar();
    void returnCar();
};

void user::getUserInfo(){
    fstream f;
	f.open("userInfo.txt" , ios::app | ios::out);
    f<<"___________________________________________________\n";
    cout<<"\n\t\t Please Enter User Data Below : ";
    cout<<"\n\t\t Enter Name : ";
    cin>>custName;
    f<<"Customer Name : "<<custName<<"\n";
    cout<<"\n\t\t Enter id : ";
    cin>>id;
    f<<"Customer id : "<<id<<"\n";
    cout<<"\n\t\t Enter Phone Number : ";
    cin>>pNo;
    f<<"Phone Number : "<<pNo<<"\n";
    f.close();
}

void user::rentCar(){
    cout<<endl;
    displayCar();
    cout<<endl;
    string enter,nameRent;
    cout<<"\tEnter the NAME of the car you want to rent : ";
    cin>>nameRent;
    cout<<"\n\tEnter the Plate Number of the car you want to rent : ";
    cin>>enter;
    
    fstream file;
    string word, filename, str = "";
    int ind;
    filename = "car rental.txt";
    file.open(filename.c_str());

    while (file >> word)
    {
        str = str + " " + word;
    }
    for (int i = 0; i <= str.size(); i++)
    {
       unsigned index = str.find((enter));
        if (index != string::npos){
           ind  = index/46;
           break;
        }
        else{
        cout<<"\tSorry we don't have a car with that Number Plate, please try again!";
        return;
        }
    
    }
    file.close();

    fstream f,f1,f2;
    f.open("rented.txt", ios::app | ios::out);
    f1.open("car rental.txt",ios::in | ios::out);
    f2.open("temp.txt",ios::out);

    // cout<<ind<<"\n";
    
    string c,s="";
    while (getline(f1, c))
    {
        if(ind>0)
        {
            f2<<c<<endl;
        }
        else if(ind==0)
        {
            f<<c<<endl;
            s = s + c;
        }
        else
        {
            f2<<c<<endl;
        }
        ind--;
    }   
    f.close();
    f1.close();
    f2.close();
    remove("car rental.txt");
    rename("temp.txt", "car rental.txt");
    fstream fr;
	fr.open("userInfo.txt" , ios::app | ios::out);
    fr<<"Car Rented : \n";
    fr<<s<<endl;
    fr<<"___________________________________________________\n";
    fr.close();
    vector<string> info;
    string words;
    stringstream iss(s);
    while (iss >> words) 
       {
           info.push_back(words);
       }
    
    stringstream ch(info[8]);

    int rent = 0;
    ch >> rent;

    int days;
    cout<<"\n\tEnter the number of days you want to rent "<<nameRent<<" : ";
    cin>>days;

    rent = rent * days;
    showRent(rent,info,days);
}

void user::returnCar(){
   
    string enter;
    cout<<"\n\tEnter the Plate Number of the car you want to return : ";
    cin>>enter;
    
    fstream file;
    string word, filename, str = "";
    int ind;
    filename = "rented.txt";
    file.open(filename.c_str());

    while (file >> word)
    {
        str = str + " " + word;
    }
    for (int i = 0; i <= str.size(); i++)
    {
       unsigned index = str.find((enter));
        if (index != string::npos){
           ind  = index/50;
           break;
        }
        else{
        cout<<"\tWrong input, please try again!";
        return;
        }
    }
    file.close();
    ind++;

    fstream f,f1,f2;
    f.open("car rental.txt", ios::app | ios::out);
    f1.open("rented.txt",ios::in | ios::out);
    f2.open("temp.txt",ios::out);
    
    string c,s="";
    while (getline(f1, c))
    {
        if(ind>0)
        {
            f2<<c<<endl;
        }
        else if(ind==0)
        {
            f<<c<<endl;
            s = s + c;
        }
        else
        {
            f2<<c<<endl;
        }
        ind--;
    }   
    f.close();
    f1.close();
    f2.close();
    remove("rented.txt");
    rename("temp.txt", "rented.txt");

    cout<<"\tSuccessfully Returned the Car\n\n";
    cout<<"\tReturned Car info : \n";
    cout<<"\t"<<s<<endl;

}

void user::showRent(int rent,vector<string> info,int days)
    {
        system("CLS");
    cout << "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t	| Invoice No. :"<<"-------------------|"<<"#Cnb81353"<<" |"<<endl;
    cout << "\t\t	| Customer Name:"<<"------------------|"<<setw(12)<<custName<<" |"<<endl;
    cout << "\t\t	| Customer ID:"<<"--------------------|"<<setw(12)<<id<<" |"<<endl;
    cout << "\t\t	| Customer Ph.No:"<<"-----------------|"<<setw(12)<<pNo<<" |"<<endl;
    cout << "\t\t	| Car No. :"<<"-----------------------|"<<setw(12)<<info[0]<<" |"<<endl;
    cout << "\t\t	| Car Company :"<<"-------------------|"<<setw(12)<<info[1]<<" |"<<endl;
    cout << "\t\t	| Car Name :"<<"----------------------|"<<setw(12)<<info[2]<<" |"<<endl;
    cout << "\t\t	| Car Model Yr:"<<"-------------------|"<<setw(12)<<info[3]<<" |"<<endl;
    cout << "\t\t	| Car Seats:"<<"----------------------|"<<setw(12)<<info[4]<<" |"<<endl;
    cout << "\t\t	| Car Colour:"<<"---------------------|"<<setw(12)<<info[5]<<" |"<<endl;
    cout << "\t\t	| Car AC/NON-AC:"<<"------------------|"<<setw(12)<<info[6]<<" |"<<endl;
    cout << "\t\t	| Car Transmission:"<<"---------------|"<<setw(12)<<info[7]<<" |"<<endl;
    cout << "\t\t	| Number of days :"<<"----------------|"<<setw(12)<<days<<" |"<<endl;
    cout << "\t\t	| Your Rental Amount is :"<<"---------|"<<setw(12)<<rent<<" |"<<endl;
    cout << "\t\t	| Caution Money :"<<"-----------------|"<<setw(12)<<"1000"<<" |"<<endl;
    cout << "\t\t	| Advance :"<<"-----------------------|"<<setw(12)<<"0"<<" |"<<endl;
    cout << "\t\t	 ________________________________________________________"<<endl;
    cout <<"\n";
    cout << "\t\t	| Total Rental Amount is :"<<"--------|"<<setw(12)<<rent+1000<<" |"<<endl;
    cout << "\t\t	| # Caution Money Rs.1000 will be returned on return of the car  |"<<endl;
    cout << "\t\t	 _______________________________________________________________ |"<<endl;
    cout << "\t\t	| # This is a computer generated invoce and it does not          |"<<endl;
    cout << "\t\t	    require an authorised signture #                             |"<<endl;
    cout <<" "<<endl;
    cout << "\t\t	/////////////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t	| You are advised to pay up the amount before due date.          |"<<endl;
    cout << "\t\t	| Otherwise penelty fee will be applied                          |"<<endl;
    cout << "\t\t	/////////////////////////////////////////////////////////////////"<<endl;
	
}

class admin
{
    private:
    string pass;
    
    public:
    admin(){
        this->pass = "admin"; 
    }
    string retPass(){
       return pass;
    }
    void showCar(){
        displayCar();
    }
    void addCar(){
        car C1;
        cin>>C1;
    }
    void delCar();
};

void admin::delCar(){
    showCar();
    string enter;
    cout<<"\n\n\t\tEnter the Plate Number of the car you want to delete : ";
    cin>>enter;
    
    fstream file;
    string word, filename, str = "";
    int ind;
    filename = "car rental.txt";
    file.open(filename.c_str());

    while (file >> word)
    {
        str = str + " " + word;
    }
    for (int i = 0; i <= str.size(); i++)
    {
       unsigned index = str.find((enter));
        if (index != string::npos){
           ind  = index/50;
           break;
        }
        else{
        cout<<"\n\t\tSorry we don't have a car with that Number Plate, please try again!";
        return;
        }
    }
    ind++;
    file.close();

    fstream f,f1;
    f.open("car rental.txt", ios::in | ios::out);
    f1.open("temp.txt",ios::out);
    
    string c,s="";
    while (getline(f, c))
    {
        if(ind>0)
        {
            f1<<c<<endl;
        }
        else if(ind==0)
        {
            s = s + c;
        }
        else
        {
            f1<<c<<endl;
        }
        ind--;
    }   
    f.close();
    f1.close();
    remove("car rental.txt");
    rename("temp.txt", "car rental.txt");

    cout<<"\n\t\tSuccessfully Removed the Car";
    cout<<"\n\t\tRemoved Car info : \n";
    cout<<"\t\t"<<s<<"\n";
}

void adminFun(){
    admin ad;
    string pass;
    art();
    cout<<"\t\tPlease Enter the Password! : ";
    cin>>pass;
    if(pass!=ad.retPass()) 
    {
        cout<<"\n\n\t\tWrong Password, Try Again!\n\n";
        system("PAUSE");
        return;
    }   
    a:
    art();
    cout<<"\n\n\t\t 1. ADD A CAR \n\t\t 2. DISPLAY ALL CARS \n\t\t 3. DELETE A CAR \n\t\t 4. LOG OUT \n\n\t\t";
    int ch;
    cout<<"Enter Your Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        system("CLS");
        art();
        Sleep(500);
        ad.addCar();
        system("PAUSE");
        system("CLS");
        goto a;
        break;
        case 2:
        system("CLS");
        art();
        Sleep(500);
        ad.showCar();
        system("PAUSE");
        system("CLS");
        goto a;
        break;
        case 3:
        system("CLS");
        art();
        Sleep(500);
        ad.delCar();
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto a;
        break;
        case 4:
        Sleep(1000);
        cout<<"\n\n\t\tLOGGING OFF.....\n";
        Sleep(1000);
        system("CLS");
        break;
        default:
        cout<<"\n\n\t\tWrong Input. Try agin!\n";
        Sleep(2000);
        system("CLS");
        goto a;
        break;
    }
    
}

void userFun(){
    user us;
    system("CLS");
    art();
    Sleep(500);
    us.getUserInfo();
    system("PAUSE");
    system("CLS");
    u:
    art();
    cout<<"\n\n\t\t 1. DISPLAY ALL CARS \n\t\t 2. RENT A CAR \n\t\t 3. RETURN A CAR \n\t\t 4. LOG OUT \n\n\t\t";
    int ch;
    cout<<"Enter Your Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        system("CLS");
        art();
        Sleep(500);
        us.showCar();
        system("PAUSE");
        system("CLS");
        goto u;
        break;
        case 2:
        system("CLS");
        art();
        Sleep(500);
        us.rentCar();
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto u;
        break;
        case 3:
        system("CLS");
        art();
        Sleep(500);
        us.returnCar();
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto u;
        break;
        case 4:
        Sleep(1000);
        cout<<"\n\n\t\tLOGGING OFF.....\n";
        Sleep(1000);
        system("CLS");
        break;
        default:
        cout<<"\n\n\t\tWrong Input. Try agin!\n";
        Sleep(2000);
        system("CLS");
        goto u;
        break;
    }
}

int main()
{   
    welcome();
    l:
    art();
    cout<<"\n\n\t\t======= Welcome To Car Rental Shop =======\n\t\t 1. ENTER AS ADMIN \n\t\t 2. ENTER AS CLIENT \n\t\t 3. T%C \n\t\t 4. EXIT \n\n\t\t";
    int ch;
    cout<<"Enter Your Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        adminFun();
        system("CLS");
        goto l;
        break;
        case 2:
        userFun();
        system("CLS");
        goto l;
        break;
        case 3:
        system("CLS");
        Sleep(1000);
        T_and_C();
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto l;
        break;
        case 4:
        system("CLS");
        Sleep(1500);
        cout<<"\n\n";
        thanks();
        cout<<"\n\n\n";
        break;
        default:
        cout<<"\n\t\tWrong Input. Try agin!";
        Sleep(2000);
        system("CLS");
        goto l;
        break;
    }

    return 0;
}


