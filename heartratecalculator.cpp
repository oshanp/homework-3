#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class HeartRates {

	private:
		int date, month, year; //DOB
		string fname, lname; //Name
		float age, MaxHR, TarHR;

	public:
	HeartRates(string aa, string bb, int dd, int mm, int yy){
		fname = aa;
		lname = bb;
		date = dd;
		month = mm;
		year = yy;
	}
	
	
       //Set and Print Name member functions
	void setName(string f, string l){
		fname = f;
		lname = l;
	}

	void getName(){
		cout << "\n\n\nName: " << lname << ", " << fname << endl;
	}


	//Set and Print Date of Birth member functions
	void setDOB(int d, int m, int y){
		
		date = d;
		month = m;
		year = y;
	}

	void getDOB(){
		cout << "\nThe Date of Birth(mmddyyyy) is: " << month << "  " << date<< "  " << year << endl;
	}


	//Function to Calculate person's age
	void getAge() {
		int cd,cm,cy;	
		bool checkdate = true;

		while (checkdate){
	
//Month restrictions
		cout << "\n\nEnter this month (mm): " << endl;
		cin >> cm;
		while (cin.fail() || (cm < 1 || cm > 12) ) {
			cout << "Invalid Input\n";
			cin.clear();
			cin.ignore();
			cout << "Enter this month (mm): " << endl;
			cin >> cm;
		}
		
//Date Restrictions	
		cout << "\nEnter today's date (dd): ";
		cin >> cd;
		if ((cm == 1 || cm == 3 || cm == 5 || cm == 7 || cm == 8 || cm == 10 || cm == 12) && (cd < 1 || cd > 31)){  
         		cout << "Invalid Input!\n";
			cout << "\nEnter today's date (dd): ";
			cin >> cd;
			while (cin.fail()) {
			cout << "Invalid Input!\n";
				cin.clear();
				cin.ignore();
				cout << "\nEnter today's date (dd): ";
				cin >> cd;
	
    			}


		}	
	  
       		if (cm == 2 && (cd < 1 || cd > 29)){       
         
		cout << "Invalid Input!\n";
		cout << "\nEnter today's date (dd): ";
		cin >> cd;
		while (cin.fail()) {
			cout << "Invalid Input!\n";
			cin.clear();
			cin.ignore();
			cout << "\nEnter today's date (dd): ";
			cin >> cd;

    			}

		}

	 	if ((cm == 4 || cm == 6 || cm == 9 || cm == 11) && (cd < 1 || cd > 30)){
 		cout << "Invalid Input!\n";
		cout << "\nEnter today's date (dd): ";
		cin >> cd;
		while (cin.fail()) {
			cout << "Invalid Input!\n";
			cin.clear();
			cin.ignore();
			cout << "\nEnter today's date (dd): ";
			cin >> cd;

    			}

		} 
//Year restrictions
	cout << "\n\nEnter this year (yyyy): ";
        cin >> cy;
	while (cin.fail() || (cy < 1500 || cy > 5100) ){
		cout << "Invalid Input!\n";
		cin.clear();
		cin.ignore();
		cout << "\nEnter this year (yyyy): ";
 		cin >> cy;
	}

	checkdate = false;
}	
		
		if (date > cd){
		cm = cm -1;
		cd = cd + 30;
		}


		if (month > cm){
		cy = cy - 1;
		cm = cm + 12;
		}

 age = (cy - year)+ ((cm - month)/float(12)) + ((cd - date)/float(365));
cout << "\n\n\nThe age is: " << age << endl;
		
}

	
	void getMaximumHeartRate(){
		 MaxHR = 220 - age;
		 cout << "Maximum Heart Rate is: " << MaxHR << endl;
	}

	void getTargetHeartRate(){
		TarHR = (.50 * MaxHR);
	       cout << "Your target heartrate should be in the range of: " << TarHR << "  to " << (.85* MaxHR) << endl;
       	 }
};

int main()
{
	string first_name, last_name;
	cout << "Enter your first name: ";
	cin >> first_name;
	cout << "\nEnter your last name: ";
	cin >> last_name;


	int a,b,c;
	bool checkdob = true;
	while (checkdob){

//Year restrictions
	cout << "\n\nEnter your birth year (yyyy): ";
        cin >> a;
	while (cin.fail() || (a < 1500 || a > 5100) ){
		cout << "Invalid Input!\n";
		cin.clear();
		cin.ignore();
		cout << "\nEnter your birth year (yyyy): ";
 		cin >> a;
	}

// Month restrictions
	cout << "\nEnter your birth month (mm): ";
	cin >> b;
	while (cin.fail() || (b < 1 || b > 12)){
		cout << "Invalid Input!\n";
		cin.clear();
		cin.ignore();
		cout << "\nEnter your birth month (mm): ";
		cin >> b;
	}

// Day restrictions
 	cout << "\nEnter your birth day (dd): ";
	cin >> c;
	
		if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && (c < 1 || c > 31)){  
         		cout << "Invalid Input!\n";
			cout << "\nEnter your birth day (dd): ";
			cin >> c;
			while (cin.fail()) {
			cout << "Invalid Input!\n";
				cin.clear();
				cin.ignore();
				cout << "\nEnter your birth day (dd): ";
				cin >> c;
	
    			}


		}	
	  
       		if (b == 2 && (c < 1 || c > 29)){       
         		cout << "Invalid Input!\n";
			cout << "\nEnter your birth day (dd): ";
			cin >> c;
			while (cin.fail()) {
			cout << "Invalid Input!\n";
				cin.clear();
				cin.ignore();
				cout << "\nEnter your birth day (dd): ";
				cin >> c;
	
    			}
		}

	 	if ((b == 4 || b == 6 || b == 9 || b == 11) && (c < 1 || c > 30)){
 		cout << "Invalid Input!\n";
			cout << "\nEnter your birth day (dd): ";
			cin >> c;
			while (cin.fail()) {
			cout << "Invalid Input!\n";
				cin.clear();
				cin.ignore();
				cout << "\nEnter your birth day (dd): ";
				cin >> c;
	
    			}
		}       


	checkdob = false;	
}

	HeartRates h1(first_name, last_name, c, b, a);
	
	h1.setName(first_name, last_name);
	h1.getName();
	h1.setDOB(c, b, a);
	h1.getDOB();
	h1.getAge();
	h1.getMaximumHeartRate();
	h1.getTargetHeartRate();
	

	return 0;
}


	


