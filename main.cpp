#include<fstream>
#include<iomanip>
#include<iostream>
#include<windows.h>
using namespace std;

// Function Declaration.
void menu(); 

class Customer {
public:
    static int cusID;
    char customerInfo[1000];
    int age, menuBack;
    string name, gender, address, mobileNo;

    /* Add new user Detail: */
    void addCustomerDetail() {
        cout << "\nEnter Customer ID: ";
        cin >> cusID;
        cout << "Enter Customer Name: ";
        cin >> name;
        cout << "Enter Customer Age: ";
        cin >> age;
        cout << "Enter Customer Mobile Number: ";
        cin >> mobileNo;
        cout << "Enter Customer Address (City): ";
        cin >> address;
        cout << "Enter Customer Gender: ";
        cin >> gender;

        ofstream out("old-customers.txt", ios::app); // open file using append mode.
        out << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;
        out.close();

        cout << "\nSaved \nNOTE: We save your details record for future purposes.\n" << endl;
    }

    /* Display Detial for All customer: */
    void showDetails() {
        ifstream in("old-customers.txt");
        
        if(!in) {
            cout << "File Error!" << endl;
            return;
        }
        
        while(!(in.eof())) {
            in.getline(customerInfo, 999);
            cout << customerInfo << endl;
        }
        in.close();
    }
};
int Customer::cusID;

class Cabs {
public:
    int cabChoice;
    int kilometers;
    float cabCost;
    static float lastCabCost;

    void cabDetails() {
        cout << "----------- ABC Cabs -----------\n" << endl;
        cout << "We collaborated with fastest, safest, and smartest cab service arround the country." << endl;
        cout << "1. Rent a Standard Cab - Rs. 15/KM." << endl;
        cout << "2. Rent a Luxury Cab - Rs. 25/KM." << endl;

        cout << "\nTo calculate the cost for your journey, Enter which kind of cab you need, Or to go back to main menu enter any another key.";
        cin >> cabChoice;

        if(cabChoice != 1 && cabChoice != 2) {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
 
        cout << "Enter Kilometers you have to travel: ";
        cin >> kilometers;

        int hireCab;
        if(cabChoice == 1){
            cabCost = kilometers * 15;
            cout << "\nYour tour will cost " << cabCost << " rupees for a standard cab" << endl;
            
            cout << "Press 1 to hire this cab: or ";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;
            
            system("CLS");
            
            if (hireCab == 1){
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired standard cab." << endl;
                cout << "Goto Menu to take the receipt." << endl;
            } else if (hireCab == 2) {
                cabDetails();
            } else {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                
                system("CLS");
                cabDetails();
            }
        } else if(cabChoice == 2){
            cabCost = kilometers * 25;
            cout << "\nYour tour will cost " << cabCost << " rupees for a luxury cab" << endl;
          
            cout << "Press 1 to hire this cab: or ";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;

            system("CLS");
          
            if (hireCab == 1){
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired luxury cab." << endl;
                cout << "Goto Menu to take the receipt." << endl;
            } else if(hireCab == 2){
                cabDetails();
            } else {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                
                system("CLS");
                cabDetails();
            }
        } 

        cout << "\nPress 1 to Redirect Main Menu: ";
        cin >> hireCab;
        system("CLS");
        if(hireCab == 1) menu();
    }
};
float Cabs::lastCabCost;

class Booking {
public:
    int goToMenu;
    int packChoice;
    int choiceHotel;
    static float hotelCost;

