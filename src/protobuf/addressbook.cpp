#pragma once

#include "addressbook.h"
#include "proto/addressbook.pb.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace xm
{

    ProtoBufDemo::ProtoBufDemo(/* args */)
    {
    }

    ProtoBufDemo::~ProtoBufDemo()
    {
    }

    // This function fills in a Person message based on user input.
    void ProtoBufDemo::PromptForAddress(tutorial::Person *person)
    {
        cout << "Enter person ID number: ";
        int id;
        cin >> id;
        person->set_id(id);
        cin.ignore(256, '\n');

        cout << "Enter name: ";
        getline(cin, *person->mutable_name());

        cout << "Enter email address (blank for none): ";
        string email;
        getline(cin, email);
        if (!email.empty())
        {
            person->set_email(email);
        }

        while (true)
        {
            cout << "Enter a phone number (or leave blank to finish): ";
            string number;
            getline(cin, number);
            if (number.empty())
            {
                break;
            }

            tutorial::Person::PhoneNumber *phone_number = person->add_phones();
            phone_number->set_number(number);

            cout << "Is this a mobile, home, or work phone? ";
            string type;
            getline(cin, type);
            if (type == "mobile")
            {
                phone_number->set_type(tutorial::Person::MOBILE);
            }
            else if (type == "home")
            {
                phone_number->set_type(tutorial::Person::HOME);
            }
            else if (type == "work")
            {
                phone_number->set_type(tutorial::Person::WORK);
            }
            else
            {
                cout << "Unknown phone type.  Using default." << endl;
            }
        }
    }

    // Main function:  Reads the entire address book from a file,
    //   adds one person based on user input, then writes it back out to the same
    //   file.
    void ProtoBufDemo::start()
    {
        // Verify that the version of the library that we linked against is
        // compatible with the version of the headers we compiled against.
        GOOGLE_PROTOBUF_VERIFY_VERSION;

        string book1 = "book1-c++";

        tutorial::AddressBook address_book;
        {
            // Read the existing address book.
            fstream input(book1.c_str(), ios::in | ios::binary);
            if (!input)
            {
                cout << book1 << ": File not found.  Creating a new file." << endl;
            }
            else if (!address_book.ParseFromIstream(&input))
            {
                cerr << "Failed to parse address book." << endl;
            }
        }

        // Add an address.
        PromptForAddress(address_book.add_people());
        {
            // Write the new address book back to disk.
            fstream output(book1, ios::out | ios::trunc | ios::binary);
            if (!address_book.SerializeToOstream(&output))
            {
                cerr << "Failed to write address book." << endl;
            }
        }

        // Optional:  Delete all global objects allocated by libprotobuf.
        google::protobuf::ShutdownProtobufLibrary();
    }
} // namespace xm