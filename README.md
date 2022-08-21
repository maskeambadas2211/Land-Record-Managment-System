# Land-Record-Managment-System
Basic Land Record Management System using C language and Data Structures
C++ Project synopsis
Land Records Display System
Abstract (Synopsis) :
The urban local body will use this software for sharing the land records online. The different users will be displayed a map on computer screen and the users will choose to select the plots for which they want to see the records. The various records like 1) ownership 2) Land value 3) Adjoining Landuse 4) Land holders name 5) Latitude and Longitude for plot.
This all is attributed to single layer and this layer will be displayed to user and user will choose the plot for which he wants the information.
The link which shares the similar idea is as follows:
http://www.mpcb.gov.in/air-quality
In this link a map is displayed and when user choose a location it will direct them further database display.





Class Diagrams:-
Class user
protected:
string name, u_name, pass ;

public:
user();
int create_login();
int login();

Class plot : public user
private:
    string s, plot_no, name, address, area, landuse;
                 string lat_t, long_t;
public:
    vector <long double > j_latitude, j_longitude;
    vector <string> j_plot_no, j_name,j_address,j_area, j_landuse;
                 long double i_lat, i_long;
                 long double to_float(const string & str);
                 void show_data(int k);
                 void read_data();
                 int find_temp(std:: vector <string> &ff, string &key);
                 int d_find_temp(std:: vector <long double> &ff, long double &key);
                 int neighbour(std:: vector <long double> &gg, long double &key1, std:: vector <long double> &ff, long double &key2);
                 void show_data(int c, int d,int x, int y);

 
Concepts Used in the project :-
	Object oriented programming
	Class and objects
	Function Overloading
	Operator Overloading
	Constructor and Destructor
	CSV File Handling
	Error handing
	Standard Template Library
	Vector and Maps
	Inheritance
	Multi-Threading
	Encapsulation
Project Outcomes:-
1)	Create a user defined login details
2)	Search for customised  data in  the  csv 
3)	Display the  user defined search values
4)	Display the Users’ adjoining Land  or Plots Details such as owner name, landuse and plot number.
5)	Successful visualisation of the land records.
6)	Map showing Plots Information.
Advantages:-
1)	Urban Local Bodies will be helped by this. ULB will be able to display the land record available with them to the public. We can see the example of the same from the website of mahabhumi.gov.in 
2)	Encapsulation.
3)	Most User friendly code.
4)	Customisation.
Limitations:- 
1)	Due to limited time available, this project was tested on the smaller area of Ahmednagar Gaothan area.
2)	The Image/map cannot be shown using c++ code hence given separately. Hence attached with the  code in zipped file.
Logic For Finding the Location  of  North, East, South, West of plot :-
For any co-ordinate we are searching the pair of another co-ordinates in the whole csv . The  logic applied here based on the spatial data i.e. latitude and longitude. 
let say x,y  are original plots lat long and x1,y1are co-ordinates of the plot which direction we are aiming to find out  .
1)	 So x1, y1 is said to be at its North when the (x =x1 or x < x1 or x>x1) and (y < y1)
2)	So x1, y1 is said to be at its East when the  (x > x1) and (y =y1 or y> y1 or y < y1) 
3)	So x1, y1 is said to be at its South when the (x =x1 or x < x1 or x>x1) and (y >y1) 
4)	So x1, y1 is said to be at its West when the (x < x1) and (y =y1 or y> y1 or y < y1)
