#include <iostream>
#include <string>
#include <fstream>
#pragma warning(disable : 4996)

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
    bool isCorrect();
};
bool Date::isCorrect()
{
    bool result = false;

    if (month > 0 && month <= 12 && year <= 2021 && year >= 1900)
    {
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
            if ((day <= 31) && (day > 0))
                result = true;
            break;
        }

        case 4:
        case 6:
        case 9:
        case 11:
        {
            if ((day <= 30) && (day > 0))
                result = true;
            break;
        }

        case 2:
        {
            if (year % 4 != 0)
            {
                if ((day <= 28) && (day > 0))
                    result = true;
            }
            else
                if (year % 400 == 0)
                {
                    if ((day <= 29) && (day > 0))
                        result = true;
                }
                else
                    if ((year % 100 == 0) && (year % 400 != 0))
                    {
                        if ((day == 28) && (day > 0))
                            result = true;
                    }
                    else
                        if ((year % 4 == 0) && (year % 100 != 0))
                            if ((day <= 29) && (day > 0))
                                result = true;
            break;
        }

        default:
            result = false;
        }
    }
    return result;
}

struct kith
{
    int serialnumber;
    string FIO;
    Date birthday;
    string address;
    string numberphone;
};

void inputinfo(kith friends[], const int K)
{
    for (size_t i = 0; i < K; i++)
    {

        cout << "\nSerial number: " << i + 1 << endl;
        friends[i].serialnumber = i + 1;

        cout << "\nEnter your last name, first name and patronymic: ";
        cin.ignore(cin.rdbuf()->in_avail());
        getline(cin, friends[i].FIO, '\n');

        do
        {
            for (;;)
            {

                cout << "\nEnter Year of Birth (Year Month Day): ";
                cin.ignore(std::cin.rdbuf()->in_avail());
                if (cin >> friends[i].birthday.year >> friends[i].birthday.month >> friends[i].birthday.day)
                {
                    break;
                }
                else
                {
                    cerr << "[Error] Enter the correct value and numbers!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        } while (!friends[i].birthday.isCorrect());

        cout << "\nEnter address: ";
        cin.ignore(cin.rdbuf()->in_avail());
        getline(cin, friends[i].address, '\n');
        int check_temp = 0;
        do {
            check_temp = 0;
            cout << "\nEnter phone number, no country code, no spaces, only numbers: ";
            cin.ignore(cin.rdbuf()->in_avail());
            getline(cin, friends[i].numberphone, '\n');
            for (size_t j = 0; j < (friends[i].numberphone).length(); j++)
            {
                if (isdigit(friends[i].numberphone[j]) == 0)
                {
                    check_temp += 1;
                    break;
                }
            }
        } while (check_temp != 0);
    }
}

void outputinfo(kith friends[], const int A)
{
    for (size_t i = 0; i < A; i++)
    {
        cout << friends[i].serialnumber << endl;
        cout << friends[i].FIO << endl;
        cout << friends[i].birthday.year << " " << friends[i].birthday.month << " " << friends[i].birthday.day << endl;
        cout << friends[i].address << endl;
        cout << friends[i].numberphone << endl;
    }
}

void outputinfof1(kith friends[], int A, int M)
{
    int count = 0;
    for (size_t i = 0; i < A; i++)
    {
        if (M == friends[i].birthday.month)
        {
            cout << friends[i].serialnumber << endl;
            cout << friends[i].FIO << endl;
            cout << friends[i].birthday.year << " " << friends[i].birthday.month << " " << friends[i].birthday.day << endl;
            cout << friends[i].address << endl;
            cout << friends[i].numberphone << endl;
            count += 1;
        }
    }
    if (count == 0)
    {
        cout << "No births in this month.";
    }
}

void outputinfof2(kith friends[], int A)
{
    int k, count = 0;
    for (size_t i = 0; i < A; i++)
    {
        for (int j = 0; j <= (friends[i].numberphone).length(); j++)
        {
            if (isalnum(friends[i].numberphone[j]) != 0)
            {
                k = 0;
                break;
            }
            else
            {
                k = 1;
                break;
            }
        }

        if (k == 0)
        {
            cout << friends[i].serialnumber << endl;
            cout << friends[i].FIO << endl;
            cout << friends[i].birthday.year << " " << friends[i].birthday.month << " " << friends[i].birthday.day << endl;
            cout << friends[i].address << endl;
            cout << friends[i].numberphone << endl;
            count += 1;
        }
    }
    if (count == 0)
    {
        cout << "All contacts do not have a phone number.";
    }
}

void outputinfof4(kith friends[], int A, string M)
{
    int count = 0;
    for (size_t i = 0; i < A; i++)
    {
        if (friends[i].numberphone[0] == M[0] && friends[i].numberphone[1] == M[1] && friends[i].numberphone[2] == M[2])
        {
            cout << friends[i].serialnumber << endl;
            cout << friends[i].FIO << endl;
            cout << friends[i].birthday.year << " " << friends[i].birthday.month << " " << friends[i].birthday.day << endl;
            cout << friends[i].address << endl;
            cout << friends[i].numberphone << endl;
            count += 1;
        }
    }
    if (count == 0)
    {
        cout << "There are no people familiar with the specified operator code." << endl;
    }
}

void newifo(kith arr1[], kith arr2[], int A, int N)
{
    for (size_t i = 0; i < N; i++)
    {
        arr1[i].serialnumber = arr2[i].serialnumber;
        arr1[i].FIO = arr2[i].FIO;
        arr1[i].birthday.year = arr2[i].birthday.year;
        arr1[i].birthday.month = arr2[i].birthday.month;
        arr1[i].birthday.day = arr2[i].birthday.day;
        arr1[i].address = arr2[i].address;
        arr1[i].numberphone = arr2[i].numberphone;
    }

    arr1[N].serialnumber = N + 1;

    cout << "\nEnter your last name, first name and patronymic: ";
    cin.ignore(cin.rdbuf()->in_avail());
    getline(cin, arr1[N].FIO, '\n');

    do
    {
        cout << "\nEnter date of birth (year month day): ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> arr1[N].birthday.year >> arr1[N].birthday.month >> arr1[N].birthday.day;
    } while (!arr1[N].birthday.isCorrect());

    cout << "\nEnter address: ";
    cin.ignore(cin.rdbuf()->in_avail());
    getline(cin, arr1[N].address, '\n');


    int proverka = 0;
    do {
        proverka = 0;
        cout << "\nEnter phone number, no country code, no spaces, only numbers: ";
        cin.ignore(cin.rdbuf()->in_avail());
        getline(cin, arr1[N].numberphone, '\n');
        for (size_t j = 0; j < (arr1[N].numberphone).length(); j++)
        {
            if (isdigit(arr1[N].numberphone[j]) == 0)
            {
                proverka += 1;
                break;
            }
        }
    } while (proverka != 0);

    for (size_t i = N + 1; i < A; i++)
    {
        arr1[i].serialnumber = arr2[i - 1].serialnumber + 1;
        arr1[i].FIO = arr2[i - 1].FIO;
        arr1[i].birthday.year = arr2[i - 1].birthday.year;
        arr1[i].birthday.month = arr2[i - 1].birthday.month;
        arr1[i].birthday.day = arr2[i - 1].birthday.day;
        arr1[i].address = arr2[i - 1].address;
        arr1[i].numberphone = arr2[i - 1].numberphone;
    }

}

string way()
{
    system("cls");
    string way_input;
    cout << "Enter the path to the file (For example D:\\file.txt): " << endl;
    getline(cin, way_input, '\n');
    return way_input;
}

void deleteinfo(kith arr1[], kith arr2[], int A, int B)
{
    for (size_t i = 0; i < A - 1; i++)
    {
        arr1[i].serialnumber = i + 1;
        arr1[i].FIO = arr2[i].FIO;
        arr1[i].birthday.year = arr2[i].birthday.year;
        arr1[i].birthday.month = arr2[i].birthday.month;
        arr1[i].birthday.day = arr2[i].birthday.day;
        arr1[i].address = arr2[i].address;
        arr1[i].numberphone = arr2[i].numberphone;
    }
    for (size_t i = A - 1; i < B - 1; i++)
    {
        arr1[i].serialnumber = i + 1;
        arr1[i].FIO = arr2[i + 1].FIO;
        arr1[i].birthday.year = arr2[i + 1].birthday.year;
        arr1[i].birthday.month = arr2[i + 1].birthday.month;
        arr1[i].birthday.day = arr2[i + 1].birthday.day;
        arr1[i].address = arr2[i + 1].address;
        arr1[i].numberphone = arr2[i + 1].numberphone;
    }
}

void task()
{
    setlocale(LC_ALL, "Russian");
    int main = 0;
    do {
        do
        {
            for (;;)
            {
                cout << "\nSelect a function number: \n1 Creating an infobase file \n2 Adding new records to the database \n3 Searching records by key field \n4 Editing database records \n5 Deleting unnecessary records \n6 Issuing reports on request\n7 Issuing information about friends, births in the specified month\n8 Display information about acquaintances with a phone number\n9 Display information about acquaintances with the telephone code of the specified operator\n10 Shut down\n";
                if (cin >> main)
                {
                    break;
                }
                else
                {
                    cerr << "[Error] Enter a number (one of the function numbers)!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        } while (main < 1 || main>10);
        switch (main)
        {

        case 1:
        {
            getchar();
            string ourway = way();
            int amz;
            do {
                for (;;)
                {
                    cout << "\nEnter how many records should be (minimum 1): ";
                    if (cin >> amz)
                    {
                        break;
                    }
                    else
                    {
                        cerr << "[Error] Please enter a number!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
            } while (amz < 1);
            kith* createinfo = new kith[amz];
            ofstream createfile(ourway);
            createfile << amz << endl;
            inputinfo(createinfo, amz);
            for (size_t i = 0; i < amz; i++)
            {
                createfile << createinfo[i].serialnumber << endl;
                createfile << createinfo[i].FIO << endl;
                createfile << createinfo[i].birthday.year << " ";
                createfile << createinfo[i].birthday.month << " ";
                createfile << createinfo[i].birthday.day << endl;
                createfile << createinfo[i].address << endl;
                createfile << createinfo[i].numberphone << endl;
            }
            createfile.close();
            main = 0;
            break;
        }
        case 2:
        {
            string password = "2jkop28SewtR";
            string attempt;
            cout << "\nEnter the password to start the function:";
            cin.ignore(cin.rdbuf()->in_avail());
            getline(cin, attempt, '\n');
            if (attempt == password)
            {
                int amadd = 0;

                string fileway = way();
                ifstream fileadd(fileway);
                string k;
                if (!fileadd.is_open())
                {
                    cout << "File opening error." << endl;
                    main = 0;
                    break;
                }
                else
                {
                    fileadd >> amadd;
                    getline(fileadd, k);
                    kith* add = new kith[amadd];
                    for (size_t i = 0; i < amadd; i++)
                    {
                        fileadd >> add[i].serialnumber;
                        getline(fileadd, k);
                        getline(fileadd, add[i].FIO);
                        fileadd >> add[i].birthday.year >> add[i].birthday.month >> add[i].birthday.day;
                        getline(fileadd, k);
                        getline(fileadd, add[i].address);
                        getline(fileadd, add[i].numberphone);
                    }
                    fileadd.close();
                    outputinfo(add, amadd);
                    cout << "\nAbove is a list of all information.\n";
                    int nomer;
                    amadd += 1;
                    do {
                        for (;;)
                        {
                            cout << "Enter the sequence number after which you would like to add a new entry: ";
                            if (cin >> nomer)
                            {
                                break;
                            }
                            else
                            {
                                cerr << "[Error] Please enter a number!\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                    } while (nomer < 1 || nomer > amadd - 1);
                    kith* newadd = new kith[amadd];
                    newifo(newadd, add, amadd, nomer);
                    ofstream updatefile(fileway);
                    updatefile << amadd << endl;
                    for (size_t i = 0; i < amadd; i++)
                    {
                        updatefile << newadd[i].serialnumber << endl;
                        updatefile << newadd[i].FIO << endl;
                        updatefile << newadd[i].birthday.year << " ";
                        updatefile << newadd[i].birthday.month << " ";
                        updatefile << newadd[i].birthday.day << endl;
                        updatefile << newadd[i].address << endl;
                        updatefile << newadd[i].numberphone << endl;
                    }
                    updatefile.close();
                    main = 0;
                    break;
                }
            }
            else
            {
                cout << "\nPassword is wrong!" << endl;
                main = 0;
                break;
            }
        }
        case 3:
        {
            int poisk = 0;
            string empty;
            getchar();
            string tofileway = way();
            ifstream findfile(tofileway);
            if (!findfile.is_open())
            {
                cout << "File opening error." << endl;
                main = 0;
                break;
            }
            else
            {
                findfile >> poisk;
                getline(findfile, empty);
                kith* sort = new kith[poisk];
                for (size_t i = 0; i < poisk; i++)
                {
                    findfile >> sort[i].serialnumber;
                    getline(findfile, empty);
                    getline(findfile, sort[i].FIO);
                    findfile >> sort[i].birthday.year >> sort[i].birthday.month >> sort[i].birthday.day;
                    getline(findfile, empty);
                    getline(findfile, sort[i].address);
                    getline(findfile, sort[i].numberphone);
                }
                findfile.close();
                int nomer1;
                do {
                    for (;;)
                    {
                        cout << "\nEnter the serial number by which you want to find information about a friend: " << endl;
                        if (cin >> nomer1)
                        {
                            break;
                        }
                        else
                        {
                            cerr << "[Error] Please enter a number!\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                } while (nomer1 < 1 || nomer1 > poisk);
                cout << sort[nomer1 - 1].serialnumber << endl;
                cout << sort[nomer1 - 1].FIO << endl;
                cout << sort[nomer1 - 1].birthday.year << " " << sort[nomer1 - 1].birthday.month << " " << sort[nomer1 - 1].birthday.day << endl;
                cout << sort[nomer1 - 1].address << endl;
                cout << sort[nomer1 - 1].numberphone << endl;
                main = 0;
                break;
            }
        }
        case 4:
        {
            string password3 = "2jkop28SewtR";
            string attempt3;
            cout << "\nEnter the password to start the function:";
            cin.ignore(cin.rdbuf()->in_avail());
            getline(cin, attempt3, '\n');
            if (attempt3 == password3)
            {
                int redact = 0;
                string emp;

                string change = way();
                ifstream changefile(change);
                if (!changefile.is_open())
                {
                    cout << "File opening error." << endl;
                    main = 0;
                    break;
                }
                else
                {
                    changefile >> redact;
                    getline(changefile, emp);
                    kith* changer = new kith[redact];
                    for (size_t i = 0; i < redact; i++)
                    {
                        changefile >> changer[i].serialnumber;
                        getline(changefile, emp);
                        getline(changefile, changer[i].FIO);
                        changefile >> changer[i].birthday.year >> changer[i].birthday.month >> changer[i].birthday.day;
                        getline(changefile, emp);
                        getline(changefile, changer[i].address);
                        getline(changefile, changer[i].numberphone);
                    }
                    changefile.close();
                    outputinfo(changer, redact);
                    cout << "\nAbove is a list of all information.\n";
                    int vibor;
                    do {
                        for (;;)
                        {
                            cout << "Enter the sequence number for which you want to change the entry: ";
                            if (cin >> vibor)
                            {
                                break;
                            }
                            else
                            {
                                cerr << "[Error] Please enter a number!\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                    } while (vibor < 1 || vibor > redact);

                    cout << "\nSerial number: " << vibor << endl;
                    changer[vibor - 1].serialnumber = vibor;

                    cout << "\nEnter your last name, first name and patronymic: ";
                    cin.ignore(cin.rdbuf()->in_avail());
                    getline(cin, changer[vibor - 1].FIO, '\n');

                    do
                    {
                        for (;;)
                        {
                            cout << "\nEnter date of birth (year month day): ";
                            cin.ignore(std::cin.rdbuf()->in_avail());
                            if (cin >> changer[vibor - 1].birthday.year >> changer[vibor - 1].birthday.month >> changer[vibor - 1].birthday.day)
                            {
                                break;
                            }
                            else
                            {
                                cerr << "[Error] Enter valid values and numbers!\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                    } while (!changer[vibor - 1].birthday.isCorrect());

                    cout << "\nEnter address: ";
                    cin.ignore(cin.rdbuf()->in_avail());
                    getline(cin, changer[vibor - 1].address, '\n');
                    int proverka = 0;
                    do {
                        proverka = 0;
                        cout << "\nEnter phone number, no country code, no spaces, only numbers: ";
                        cin.ignore(cin.rdbuf()->in_avail());
                        getline(cin, changer[vibor - 1].numberphone, '\n');
                        for (size_t j = 0; j < (changer[vibor - 1].numberphone).length(); j++)
                        {
                            if (isdigit(changer[vibor - 1].numberphone[j]) == 0)
                            {
                                proverka += 1;
                                break;
                            }
                        }
                    } while (proverka != 0);
                    ofstream changefile(change);
                    changefile << redact << endl;
                    for (size_t i = 0; i < redact; i++)
                    {
                        changefile << changer[i].serialnumber << endl;
                        changefile << changer[i].FIO << endl;
                        changefile << changer[i].birthday.year << " ";
                        changefile << changer[i].birthday.month << " ";
                        changefile << changer[i].birthday.day << endl;
                        changefile << changer[i].address << endl;
                        changefile << changer[i].numberphone << endl;
                    }
                    changefile.close();
                    main = 0;
                    break;
                }
            }
            else
            {
                cout << "\nPassword is wrong!" << endl;
                main = 0;
                break;
            }
        }
        case 5:
        {
            string password2 = "2jkop28SewtR";
            string attempt2;

            cout << "\nEnter the password to start the function:";
            cin.ignore(cin.rdbuf()->in_avail());
            getline(cin, attempt2, '\n');
            if (attempt2 == password2)
            {

                string delway = way();
                int sizearr;
                string emptys;
                ifstream deleteneed(delway);
                if (!deleteneed.is_open())
                {
                    cout << "File opening error." << endl;
                    main = 0;
                    break;
                }
                else
                {
                    deleteneed >> sizearr;
                    getline(deleteneed, emptys);
                    kith* delarr = new kith[sizearr];
                    for (size_t i = 0; i < sizearr; i++)
                    {
                        deleteneed >> delarr[i].serialnumber;
                        getline(deleteneed, emptys);
                        getline(deleteneed, delarr[i].FIO);
                        deleteneed >> delarr[i].birthday.year >> delarr[i].birthday.month >> delarr[i].birthday.day;
                        getline(deleteneed, emptys);
                        getline(deleteneed, delarr[i].address);
                        getline(deleteneed, delarr[i].numberphone);
                    }
                    deleteneed.close();
                    outputinfo(delarr, sizearr);
                    cout << "\nAbove is a list of all information.\n";
                    int deletenumber;
                    do {
                        for (;;)
                        {
                            cout << "Enter the sequence number of the entry you want to delete: ";
                            if (cin >> deletenumber)
                            {
                                break;
                            }
                            else
                            {
                                cerr << "[Error] Please enter a number!\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                    } while (deletenumber < 1 || deletenumber > sizearr);
                    kith* newdelarr = new kith[sizearr - 1];
                    deleteinfo(newdelarr, delarr, deletenumber, sizearr);
                    ofstream newdelfile(delway);
                    newdelfile << sizearr - 1 << endl;
                    for (size_t i = 0; i < sizearr - 1; i++)
                    {
                        newdelfile << newdelarr[i].serialnumber << endl;
                        newdelfile << newdelarr[i].FIO << endl;
                        newdelfile << newdelarr[i].birthday.year << " ";
                        newdelfile << newdelarr[i].birthday.month << " ";
                        newdelfile << newdelarr[i].birthday.day << endl;
                        newdelfile << newdelarr[i].address << endl;
                        newdelfile << newdelarr[i].numberphone << endl;
                    }
                    newdelfile.close();
                    main = 0;
                    break;
                }
            }
            else
            {
                cout << "\nPassword is wrong!" << endl;
                main = 0;
                break;
            }
        }
        case 6:
        {
            int size6 = 0;
            getchar();
            string fileway6 = way();
            ifstream filep6(fileway6);
            string k;
            if (!filep6.is_open())
            {
                cout << "File opening error." << endl;
                main = 0;
                break;
            }
            else
            {
                filep6 >> size6;
                getline(filep6, k);
                kith* arrotch = new kith[size6];
                for (size_t i = 0; i < size6; i++)
                {
                    filep6 >> arrotch[i].serialnumber;
                    getline(filep6, k);
                    getline(filep6, arrotch[i].FIO);
                    filep6 >> arrotch[i].birthday.year >> arrotch[i].birthday.month >> arrotch[i].birthday.day;
                    getline(filep6, k);
                    getline(filep6, arrotch[i].address);
                    getline(filep6, arrotch[i].numberphone);
                }
                filep6.close();
                int otch;
                do {
                    for (;;)
                    {
                        cout << "\nChoose what you want to search for:\n1) Ordinal number \n2) Year of birth \n3) Month of birth \n";
                        if (cin >> otch)
                        {
                            break;
                        }
                        else

                        {
                            cerr << "[Error] Please enter a number!\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                } while (otch < 1 || otch > 3);
                switch (otch)
                {
                case 1:
                {
                    int nomer1;
                    do {
                        for (;;)
                        {
                            cout << "\nEnter the serial number by which you want to find information about a friend: " << endl;
                            if (cin >> nomer1)
                            {
                                break;
                            }
                            else
                            {
                                cerr << "[Error] Please enter a number!\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                    } while (nomer1 < 1 || nomer1 > size6);
                    cout << arrotch[nomer1 - 1].serialnumber << endl;
                    cout << arrotch[nomer1 - 1].FIO << endl;
                    cout << arrotch[nomer1 - 1].birthday.year << " " << arrotch[nomer1 - 1].birthday.month << " " << arrotch[nomer1 - 1].birthday.day << endl;
                    cout << arrotch[nomer1 - 1].address << endl;
                    cout << arrotch[nomer1 - 1].numberphone << endl;
                    cout << "\nAfter the command you chose above, the necessary data was displayed." << endl;
                    main = 0;
                    break;
                }
                case 2:
                {
                    int poranomer;
                    do {
                        for (;;)
                        {
                            cout << "\nEnter the year of birth by which you want to find information about a friend: " << endl;
                            if (cin >> poranomer)
                            {
                                break;
                            }
                            else
                            {
                                cerr << "[Error] Please enter a number!\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                    } while (poranomer < 1900 || poranomer > 2021);
                    int counter = 0;
                    for (size_t i = 0; i < size6; i++)
                    {
                        if (arrotch[i].birthday.year == poranomer)
                        {
                            cout << arrotch[i].serialnumber << endl;
                            cout << arrotch[i].FIO << endl;
                            cout << arrotch[i].birthday.year << " " << arrotch[i].birthday.month << " " << arrotch[i].birthday.day << endl;
                            cout << arrotch[i].address << endl;
                            cout << arrotch[i].numberphone << endl;
                            counter += 1;
                        }
                    }
                    if (counter == 0)
                    {
                        cout << "No acquaintances born in the specified year" << endl;
                    }
                    cout << "\nAfter the command you chose above, the necessary data was displayed." << endl;
                    main = 0;
                    break;

                }
                case 3:
                {
                    int mesac, count = 0;
                    do {
                        for (;;)
                        {
                            cout << "Enter the number of the month in which you want to see who was born: ";
                            if (cin >> mesac)
                            {
                                break;
                            }
                            else

                            {
                                cerr << "[Error] Please enter a number!\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                    } while (mesac < 1 || mesac>12);
                    outputinfof1(arrotch, size6, mesac);
                    main = 0;
                    cout << "\nAfter the command you chose above, the necessary data was displayed." << endl;
                    break;
                }
                default:
                    break;
                }
                break;
            }

        }
        case 7:
        {
            int size7 = 0;
            getchar();
            string fileway7 = way();
            ifstream filep7(fileway7);
            string k;
            if (!filep7.is_open())
            {
                cout << "File opening error." << endl;
                main = 0;
                break;
            }
            else
            {
                filep7 >> size7;
                getline(filep7, k);
                kith* arrsved = new kith[size7];
                for (size_t i = 0; i < size7; i++)
                {
                    filep7 >> arrsved[i].serialnumber;
                    getline(filep7, k);
                    getline(filep7, arrsved[i].FIO);
                    filep7 >> arrsved[i].birthday.year >> arrsved[i].birthday.month >> arrsved[i].birthday.day;
                    getline(filep7, k);
                    getline(filep7, arrsved[i].address);
                    getline(filep7, arrsved[i].numberphone);
                }
                filep7.close();

                int mes;
                do {
                    for (;;)
                    {
                        cout << "Enter the number of the month in which you want to see who was born: ";
                        if (cin >> mes)
                        {
                            break;
                        }
                        else

                        {
                            cerr << "[Error] Please enter a number!\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                } while (mes < 1 || mes>12);
                outputinfof1(arrsved, size7, mes);
                main = 0;
                break;
            }

        }
        case 8:
        {
            int size8;
            getchar();
            string fileway8 = way();
            ifstream filep8(fileway8);
            string empt;
            if (!filep8.is_open())
            {
                cout << "File opening error." << endl;
                main = 0;
                break;
            }
            else
            {
                filep8 >> size8;
                getline(filep8, empt);
                kith* arrnomer = new kith[size8];
                for (size_t i = 0; i < size8; i++)
                {
                    filep8 >> arrnomer[i].serialnumber;
                    getline(filep8, empt);
                    getline(filep8, arrnomer[i].FIO);
                    filep8 >> arrnomer[i].birthday.year >> arrnomer[i].birthday.month >> arrnomer[i].birthday.day;
                    getline(filep8, empt);
                    getline(filep8, arrnomer[i].address);
                    getline(filep8, arrnomer[i].numberphone);
                }
                filep8.close();
                outputinfof2(arrnomer, size8);
                main = 0;
                break;
            }
        }
        case 9:
        {
            int size9;
            getchar();
            string fileway9 = way();
            ifstream filep9(fileway9);
            string empt;
            if (!filep9.is_open())
            {
                cout << "File opening error." << endl;
                main = 0;
                break;
            }
            else
            {
                filep9 >> size9;
                getline(filep9, empt);
                kith* arrnoper = new kith[size9];
                for (size_t i = 0; i < size9; i++)
                {
                    filep9 >> arrnoper[i].serialnumber;
                    getline(filep9, empt);
                    getline(filep9, arrnoper[i].FIO);
                    filep9 >> arrnoper[i].birthday.year >> arrnoper[i].birthday.month >> arrnoper[i].birthday.day;
                    getline(filep9, empt);
                    getline(filep9, arrnoper[i].address);
                    getline(filep9, arrnoper[i].numberphone);
                }
                filep9.close();
                int k = 0;
                string oper;
                do {
                    cout << "Введите код оператора (3 цифры подряд): ";
                    cin.ignore(cin.rdbuf()->in_avail());
                    cin >> oper;
                    if (oper.length() > 3)
                    {
                        k = 0;
                    }
                    else
                    {
                        if (isdigit(oper[0]) != 0 && isdigit(oper[1]) != 0 && isdigit(oper[2]) != 0)
                        {
                            k = 1;
                        }
                    }
                } while (k != 1);
                outputinfof4(arrnoper, size9, oper);
                main = 0;
                break;
            }
        }
        default:
            break;
        }
    } while (main < 1 || main > 10);
}

int main()
{
    task();
}
