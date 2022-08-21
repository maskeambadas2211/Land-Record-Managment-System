// Hi, Wlecome to the code example for Land Record Management using c++

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;
// creating the  user class for which the  user can be log in and just can save the information
class user
{
      protected:
        string name, u_name, pass ; // data variables
     public:
         user(){ // constructor
         name = 'Ambadas';}
        void create_login()  //  member functions  for creating an account on the site
        {
            cout <<"***************Creating User Login***************\n" << endl;
            // creating username and password from user..
            cout <<"Create your user_name " << endl;
            cin >> u_name;
            cout <<"Create your password " << endl;
            cin >> pass;
            cout << "Account Created Successfully !!! \n\n Please login into your account to enter the personal details\n \n Loading....... Please Enter any key to start further...........\n\n"<< endl;
            system("PAUSE");
            system("CLS");
            login();
        }
        void login() // Entering in the login system
        {
            string m_name, m_pass;
            cout <<" Enter your user_name " << endl;
            cin >> m_name;
            cout <<"Enter your password " << endl;
            cin >> m_pass;
            cout <<" validating results... Please wait...\n " << endl;
            if( u_name == m_name &&  pass == m_pass ) //checking the given user name and password
            {
                cout << "Login successfully !! \n\n Entering into your account .....\n "<<endl;
            }
            else { //if error show error message
                cout << " Invalid  credential Please try again;"<<endl;
                login();
            }
        }
};

class plot :  public user // using inheritance from user class
{
private:
    // assigning values from user's csv file to individual data
    string s, plot_no, name,address,area, landuse;
    string lat_t,long_t;

public:
    // creating vector for storing each column from csv .
    vector <long double > j_latitude, j_longitude;
    vector <string> j_plot_no, j_name,j_address,j_area, j_landuse;
    long double i_lat, i_long;
    //function to convert string to  decimal value
    long double to_float(const string & str)
    {
       std::istringstream iss(str);
        long double num = 0;
        iss >> num;
        return num;
    }
    //  function for showing the details of owner
    void show_data(int k)
    {
        cout << "\n The owner details  are  :- \n" <<  "Name:- "<< j_name[k]<<"\n"<<"Plot_no:- "<<j_plot_no[k]<<"\n"<<"Plot_Address "<<j_address[k]<<"\n"<<"Plot_Land use:- "<<j_landuse[k]<<"\n"<<"Plot_Lattitude - "<< setprecision(10)<<j_latitude[k]<<"\n"<<"Plot_Longitude:- "<< setprecision(10)<<j_longitude[k]<<"\n"<<"Plot_Area (Sq.m):- "<<j_area[k]<< endl;
    }
    //function to read data and store each csv's column into separate vector
    void read_data()
    {
            string t_input ;
            ifstream file2;
            file2.open("E:\\Sem-6\\OOPD_Minor\\End Sem Project\\Fianl_Start\\Final_Code\\Final_Plot_Details__.csv", ios::in); // import the file into code
            if (file2.is_open()) // check if it is open
            {
                while (getline(file2, t_input))
                {
                    std::stringstream ss(t_input); // read data from file  line by line
                     // reading from each column
                    getline (ss, plot_no,',');
                    getline (ss, lat_t,',');
                    getline (ss, long_t,',');
                    getline (ss, name,',');
                    getline (ss, landuse,',');
                    getline (ss, area,',');
                    getline (ss, address);
                    // converting latitude string ti latitude float value
                    i_lat = to_float(lat_t);
                    i_long = to_float(long_t);
                    // inserting each element into vector
                    j_latitude.push_back(i_lat);
                    j_longitude.push_back(i_long);
                    j_plot_no.push_back(plot_no);
                    j_name.push_back(name);
                    j_landuse.push_back(landuse);
                    j_area.push_back(area);
                    j_address.push_back(address);
                }
            }
            else //check if file not found
            {
                cout <<"Bad File, can't open the file" << endl;
                exit(0);
            }

        }
    // function for  searching the string data in csv file
    int find_temp(std:: vector <string> &ff, string &key)
        {
            std:: vector<string>:: iterator itr ;// create iterator
            itr = find( ff.begin(), ff.end(), key); // search for the string
            if (itr != ff.end()) //if found
            {
                int b = std::distance(ff.begin(), itr) ; // find the index number of that item
                return b;
            }
            else{cout <<"\nSorry !!! Data You are Searching for  \t"<< key << "  is not in our Directory"<<endl;
            exit(0);}
        }
         // function for  searching decimal  data in csv file
        int d_find_temp(std:: vector <long double> &ff, long double &key)
        {
            std:: vector<long double>:: iterator itr ;
            itr = find( ff.begin(), ff.end(), key);
            if (itr != ff.end())
            {
                int b = std::distance(ff.begin(), itr) ;
                return b;
            }
            else{cout <<"\n Sorry !!! Data You are Searching for  \t"<< setprecision(10) <<key << "  is not in our Directory"<<endl;
            exit(0);}
        }
         // function for  searching the north and south;s neighbour of the plot
        int neighbour(std:: vector <long double> &gg, long double &key1, std:: vector <long double> &ff, long double &key2)
        {
            cout << "\nShowing you the Neighbours Details" <<endl;
            vector <long double> sorted_loc1(gg);
            sort(sorted_loc1.begin(), sorted_loc1.end());
            vector <long double> sorted_loc2(ff);
            sort(sorted_loc2.begin(), sorted_loc2.end());
            // search for key
           int w = d_find_temp(sorted_loc1, key1);
           int v = d_find_temp(sorted_loc2, key2);
           //if found search for its closest greater value and again search it in parent vector
           int h =d_find_temp(gg, sorted_loc1[w+1]);
           int a =d_find_temp(ff, sorted_loc2[v+1]);
           //if found search for its closest lower value and again search it in parent vector
           int b= d_find_temp(ff, sorted_loc2[v-1]);
           int g = d_find_temp(gg, sorted_loc1[w-1]);
           cout <<endl;
           show_data(h, g, a, b); // show the neighbours data
        }
        // function for showing the neighbours customised data
        void show_data(int c, int d,int x, int y)
        {
            cout <<"\nThe Plot details to given plot's  'East'  direction are as follows: - "<< endl;
            cout <<"\nName:- "<< j_name[c]<<"\n"<<"Plot_no:- "<<j_plot_no[c]<<"\n"<<"Plot_Land use:- "<<j_landuse[c]<<endl;
            cout <<"\nThe Plot details to given plot's  'North'  direction are as follows: - \n"<< endl;
            cout <<"\nName:- "<< j_name[y]<<"\n"<<"Plot_no:- "<<j_plot_no[y]<<"\n"<<"Plot_Land use:- "<<j_landuse[y]<<endl;
            cout <<"\nThe Plot details to given plot's  'West'  direction are as follows: - "<< endl;
            cout <<"\nName:- "<< j_name[d]<<"\n"<<"Plot_no:- "<<j_plot_no[d]<<"\n"<<"Plot_Land use:- "<<j_landuse[d]<<endl;
            cout <<"\nThe Plot details to given plot's  'South'  direction are as follows: - \n"<< endl;
            cout <<"\nName:- "<< j_name[x]<<"\n"<<"Plot_no:- "<<j_plot_no[x]<<"\n"<<"Plot_Land use:- "<<j_landuse[x]<<endl;
        }
};

