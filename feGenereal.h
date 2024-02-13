#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std; 

namespace feGeneral
{

    void PrintFirstLetterForEachWord(string Name)
    {
        bool IsFirstLetter = true;

        for (int i = 0; i < Name.length(); i++)
        {
            if (Name[i] != ' ' && IsFirstLetter)
            {
                cout << Name[i] << endl;
            }
            IsFirstLetter = (Name[i] == ' ' ? true : false);
        }
    }

    string ReadString()
    {
        string String = " ";
        cout << "Enter Sreing ";
        getline(cin, String);

        return String;
    }

    string UpperEachFirstLetterForEachWord(string Name)
    {
        bool IsFirstLetter = true;

        for (int i = 0; i < Name.length(); i++)
        {
            if (Name[i] != ' ' && IsFirstLetter)
            {
                Name[i] = toupper(Name[i]);

            }
            IsFirstLetter = (Name[i] == ' ' ? true : false);
        }
        return Name;

    }

    string UpperAllLetter(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);

        }
        return S1;
    }

    string LowerAllLetter(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);

        }
        return S1;
    }

    char InvertChar(char Ch1)
    {
        return(isupper(Ch1) ? tolower(Ch1) : toupper(Ch1));
    }

    string InvertStringChar(string Ch1)
    {

        for (int i = 0; i < Ch1.length(); i++)
        {
            if (Ch1[i] >= 'A' && Ch1[i] <= 'Z')
            {
                Ch1[i] = tolower(Ch1[i]);
            }
            else
            {
                Ch1[i] = toupper(Ch1[i]);
            }
        }
        return Ch1;
    }

    char  InvertLetterCase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }

    string  InvertAllStringLettersCase(string S1) {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertLetterCase(S1[i]);
        }
        return S1;

    }

    enum enWhatToCount { SmallLetter = 1, CapitalLetter = 2, All = 3 };

    short CountLetterCase(string& S1, enWhatToCount WhatToCount)
    {
        short Count = 0;

        for (size_t i = 0; i < S1.length(); i++)
        {
            if (WhatToCount == enWhatToCount::CapitalLetter && isupper(S1[i]))
                Count++;
            else if (WhatToCount == enWhatToCount::SmallLetter && islower(S1[i]))
                Count++;
        }
        return Count;
    }

    short CountLetterCase(string S1, char Letter, bool MatchCase = true)
    {
        short Count = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (MatchCase)
            {
                if (S1[i] == Letter)
                {
                    Count++;
                }
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                {
                    Count++;
                }
            }

        }
        return Count;
    }

    char  ReadChar()
    {
        char Ch1;
        cout << "\nPlease Enter a Character?\n";
        cin >> Ch1;
        return Ch1;
    }

    /*  short CountLetters(string S1, char Char)
      {
          short Count = 0;
          for (short i = 0; i < S1.length(); i++)
          {
              if (Char == S1[i])
              {

                  Count++;
              }
          }
          return Count;
      }*/

    bool IsVoulLetter(char Letter)
    {

        Letter = tolower(Letter);
        return (Letter == 'a' || Letter == 'o' || Letter == 'i' || Letter == 'e' || Letter == 'u');


    }

    short CountVoul(string S1)
    {
        short Counter = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (feGeneral::IsVoulLetter(S1[i]))
            {
                Counter++;
            }

        }
        return Counter;
    }

    void PrintAllVouels(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            if (feGeneral::IsVoulLetter(S1[i]))
                cout << S1[i] << "     ";
        }
    }

    void PrintEachWorodInString(string S1)
    {
        string dilma = " ";
        short pos = 0;
        string sWord = "";


        while ((pos = S1.find(dilma)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                cout << sWord << endl;

                S1.erase(0, pos + dilma.length());
            }

        }
        if (S1 != "")
        {
            cout << S1 << endl;
        }
    }

    short CountWords(string S1)
    {
        string delima = " ";
        short pos = 0;
        short Counter = 0;
        string sWord = "";

        while ((pos = S1.find(delima)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                Counter++;
            }
            S1.erase(0, pos + delima.length());
        }
        if (S1 != "")
        {
            Counter++;
        }
        return Counter;
    }

    string JoinString(vector <string> vString, string Delim)
    {
        string S1 = "";

        for (string& s : vString)
        {
            S1 = S1 + s + Delim;
        }
        return S1.substr(0, S1.length() - Delim.length());
    }

    string JoinString(string arr[], short length, string Delim)
    {
        string S1 = "";

        for (short i = 0; i < length; i++)
        {
            S1 = S1 + arr[i] + Delim;
        }
        return S1.substr(0, S1.length() - Delim.length());
    }

    vector<string> SplitString(string S1, string Delim)
    {
        vector<string> vString;
        short pos = 0;
        string sWord; // define a string variable  
                      // use find() function to get the position of the delimiters  
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")

            {
                vString.push_back(sWord);
            }
            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }
        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.    
        }
        return vString;
    }

    string ReseveWordInString(string S1)
    {
        vector <string> vString;
        string S2 = "";

        vString = feGeneral::SplitString(S1, " ");

        vector <string> ::iterator iter = vString.end();

        while (iter != vString.begin())
        {
            --iter;
            S2 += *iter + " ";
        }

        S2 = S2.substr(0, S2.length() - 1);
        return S2;
    }

    string ReplaceWordsInStringUsingBuiltInFunctions(string S1, string StringToReplace, string ReplaceTo)
    {
        short pos = S1.find(StringToReplace);
        while (pos != std::string::npos)
        {
            S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
            pos = S1.find(StringToReplace);
        }
        return S1;

    }

    string ReplaceWordsInStringUsingSplit(string S1, string StringToReplace, string ReplaceTo, bool Matchcase = true)
    {
        vector <string > vString = feGeneral::SplitString(S1, " ");

        for (string& s : vString)
        {
            if (Matchcase)
            {
                if (s == StringToReplace)
                {


                    s = ReplaceTo;
                }
            }

            else
            {
                if (feGeneral::LowerAllLetter(s) == feGeneral::LowerAllLetter(StringToReplace))
                {
                    s = ReplaceTo;
                }
            }


        }
        return (feGeneral::JoinString(vString, " "));


    }

    string RemovePunctuiationFromString(string S1)
    {
        string S2 = "";
        for (int i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }

        return S2;

    }

    struct sClint
    {
        string AcoountNumber;
        string PinCode;
        string Name;
        string PhoneNumebr;
        double Balance;
    };

    //sClint ReadNewClint(sClint Clint)

    //{
    //    
    //    cout << "ADDING NEWCLINT " << endl;

    //    cout << "Enter Account Number : ";
    //    getline(cin >> ws, Clint.AcoountNumber);
    //    cout << "Enter PinCdoe : ";
    //    getline(cin, Clint.PinCode);
    //    cout << "Enter Clint Name : ";
    //    getline(cin, Clint.Name);
    //    cout << "Enter Phine Number  : ";
    //    getline(cin, Clint.PhoneNumebr);
    //    cout << "Enter Balance Acount  : ";
    //    cin >> Clint.Balance;

    //    return Clint;

    //}

    string ConvertRecodeToLine(sClint Clint, string Seperator = "#//#")
    {
        string Line = "";

        Line += Clint.AcoountNumber + Seperator;
        Line += Clint.PinCode + Seperator;
        Line += Clint.Name + Seperator;
        Line += Clint.PhoneNumebr + Seperator;
        Line += to_string(Clint.Balance);

        return Line;

    }

    sClint ConvertLineToRecord(string Line, string Seperator = "#//#")
    {
        sClint sClintData;

        vector <string> vClintRecord = feGeneral::SplitString(Line, Seperator);


        sClintData.AcoountNumber = vClintRecord[0];
        sClintData.PinCode = vClintRecord[1];
        sClintData.Name = vClintRecord[2];
        sClintData.PhoneNumebr = vClintRecord[3];
        sClintData.Balance = stod(vClintRecord[4]);

        return sClintData;

    }

    void PrintClientCard(sClint stClintRecrod)
    {

        cout << "Account Number : " << stClintRecrod.AcoountNumber << endl;
        cout << "Account Number : " << stClintRecrod.PinCode << endl;
        cout << "Account Number : " << stClintRecrod.Name << endl;
        cout << "Account Number : " << stClintRecrod.PhoneNumebr << endl;
        cout << "Account Number : " << stClintRecrod.Balance << endl;



    }

    void LoadDataFromFileToVector(string FileName, vector <string>& vFielContant)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::in);
        string Line = "";

        if (MyFile.is_open())
        {
            while (getline(MyFile, Line))
            {
                vFielContant.push_back(Line);
            }
            MyFile.close();
        }

    }

    void SaveDataFromVectorToFile(string FileName, vector <string>& vFielContant)
    {
        fstream Myfile;
        Myfile.open(FileName, ios::out);

        if (Myfile.is_open())
        {


            for (string& Line : vFielContant)
            {
                if (Line != "")
                {
                    Myfile << Line << endl;
                }
            }

            Myfile.close();
        }

    }


    string const FileName = "ClintsFile.txt";

    void AddLineToFile(string FileName, string Line)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::in | ios::out);
        if (MyFile.is_open())
        {
            MyFile << Line << endl;
        }
    }

    //void AddNewClient()
    //{
    //    feGeneral::sClint Clint;
    //    Clint = feGeneral::ReadNewClint();
    //    AddLineToFile(FileName, feGeneral::ConvertRecodeToLine(Clint));


    //}

   /* void AddClinets()
    {
        char ToAdd = 'Y';

        do
        {
            system("cls");
            AddNewClient();
            cout << "Client added sucssesfully. Do you want to add more . Y/N ? ";
            cin >> ToAdd;

        } while (tolower(ToAdd) == 'Y');


    }*/

    vector<sClint> LoadDataFromFile(string FileName)
    {
        vector<sClint> vClints;
        fstream MyFile;
        MyFile.open(FileName, ios::in);

        if (MyFile.is_open())
        {
            sClint Clint;
            string Line = "";
            while (getline(MyFile, Line))
            {
                Clint = ConvertLineToRecord(Line);
                vClints.push_back(Clint);
            }

            MyFile.close(); // Close the file after reading
        }

        return vClints; // Return the vector of sClint objects
    }

    void PrintClientRecord(sClint Client)
    {
        cout << "|" << left << setw(15) << Client.AcoountNumber;
        cout << "|" << left << setw(10) << Client.PinCode;
        cout << "|" << left << setw(40) << Client.Name;
        cout << "|" << left << setw(23) << Client.PhoneNumebr;
        cout << "|" << left << setw(18) << Client.Balance;

    }

    void PrintAllClientsData(vector <sClint> vClient)
    {
        cout << "\t\t\t\t\t  Clint list(" << vClient.size() << ") clint (s)" << endl;
        cout << "------------------------------------------------------------------------------------------";
        cout << "---------------------------" << endl;
        cout << "|" << left << setw(15) << "Account Number ";
        cout << "|" << left << setw(10) << "Pin Code";
        cout << "|" << left << setw(40) << "Name ";
        cout << "|" << left << setw(12) << "Phone Number ";
        cout << "|" << left << setw(12) << "Balance Account " << endl;
        cout << "------------------------------------------------------------------------------------------";
        cout << "----------------------" << endl;

        for (sClint& Clint : vClient)
        {
            PrintClientRecord(Clint);
            cout << endl;
        }
        cout << "------------------------------------------------------------------------------------------";
        cout << "---------------------------" << endl;

    }


    bool FindClientByAccountNumber(string AccountNumber, sClint& Client)
    {

        vector <sClint> vClient = LoadDataFromFile(FileName);


        for (sClint& C : vClient)
        {
            if (C.AcoountNumber == AccountNumber)
            {
                Client = C;
                return true;
            }
        }
        return false;

    }
    string ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "Please Enter Account Number : ";
        cin >> AccountNumber;
        return AccountNumber;
    }
    void FindClient()
    {
        sClint Client;
        string AccountNumber = ReadAccountNumber();


        if (FindClientByAccountNumber(AccountNumber, Client))
        {
            PrintClientCard(Client);
        }
        else
        {
            cout << " The Account number (" << AccountNumber << ") is not found ";
        }
    }


    //sClint ConvertLineToRecord(string Line, string Seperator = "#//#")
