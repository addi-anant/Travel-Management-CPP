#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <windows.h>
#include <bits/stdc++.h>

using namespace std;

/* Function Declaration: */
void menu();

/* Valid Redirection:*/
void validRedirect() {
    system("CLS");

    cout << "Redirecting to the Main Menu \nPlease Wait!" << endl;
    Sleep(1100);
    system("CLS");
    menu();
}

/* Redirection To Main Menu: */
void redirectToMainMenu() {
    cout << "Press any key to Redirect Main Menu: ";

    char goToMenu;
    cin >> goToMenu;
    system("CLS");
    menu();
}

/* Redirection Incase Of Invalid Input:*/
void invalidRedirect(string info) {
    system("CLS");

    if(info.length() == 0) cout << "Invalid Input Provided. " << endl;
    if(info.length() != 0) cout << "Invalid Input Provided: " << info  << endl;
    
    cout << "Redirecting to Previous Menu \nPlease Wait!" << endl;
    Sleep(1100);
    system("CLS");
    menu();
}

class Customer {
    bool validName(string &name) {
        if(name.length() == 0) return false;

        for(auto x : name) if(isdigit(x)) return false;
        return true;
    }

    bool validAge(string &age) {
        if(age.length() != 2 && age.length() != 3) return false;

        for(auto x : age) if(!isdigit(x)) return false;
        return true;
    }

    bool validMobileNumber(string &mobileNo) {
        if(mobileNo.length() != 10) return false;

        for(auto x : mobileNo) if(!isdigit(x)) return false;
        return true;
    }

    bool validAddress(string &address) {
        if(address.length() == 0) return false;

        for(auto x : address) if(isdigit(x)) return false;
        return true;
    }

    bool validGender(string &gender) {
        if(gender.length() == 0) return false;

        for(auto x : gender) if(isdigit(x)) return false;
        return true;
    }
    
public:
    static int ID;
    char customerInfo[1000];
    string age, name, gender, address, mobileNo;

    /* Add new user Detail: */
    void addCustomerDetail() {
        cout << "Enter Customer ID: ";
        cin >> ID;

        cout << "Enter Customer Name: ";
        cin >> name;
        // Validation to Check if Name is valid:
        if(!validName(name)) invalidRedirect("Name.");

        cout << "Enter Customer Age: ";
        cin >> age;
        // Validation to Check if age is valid:
        if(!validAge(age)) invalidRedirect("Age.");

        cout << "Enter Customer Mobile Number: ";
        cin >> mobileNo;
        // Validation to Check if mobileNo is valid:
        if(!validMobileNumber(mobileNo)) invalidRedirect("Mobile Number.");
        
        cout << "Enter Customer Address (City): ";
        cin >> address;
        // Validation to Check if Address is valid:
        if(!validAddress(address)) invalidRedirect("Address.");

        cout << "Enter Customer Gender: ";
        cin >> gender;
        // Validation to Check if Gender is valid:
        if(!validGender(gender)) invalidRedirect("Gender.");

        
        ofstream out("old-customers.txt", ios::app); // open file using append mode.
        out << "\nCustomer ID: " << ID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;
        out.close();

        cout << "\nSaved \nNOTE: We save your details record for future purposes.\n" << endl;
    }

    /* Display Information Of All customer: */
    void showDetails() {
        ifstream in("old-customers.txt");

        if (!in) {
            cout << "Error! Couldn't read the File." << endl;
            return;
        }

        while (!(in.eof())) {
            in.getline(customerInfo, 1000);
            cout << customerInfo << endl;
        }

        in.close();
    }
};
int Customer::ID = 0;

class Cabs {
    bool validDistance(string &distance) {
        if(distance.length() == 0) return false;

        for(auto x : distance) if(!isdigit(x)) return false;
        return true;
    } 
public:
    float bill;
    char cab, hireCab;
    string  distance;
    static float lastCabBill;

