#include "RoadMap.h"
#include "App.h"
#include "Handler.h"

using namespace std;

int main(){
    RoadMap* rm = RoadMap::getInstance();
    rm->viewMap();

    uint cross = rm->getCrossroadIdFromAddress("Rua Orfeao do Porto", 120);

    string filename;
    App application;

   ifstream test;

    do{
        cout << "Introduce filename: ";
        getline(cin, filename);
        if(filename == "")
            break;
        test.open(filename.c_str());
        if(!test.is_open())
            cout << "File doesn't exist!" << endl;
    }while(!test.is_open());

    if(filename != "") {
        try {
            application.readData(filename);
        } catch (FileReadingError &e) {
            cout << "Error reading file." << endl;
            return 1;
        }
    }

	   try {
       application.readDataRides("ridesDatabase.txt");
      } catch (FileReadingError &e) {
          cout << "Starting without RidesTest." << endl;
      }

    int choice, counter = 0;
    do{
        do{
            if (counter != 0){
                cout << "You have introduced an invalid option!\n" << endl;
            }
            cout << "3 - View All Info" << endl;
            cout << "2 - Request Ride" << endl;
            cout << "1 - Offer Ride" << endl;
            cout << "0 - Exit Application" << endl;

            cout << "Choose appropriate numerical option: ";
            cin >> choice;
            counter ++;
        }while( (choice < 0) || (choice > 3));
        counter = 0;

        switch(choice){
            case 3:
                //TODO: SHOW INFO
                //application.displayAllInfo();
                application.showUsersInfo();
                cout<<endl;
                break;
            case 2:
            case 1:
                createRide(application, choice);
                break;
            case 0:
                cout<<"Exiting..." << endl;
                return 0;
            default:
                return 3;
        }
    }while(1);
}
