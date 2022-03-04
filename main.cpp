/**
 * Title:   main.cpp
 *
 * Purpose: Example of a linked list class
 * Class:   CSC 2430 Winter 2022
 * Author:  Max Benson
 * Date:    2022-03-02
 */

#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::stringstream;
using std::string;

#include "LinkedList.h"

int main() {
    LinkedList list;
    char command;

    do {
        string line;
        stringstream ss;
        int item;
        int after;
        size_t pos;

        cout << "Enter P(repend) number, A(Insert After) item after, D(Remove) item, O(utput), I(nsert At Pos) pos item, R(emove) pos, G(et) pos, F(ind) item start, S(ize), or E(xit)";
        getline(cin, line);
        ss.str(line);
        ss >> command;
        switch (command) {
            case 'P':
                ss >> item;
                if (ss.fail()) {
                    cerr << "You need to enter a number after 'P'" <<endl;
                }
                else {
                    list.Prepend( item );
                }
                break;
            case 'A':
                ss >> item;
                ss >> after;
                if (ss.fail()) {
                    cerr << "You need to enter two numbers after 'A'" <<endl;
                }
                else {
                    if (!list.InsertAfter(item, after)) {
                        cerr << after << " does not appear in the list" << endl;
                    }
                }
                break;
            case 'I':
                ss >> pos;
                ss >> item;
                if (ss.fail()) {
                    cerr << "You need to enter two numbers after 'I'" <<endl;
                }
                else if (list.Insert(pos, item)) {
                    cout << "Inserted " << item << " at position " << pos << endl;
                }
                else {
                    cout << "Position " << pos << " is invalid" << endl;
                }
                break;

            case 'D':
                ss >> item;
                if (ss.fail()) {
                    cerr << "You need to enter a number after 'D'" <<endl;
                }
                else {
                    if (!list.RemoveItem( item )) {
                        cerr << item << " does not appear in the list" << endl;
                    }
                }
                break;
            case 'R':
                ss >> pos;
                if (ss.fail()) {
                    cerr << "You need to enter a number after 'R'" <<endl;
                }
                else if (list.Remove( pos, item )) {
                    cout << "Removed " << item << " from position " << pos << endl;
                }
                else {
                    cout << "Position " << pos << " is invalid" << endl;
                }
                break;
            case 'G':
                ss >> pos;
                if (ss.fail()) {
                    cerr << "You need to enter a number after 'G'" <<endl;
                }
                else if (list.Get( pos, item )) {
                    cout << "Get " << item << " from position " << pos << endl;
                }
                else {
                    cout << "Position " << pos << " is invalid" << endl;
                }
                break;
            case 'F':
                ss >> item;
                ss >> pos;
                if (ss.fail()) {
                    cerr << "You need to enter a two numbers after 'F'" <<endl;
                }
                else {
                    int result = list.Find(item, pos);

                    if (-1 == result) {
                        cout <<  item << " not found" << endl;
                    }
                    else {
                        cout << item << " found at position " << result << endl;
                    }
                }
                break;
            case 'S':
                cout << "Size returns " << list.Size() << endl;
                break;
            case 'O':
                list.Print(cout);
                break;
            case 'E':
                break;
            default:
                cerr << "Unrecognized command '" << command << "'" << endl;
                break;
        }
    } while (command != 'E' && !cin.eof());
    return 0;
}