    void cabDetails() {
        cout << "----------- ABC Cabs -----------\n" << endl;
        cout << "We collaborated with fastest, safest, and smartest cab service arround the country." << endl;
        cout << "1. Rent an Everyday Cab - Rs. 15/KM." << endl;
        cout << "2. Rent Our Premium Cab - Rs. 25/KM." << endl;

        cout << "\nTo calculate the cost for your journey, Enter which kind of cab you Need." << endl;
        cout << "To Go Back to main menu enter any another key. ";
        cin >> cab;

        switch(cab) {
        case '1':
            cout << "Enter distance you have to travel: ";
            cin >> distance;

            // Check if the distance is valid:
            if(!validDistance(distance)) invalidRedirect("Distance.");
            
            bill = stoi(distance) * 15;
            cout << "\nYour tour will cost " << bill << " rupees for an Everyday Cab" << endl;

            cout << "Press 1 to hire the cab." << endl;
            cout << "Press 2 to select another cab. " << endl;
            cin >> hireCab;

            system("CLS");

            switch(hireCab) {
            case '1':
                lastCabBill = (bill);
                cout << "\nYou have successfully hired the Everyday cab." << endl;
                cout << "Goto Menu to take the receipt." << endl;
                redirectToMainMenu();
            
            case '2':
                cabDetails();

            default:
                invalidRedirect("");
            }

        case '2':
            cout << "Enter distance you have to travel: ";
            cin >> distance;
            
            // Check if the distance is valid:
            if(!validDistance(distance)) invalidRedirect("Distance.");

            bill = stoi(distance) * 25;
            cout << "\nYour tour will cost " << bill << " rupees for the Premium Cab" << endl;

            cout << "Press 1 to hire the cab." << endl;
            cout << "Press 2 to select another cab. " << endl;
            cin >> hireCab;

            system("CLS");

            switch(hireCab) {
            case '1':
                lastCabBill = (bill);
                cout << "\nYou have successfully hired the Premium cab." << endl;
                cout << "Goto Menu to take the receipt." << endl;
                redirectToMainMenu();
            
            case '2':
                cabDetails();

            default:
                invalidRedirect(""); 
            }

        default: 
            validRedirect();
        }
    }
};
float Cabs::lastCabBill;

class Booking {
public:
    int stayDuration;
    static float hotelCost;
    char choiceHotel, packChoice;

    void availableHotelList() {
        string hotelNo[] = {"Avendra", "ChoiceYou", "ElephantBay"};

        cout << "\nWe have collaborated with the following hotels!" << endl;
        for (int i = 0; i < 3; i++) {
            cout << (i + 1) << ". Hotel " << hotelNo[i] << endl;
        }

        cout << "Enter Number of the hotel you want to book or see details." << endl;
        cout << "Press any key to go back to main menu. ";

        cin >> choiceHotel;
        system("CLS");

        switch(choiceHotel) {
        case '1':
            cout << "-------WELCOME TO HOTEL AVENDRA-------\n" << endl;
            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;

            cout << "Packages offered by Avendra:\n" << endl;
            cout << "1. Standard Pack: " << endl;
            cout << "   All basic facilities you need just for: Rs.5000.00\n" << endl;
            cout << "2. Premium Pack: " << endl;
            cout << "   Enjoy Premium: Rs.10000.00\n" << endl;
            cout << "3. Luxury Pack: " << endl;
            cout << "   Experience Luxury at Avendra: Rs.15000.00\n" << endl;

            cout << "\nEnter Package number you want to book." << endl;
            cout << "Press any other key to go back to the Main Menu. ";
            cin >> packChoice;

            switch (packChoice) {
            case '1':
                cout << "Enter the duration of your stay: ";
                cin >> stayDuration;

                hotelCost = stayDuration * 5000;
                cout << "\nYou have successfully booked Standard Pack at Avendra." << endl;
                cout << "Goto Menu and take the receipt." << endl;
                redirectToMainMenu();
                break;

            case '2':
                cout << "Enter the duration of your stay: ";
                cin >> stayDuration;

                hotelCost = stayDuration * 10000;
                cout << "\nYou have successfully booked Premium Pack at Avendra." << endl;
                cout << "Goto Menu and take the receipt." << endl;
                redirectToMainMenu();
                break;

            case '3':
                cout << "Enter the duration of your stay: ";
                cin >> stayDuration;

                hotelCost = stayDuration * 15000;
                cout << "\nYou have successfully booked Luxury Pack at Avendra." << endl;
                cout << "Goto Menu to take the receipt." << endl;
                redirectToMainMenu();
                break;

            default:
                validRedirect();
                break;
            }

            break;
        case '2':
            cout << "------- WELCOME TO HOTEL CHOICEYOU -------\n" << endl;
            cout << "Packages offered by ChoiceYou:\n" << endl;
            cout << "Swimming Pool | Free WiFi | Family Rooms | Fitness Center | Restaurant & Bar" << endl;

            cout << "1. Standard Pack: ";
            cout << "Rs.5000.00/day. \n" << endl;
            cout << "1. Family Pack: ";
            cout << "Rs.10000.00/day. \n" << endl;
            cout << "3. Luxary Pack: ";
            cout << "15000.00/day. \n" << endl;

            cout << "\nEnter Package number you want to book: " << endl;
            cout << "Press any other key to go back to the Main Menu. ";
            cin >> packChoice;

            switch (packChoice) {
            case '1':
                cout << "Enter the duration of your stay: ";
                cin >> stayDuration;

                hotelCost = stayDuration * 5000;
                cout << "\nYou have successfully booked Standard Pack at ChoiceYou." << endl;
                cout << "Goto Menu and take the receipt." << endl;
                redirectToMainMenu();
                break;
            
            case '2':
                cout << "Enter the duration of your stay: ";
                cin >> stayDuration;

                hotelCost = stayDuration * 10000;
                cout << "\nYou have successfully booked Family Pack at ChoiceYou." << endl;
                cout << "Goto Menu and take the receipt." << endl;
                redirectToMainMenu();
                break;
            
            case '3':
                cout << "Enter the duration of your stay: ";
                cin >> stayDuration;

                hotelCost = stayDuration * 15000;
                cout << "\nYou have successfully booked Luxary Pack at ChoiceYou." << endl;
                cout << "Goto Menu and take the receipt." << endl;
                redirectToMainMenu();
                break;

            default:
                validRedirect();
                break;
            }

            break;
        case '3':
            cout << "------- WELCOME TO HOTEL ELEPHANTBAY -------\n" << endl;
            cout << "Set in tropical gardens on the banks of the Maha Oya river While Seeing Elephants" << endl;
            cout << "Amazing offer For the Season: Rs.5000.00/day!!!" << endl;

            cout << "Press 1 to book the special package." << endl;
            cout << "Press any other key to go back to the Main Menu. ";
            cin >> packChoice;
            
            switch(packChoice) {
            case '1':
                cout << "Enter the duration of your stay: ";
                cin >> stayDuration;

                hotelCost = stayDuration * 5000;
                cout << "You have successfully booked ElephantBay Special Pack." << endl;
                cout << "Goto Menu and take the receipt." << endl;
                redirectToMainMenu();
                break;
            default:
                validRedirect();
                break;
            }

            break;
        default:
            validRedirect();
            break;
        }
    }
};
float Booking::hotelCost;