int main()
{

    cout << "\n ___________________**********   Welcome to our Land Record Management System  **********___________________\n" << endl ;
    cout << "\nBefore Proceeding to our system , Please create your login details \n" << endl;
    user u1; // creating object of user class
    plot p; // creating object of plot class
    //u1.create_login(); // creating login
    system("PAUSE");
    p.read_data();
    int a;
    char b, ch;
    string id;
    do
    {
        system("CLS");
        cout <<"What you want to search for \n1.By Owners Name \n2. By Latitude and Longitude \n3. By Plot Number " << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            {
                cout << "Enter the name in this format FIRSTNAME-MIDDLENAME-LASTNAME \n(note:- all the entries should be in capital letters only)"<< endl;
                cin >> id;
                int m = p.find_temp(p.j_name, id);
                p.show_data(m);
                cout<< "\nDo you wnat to know your plot's north and south direction plor's  information?? Y/ N" << endl;
                cin >> b;
                if(b == 'Y' || b == 'y')
                {
                    system("PAUSE");
                    system("CLS");
                    p.neighbour(p.j_latitude, p.j_latitude[m],p.j_longitude, p.j_longitude[m]);
                }
                else (exit(0));
                break;
            }
        case 2:
            {
                cout << "Enter the Latitude and Longitude of the Plot \n Enter Longitude \n(note:- you must Enter the lat , long in precious level up to 8 only)"<< endl;
                long double latt, longg;
                cin >> latt;
                cout << "Enter the Latitude"<<endl;
                cin>> longg;
                int m = p.d_find_temp(p.j_latitude, latt);
                int n = p.d_find_temp(p.j_longitude, longg);
                if ( m == n )
                {
                    p.show_data(m);
                    cout<< "\nDo you wnat to know your plot's north and south direction plor's  information?? Y/ N" << endl;
                    cin >> b;
                    if(b == 'Y' || b == 'y')
                    {
                        system("PAUSE");
                        system("CLS");
                        p.neighbour(p.j_latitude, p.j_latitude[m],p.j_longitude, p.j_longitude[m] );
                    }
                    else (exit(0));
                }
                break;
            }
        case 3:
            {
                cout << "Enter the Plot No "<< endl;
                cin >> id;
                int m = p.find_temp(p.j_plot_no, id);
                p.show_data(m);
                cout<< "\nDo you wnat to know your plot's north and south direction plor's  information?? Y/ N" << endl;
                cin >> b;
                if(b == 'Y' || b == 'y')
                {
                    system("PAUSE");
                    system("CLS");
                    p.neighbour(p.j_latitude, p.j_latitude[m],p.j_longitude, p.j_longitude[m] );

                }
                else (exit(0));
                break;
            }
        default :
            cout<<"Wrong selection !! Please Try again..."<< endl;
            break;
        }cout <<"\n\nDo you want to continue for search any other plot details "<<endl;
        cin>> ch;
    }while (ch!='n');

    return 0;
}