//{
//    sClint sClintData;
//
//    vector <string> vClintRecord = feGeneral::SplitString(Line, Seperator);
//
//
//    sClintData.AcoountNumber = vClintRecord[0];
//    sClintData.PinCode = vClintRecord[1];
//    sClintData.Name = vClintRecord[2];
//    sClintData.PhoneNumebr = vClintRecord[3];
//    sClintData.Balance = stod(vClintRecord[4]);
//
//    return sClintData;
//
//}
//
//
//vector<sClint> LoadDataFromFile(string FileName)
//{
//    vector<sClint> vClints;
//    fstream MyFile;
//    MyFile.open(FileName, ios::in);
//
//    if (MyFile.is_open())
//    {
//        sClint Clint;
//        string Line = "";
//        while (getline(MyFile, Line))
//        {
//             Clint = ConvertLineToRecord(Line);
//            vClints.push_back(Clint);
//        }
//
//        MyFile.close(); // Close the file after reading
//    }
//
//    return vClints; // Return the vector of sClint objects
//}
//void PrintClientRecord(sClint Client)
//{
//    cout << "|" << left << setw(15) << Client.AcoountNumber;
//    cout << "|" << left << setw(10) << Client.PinCode;
//    cout << "|" << left << setw(40) << Client.Name;
//    cout << "|" << left << setw(23) << Client.PhoneNumebr;
//    cout << "|" << left << setw(18) << Client.Balance;
//    
//}
//void PrintAllClientsData(vector <sClint> vClient)
//{
//    cout << "\t\t\t\t\t  Clint list(" << vClient.size() << ") clint (s)" << endl;
//    cout << "------------------------------------------------------------------------------------------";
//    cout << "---------------------------" << endl;
//    cout << "|" << left << setw(15) << "Account Number ";
//    cout << "|" << left << setw(10) << "Pin Code";
//    cout << "|" << left << setw(40) << "Name ";
//    cout << "|" << left << setw(12) << "Phone Number ";
//    cout << "|" << left << setw(12) << "Balance Account " << endl;
//    cout << "------------------------------------------------------------------------------------------";
//    cout << "----------------------" << endl;
//
//    for (sClint &Clint : vClient)
//    {
//        PrintClientRecord(Clint);
//        cout << endl;
//    }
//    cout << "------------------------------------------------------------------------------------------";
//    cout << "---------------------------" << endl;
//
//}
//int main()
//{
//    vector <sClint> vClint = LoadDataFromFile(FileName);
//    PrintAllClientsData(vClint);
//
//    system("pause>0");
//    return 0; 
//}

}