class Chargers : public Booking, Cabs, Customer {
public:
    void printBill() {
        ofstream outf("receipt.txt");
        outf << "--------ABC Travel Agency--------" << endl;
        outf << "-------------Receipt-------------" << endl;
        outf << "_________________________________" << endl;

        outf << "Customer ID: " << Customer::ID << endl
             << endl;
        outf << "Description\t\t Total" << endl;
        outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
        outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastCabBill << endl;

        outf << "_________________________________" << endl;
        outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost + Cabs::lastCabBill << endl;
        outf << "_________________________________" << endl;
        outf << "------------THANK YOU------------" << endl;

        outf.close();
    }

    void showBill() {
        ifstream inf("receipt.txt");
        if (!inf)
            cout << "Error! Cannot read receipt.txt" << endl;

        while (!(inf.eof())) {
            inf.getline(customerInfo, 1000);
            cout << customerInfo << endl;
        }

        inf.close();
    }
};


void menu() {
    char mainChoice;

    cout << "\t\t      * ABC Travels *\n" << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;

    cout << "\t|\t Customer Management -> 1\t|" << endl;
    cout << "\t|\t Cabs Management     -> 2\t|" << endl;
    cout << "\t|\t Booking Management  -> 3\t|" << endl;
    cout << "\t|\t Charges & Bill      -> 4\t|" << endl;

    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\n Enter Choice: ";
    cin >> mainChoice;

    system("CLS");

    Cabs cabObj;
    Chargers billObj;
    Booking bookingObj;
    Customer customerObj;

    switch (mainChoice) {
    case '1':
        cout << "------ Customers ------\n" << endl;
        cout << "1. Enter New Customer" << endl;
        cout << "2. See Old Customers" << endl;

        cout << "\n Enter choice: ";
        
        char inChoice;
        cin >> inChoice;

        system("CLS");

        switch (inChoice) {
        case '1':
            customerObj.addCustomerDetail();
            redirectToMainMenu();
            break;

        case '2':
            customerObj.showDetails();
            redirectToMainMenu();
            break;

        default:
            invalidRedirect("");
            break;
        }
        break;
    
    case '2':
        cabObj.cabDetails();
        break;
    
    case '3':
        cout << "--> Book a Luxury Hotel using the System <-- \n" << endl;
        bookingObj.availableHotelList();
        break;

    case '4':
        billObj.printBill();
        billObj.showBill();

        redirectToMainMenu();
        break;

    default:
        invalidRedirect("");
        break;
    }
}

int main() {
    system("CLS");
    menu();

    return 0;
}