    void availableHotelList() {
        string hotelNo[] = {"Avendra", "ChoiceYou", "ElephantBay"};
        
        cout << "\nWe have collaborated with the following hotels!" << endl;
        for(int i = 0; i < 3; i++) {
            cout << (i + 1) << ". Hotel " << hotelNo[i] << endl;
        }

        cout << "Enter Number of the hotel you want to book or see details, Or Press any key to go back to main menu.";
        cin >> choiceHotel;

        system("CLS");

        if(choiceHotel == 1){
            cout << "-------WELCOME TO HOTEL AVENDRA-------\n" << endl;
            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;

            cout << "Packages offered by Avendra:\n" << endl;
            cout << "1. Standard Pack: " << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack: " << endl;
            cout << "\tEnjoy Premium: Rs.10000.00" << endl;
            cout << "3. Luxury Pack: " << endl;
            cout << "\tExperience Luxury at Avendra: Rs.15000.00" << endl;

            cout << "\nEnter Package number you want to book, Or Press any other key to go back to previous menu.";
            cin >> packChoice;

            if (packChoice == 1){
                hotelCost = 5000.00;
                cout << "\nYou have successfully booked Standard Pack at Avendra." << endl;
                cout << "Goto Menu and take the receipt." << endl;
            } else if (packChoice == 2){
                hotelCost = 10000.00;
                cout << "\nYou have successfully booked Premium Pack at Avendra." << endl;
                cout << "Goto Menu and take the receipt." << endl;
            } else if (packChoice == 3){
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked Luxury Pack at Avendra." << endl;
                cout << "Goto Menu to take the receipt." << endl;
            } else{
                cout << "Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                availableHotelList();
            }
        } else if(choiceHotel == 2){
            cout << "------- WELCOME TO HOTEL CHOICEYOU -------\n" << endl;
            cout << "Packages offered by ChoiceYou:\n" << endl;
            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

            cout << "1. Standard Pack:" << endl;
            cout << "\t Rs.5000.00/day." << endl;
            cout << "1. Family Pack:" << endl;
            cout << "\t Rs.10000.00/day." << endl;
            cout << "3. Luxary Pack:" << endl;
            cout << "\t 15000.00/day." << endl;

            cout << "\nEnter Package number you want to book: ";
            cout << "\nOr Press any other key to go back to previous menu.";
            cin >> packChoice;

            if (packChoice == 1){
                hotelCost = 5000.00;
                cout << "You have successfully booked Standard Pack at ChoiceYou." << endl;
                cout << "Goto Menu and take the receipt." << endl;
            } else if (packChoice == 2){
                hotelCost = 10000.00;
                cout << "You have successfully booked Family Pack at ChoiceYou." << endl;
                cout << "Goto Menu and take the receipt." << endl;
            } else if (packChoice == 3){
                hotelCost = 15000.00;
                cout << "You have successfully booked Luxary Pack at ChoiceYou." << endl;
                cout << "Goto Menu and take the receipt." << endl;
            } else{
                cout << "Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                availableHotelList();
            }
        } else if(choiceHotel == 3){
            cout << "------- WELCOME TO HOTEL ELEPHANTBAY -------\n" << endl;
            cout << "Set in tropical gardens on the banks of the Maha Oya river While Seeing Elephants" << endl;
            cout << "Amazing offer this summer: Rs.5000.00 for a one day!!! \nPress 1 to book this special package, Or Press any other key to go back to previous menu." << endl;

            cin >> packChoice;

            if (packChoice == 1){
                hotelCost = 5000.00;
                cout << "You have successfully booked ElephantBay Special Pack." << endl;
                cout << "Goto Menu and take the receipt." << endl;
            } else{
                cout << "Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                availableHotelList();
            }
        } else {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }

        cout << "\nPress any key to Redirect to Main Menu: ";
        cin >> goToMenu;
        system("CLS");
        menu();
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

        outf << "Customer ID: " << Customer::cusID << endl << endl;
        outf << "Description\t\t Total" << endl;
        outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
        outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;

        outf << "_________________________________" << endl;
        outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost + Cabs::lastCabCost << endl;
        outf << "_________________________________" << endl;
        outf << "------------THANK YOU------------" << endl;

        outf.close();
    }

    void showBill(){
        ifstream inf("receipt.txt");
        if(!inf) cout << "File Error!" << endl;

        while(!(inf.eof())) {
            inf.getline(customerInfo, 1000);
            cout << customerInfo << endl;
        }

        inf.close();
    }
};

void menu() {
    int inChoice, goToMenu, mainChoice;

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

    if(mainChoice == 1){
        cout << "------ Customers ------\n" << endl;
        cout << "1. Enter New Customer"<< endl;
        cout << "2. See Old Customers"<< endl;

        cout << "\n Enter choice: ";
        cin >> inChoice;

        system("CLS");
        if(inChoice == 1){
            customerObj.addCustomerDetail();
        } else if(inChoice == 2){
            customerObj.showDetails();
        } else {
            cout << " Invalid Input! Redirecting to Previous Menu \n Please Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }

        cout << "Press any key to Redirect Main Menu: ";
        cin >> goToMenu;
        system("CLS");
        menu();
    } else if(mainChoice == 2){
        cabObj.cabDetails();
    } else if(mainChoice == 3){
        cout << "--> Book a Luxury Hotel using the System <-- \n" << endl;
        bookingObj.availableHotelList();
    } else if(mainChoice == 4){
        billObj.printBill();
        billObj.showBill();
        
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> goToMenu;
        system("CLS");
        if(goToMenu == 1) menu();
    } else{
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main() {
    system("CLS");
    menu(); 

    return 0;
}