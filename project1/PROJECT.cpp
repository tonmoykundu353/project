/// CREATING ALUMNI LIST & USE OF OOP CONCEPTS
#include<bits/stdc++.h>
using namespace std;
class Virtual_func
{
public :                                                   /// using pure virtual function
    virtual string getUsername()=0;
    virtual string getPassword()=0;
    virtual int get_batch()=0;
    virtual string get_dept()=0;
};
///-----------------------------------------------------------------------------------
class User : public Virtual_func         /// inheritance
{

    string username;
    string password;
    string dept_name;
    int batch_year;
    int roll;
public:
    User(int roll,int batch_year,string username,string dept_name,string password);/// parameterized constructor
    ~User() {}                                                                                                                             /// using destructor
    inline string getUsername()
    {
        return username;                                                                    /// inline function
    }
    inline string getPassword()
    {
        return password;                                                                   /// inline function
    }
    inline int get_batch()
    {
        return batch_year;                                                                /// inline function
    }
    inline string get_dept()
    {
        return dept_name;                                                                 /// inline function
    }
};
///------------------------------------------------------------------------------------------------------------
User :: User(int roll,int batch_year,string username,string dept_name,string password)  /// parameterized constructor
{
    this->username = username;                                                       /// using this pointer
    this->password = password;
    this->batch_year=batch_year;
    this->dept_name=dept_name;
    this->roll=roll;
}
///----------------------------------------------------------------------------------------------------------
template<class T>
class String                                                 /// creating a generalized class (TEMPLATE)
{
    T name()
    {
        T username;
        cout<<endl<<"\t\tEnter your Name : ";
        getline(cin,username);
        cout<<username;
        return username;
    }
    T Password()
    {
        T password;
        cout<<endl<<"\t\tEnter your password : ";
        getline(cin,password);
        cout<<password;
        return password;
    }
public :
    T getname()
    {
        T str=name();
        return str;
    }
    T get_password()
    {
        T str=Password();
        return str;
    }
};
///-------------------------------------------------------------------------------------------------------------------
class UserManager :public  String<string>                         /// using INHERITANCE
{
    vector<User> users;                                                    /// using STL (container VECTOR)

public:
    void RegiserUser();
    bool LoginUser(string name,string pass,UserManager usermanage);
    void showUser();
    void searchUser(string username);
    void deleteUser(string username);
    friend ostream& operator<< (ostream &out,vector<User> &users);    /// using friend function
};
///-----------------------------------------------------------------------------------------------------
ostream& operator<< (ostream &out,vector<User> &users)    /// operator overloading
{
    cout<<endl<<"\t\t1.do you want see the whole alumni list ?";
    cout<<endl<<"\t\t2.do you want see any particular department ?";
    cout<<endl<<"\t\tEnter your choice : ";
    int choice ;
    cin>>choice;
    cout<<choice;
    switch(choice)
    {
    case 1:
    {
        cout<<endl<<endl<<"\t\t---Alumni List---"<<endl<<endl;
        for(int i = 0; i<users.size(); i++)
        {
            out<<"\t\t"<<i+1<<". "<<users[i].getUsername();
            out<<"  dept : "<<users[i].get_dept();
            out<<"  Batch : "<<users[i].get_batch()<<endl;

        }
        break;
    }
    case 2:
    {
        cout<<endl<<"\t\tEnter department name :";
        string department;
        cin>>department;
        cout<<department;
        cout<<endl<<endl<<"\t\t---Alumni List---"<<department<<" department"<<endl<<endl;
        for(int i = 0; i<users.size(); i++)
        {
            if(users[i].get_dept()==department)
            {
                out<<"\t\t"<<i+1<<". "<<users[i].getUsername();
                out<<"  Batch : "<<users[i].get_batch()<<endl;
            }
        }
        break;
    }
    }
    return out;
}
///-----------------------------------------------------------------------
void UserManager :: RegiserUser()
{
    cout<<endl;
    string username;
    string password;
    string department;
    int batch_year;
    int roll;

    String<string> st;    /// creating object for generalized String
    username= st.getname();

    cout<<endl<<"\t\tEnter department Name : ";
    getline(cin,department);
    cout<<department;

    cout<<endl<<"\t\tEnter batch : ";
    cin>>batch_year;
    cout<<batch_year;

    cout<<endl<<"\t\tEnter full roll : ";
    cin>>roll;
    cout<<roll;

    string choice;
    cout<<endl<<"\t\tDo you want to give a Password [yes/no]: ";
    cin>>choice;
    cin.ignore();
    cout<<choice;

    if(choice=="yes" || choice=="Yes")
    {
        password=st.get_password();
    }
    else
    {
        cout<<endl<<"\t\tyour password will be your roll "<<endl<<endl;
        password=to_string(roll);                                                                         /// using an inbuilt function
    }
    User newUser(roll,batch_year,username,department,password);       /// User parameterized constructor call
    users.push_back(newUser);
    cout<<endl<<"\t\tNew User Register Successfully ....."<<endl;
}
///---------------------------------------------------------------
void UserManager :: showUser()
{
    if(users.size()==0)
    {
        cout<<endl<<"\t\tNo one registred till now "<<endl;
        return ;
    }
    cout<<users;                    /// using overloaded form of insertion operator for vector users

}
void UserManager :: searchUser (string username)
{
    for(int i=0; i<users.size(); i++)
    {
        if(users[i].getUsername() == username)
        {
            cout<<endl<<"\t\tyes "<<users[i].getUsername()<<" is coming"<<endl;
            return ;
        }
    }
    cout<<endl<<"\t\talumni Not registered till now"<<endl;
}
///----------------------------------------------------------------------------------------
bool UserManager :: LoginUser(string name,string pass,UserManager usermanage)
{
    for(int i = 0; i<users.size(); i++)
    {
        if(users[i].getUsername()==name && users[i].getPassword() == pass)
        {
            cout<<endl<<"\t\tLogin Successfully...."<<endl;
            cout<<endl<<"\t\t what are you looking for ?"<<endl;
            cout<<"\t\t1. Show Alumni List "<<endl;
            cout<<"\t\t2. Search Alumni "<<endl;
            cout<<"\t\t3. Exit"<<endl;
            cout<<endl<<"\t\tEnter Your Choice : ";
            cin>>i;
            cin.ignore();
            cout<<i;
            switch(i)
            {
            case 1:
            {
                usermanage.showUser();
                break;
            }
            case 2:
            {
                cout<<endl;
                String st;
                usermanage.searchUser(st.getname());
                break;
            }
            case 3:
                exit(1);
            }
            return true;
        }
    }
    cout<<endl<<"\t\tInvalid User Name or Password for login..."<<endl;
    return false;
}
///------------------------------------------------------------------------------------
void create_alumni_list(UserManager &usermanage)
{
    int op;
    string choice;
    do
    {
        system("cls");
        cout<<endl<<endl<<"\t\t<<-----  Registration for Reunion 2050  ----->> "<<endl<<endl<<endl<<endl;
        cout<<"\t\t1. Register New Alumni "<<endl;
        cout<<"\t\t2. Login "<<endl;
        cout<<"\t\t3. Exit"<<endl;
        cout<<endl<<"\t\tEnter Your Choice : ";
        cin>>op;
        cin.ignore();
        cout<<op;
        switch(op)
        {
        case 1:
        {
            usermanage.RegiserUser();
            break;
        }
        case 2:
        {
            string username;
            string password;

            String<string> st;
            username= st.getname();
            password=st.get_password();

            usermanage.LoginUser(username,password,usermanage);
            break;
        }
        case 3:
            exit(1);
        }
        cout<<endl<<"\t\tDo You Want to Continue [Yes/ No] ? :";
        cin>>choice;
        cout<<"\t\t"<<choice;
    }
    while(choice == "yes" || choice =="Yes" || choice=="y" || choice=="Y");
}
///-----------------------------------------------------------------------------------------------
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    UserManager usermanage;
    create_alumni_list(usermanage);

    return 0;
}

