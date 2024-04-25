#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int maxrow = 10;

string userName[maxrow] = {};
string userId[maxrow] = {};

void openFile()
   {
        string line;

        ifstream myfile("D:\\users.txt");

        if(myfile.is_open())
        {
            int i=0;
            while(getline(myfile, line))
            {
                int l = line.length();
                userId[i] = line.substr(0, 3);
                userName[i] = line.substr(4, l-4);
                i++;
            }
        }
        else
        {
            cout << "\nEnable to Open users.txt file.";
        }
   }

void addRecord()
{
    char id[5];
    char name[50];

    cin.ignore();

    cout << "\nEnter User Id : ";
    cin.getline(id, 5);
    cout << "Enter User Name : ";
    cin.getline(name, 50);

    for(int i=0; i<maxrow; i++)
    {
        if(userId[i] == "\0")
        {
            userId[i] = id;
            userName[i] = name;
            break;
        }
    }

}

void listRecord()
{
    system("CLS");
    cout << "Current Records" << endl;
    cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = " << endl << endl;

    cout << "   No   |" << "   ID   |" << "             Name             |\n";
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" ;

    int counter=0;

    for(int i=0; i<maxrow; i++)
    {
        if(userId[i] != "\0")
        {
            counter++;
            cout << "   " << counter << "        " << userId[i] << "               " << userName[i] << endl;
        }
    }

    if(counter == 0)
    {
        cout << "\nNo Records found.\n";
    }
    cout << "\n= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n";

}

void searchRecord(string search)
{
    system("CLS");
    cout << "Current Records" << endl;
    cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = " << endl;

    cout << "   No   |" << "   ID   |" << "             Name             |\n";
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" ;

    int counter = 0;

    for(int i=0; i<maxrow; i++){
        if(userId[i] == search)
        {
            counter++;

            cout <<"   " << counter << "   |" << "   " << userId[i] << "   |" << "             " << userName[i] << endl;
            break;
        }
    }
    if(counter == 0)
    {
        system("CLS");
        cout << "\nid does not exist." << endl;
    }
    cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = " << endl;
}

void updateRecord(string search)
{
    char name[50];
    char id[5];

    int counter = 0;

    for(int i=0; i<maxrow; i++)
    {
        if(userId[i] == search)
        {
            counter++;

            cout << "Enter update name : " ;
            cin.getline(name, 50);

            userName[i] = name;
            system("CLS");
            cout << "\nUpdate successful." << endl;
            break;
        }
    }

     if(counter == 0)
    {
        system("CLS");
        cout << "\nid does not exist." << endl;
    }
    cout << "\n= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = " << endl;
}

deleteRecord(string search)
{
    int counter = 0;

    for(int i=0; i<maxrow; i++){
        if(userId[i] == search)
        {
            counter++;

            userName[i] = "";
            userId[i] = "";

            system("CLS");

            cout << "\nDeleting record is successful." << endl;
        }
    }

    if(counter == 0)
    {
        system("CLS");
        cout << "\nNo records found." << endl;
    }
    cout << "\n= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = " << endl;
}

void saveFile()
{
    ofstream myfile;
    myfile.open("D:\\users.txt");

    for(int i=0; i<maxrow; i++)
    {
        if(userId[i] == "\0")
        {
            break;
        }
        else
        {
            myfile << userId[i] + "," + userName[i] << endl;
        }
    }
}

int main()
{
   cout << "\nMenu\n" << endl;
   cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;

   int option;
   string id;
   openFile();

   do{
        cout << "\n1 - Create Records" << endl;
        cout << "2 - Update Records" << endl;
        cout << "3 - Delete Records" << endl;
        cout << "4 - Search Records" << endl;
        cout << "5 - Display All Records" << endl;
        cout << "6 - Exit and save records to textFile" << endl << endl;
        cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n" << endl;

        cout << "Select Option >> ";
        cin >> option;

        switch(option)
        {
            case 1:
                addRecord();
                system("CLS");
                break;
            case 2:
                cin.ignore();
                cout << "\nEnter ID to search : ";
                getline(cin, id);
                updateRecord(id);
                break;
            case 3:
                cin.ignore();
                cout << "\nEnter ID to delete record : ";
                getline(cin, id);
                deleteRecord(id);
                break;
            case 4:
                cin.ignore();
                cout << "\nEnter ID to search : ";
                getline(cin, id);
                searchRecord(id);
                break;
            case 5:
                listRecord();
                break;

        }
   }while (option != 6);

   saveFile();
   cout << "\nExist... saving data is success.\n";
    return 0;
}
