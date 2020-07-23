/**
*  @file main.cpp
*
*  This project will read up to 1000 long integer values from a file into an array, find
*  the max, min and the ith value.
*  @author Pranav Rao (pranavr)
*  @date   December 9, 2017
*
*  Virginia Tech Honor Code Pledge
*  On my honor:
*
*  -  I  have not discussed the C++ language code in my program with
*  anyone other than my instructor or the teaching assistants
*  assigned to this course.
*  -  I  have not used C++ language code obtained from another student,
*  or any other unauthorized source, either modified or unmodified.
*  -  If   any C++ language code or documentation used in my program
*  was obtained from another source, such as a text book of coarse
*  notes, that has been clearly noted with a  proper citation in
*  the comments of my program.
*  -  I  have not designed this program in such a way as to defeat or
*  interfere with the normal operation of the Web-Cat Server.
*
*  Pranav Rao
*/

#include <iostream>
#include <fstream>

using namespace std;

// prototypes & constants
int readArray(ifstream& ifile, long arr[]);
void sortArray(long arr[], int numberInTheArray);

const int LG = 1000;

int main()
{
    //Declare variables
    string infile2; //user's inputed file name
    ifstream myInfile;
    long inputArray[LG];
    long ith; //user's inputed value to print ith value
    int number = 0; //value that gets returned by inputArray
    int out = 0;

    //Prompts user for file
    cout << "Input File Name: ";
    cin >> infile2;

    //Open the input file
    myInfile.open(infile2.c_str());

    //Check to see if infile is okay
    if (! myInfile)
    {
        cout << "\nThat file does not exist!\n";
        return 1;
    }

    //Ask user which number they want to return
    cout << "Which number do you want to return? ";
    cin >> ith;

    //call readArray
    out = readArray(myInfile,inputArray);
    // Print first, last, etc.
    // if there are less than 1000 numbers in the file
    if ( out == LG  )
    {
        cout << "\nBefore Sort:" << endl;
        cout << " First is {" << inputArray[0] << "}."<< endl;
        cout << " Last is {" << inputArray[out - 1] << "}."<< endl;

        // print Value is OR error message
        if ( ith > LG )
        {
            cout << " " << ith << " is bigger than 1000!" << endl;
        }
        else
        {
            cout << " Value "<< ith << " is {"<< inputArray[ith - 1] << "}." << endl;
        }

        //call sortArray
        sortArray(inputArray,out);



        //Outputs after sortArray
        // Print min/first, max/last, and amount of numbers in the array AFTER the sort
        cout << "\nAfter Sort:" << endl;
        cout << " Min is {" << inputArray[0] << "}."<< endl;
        cout << " Max is {" << inputArray[out - 1] << "}."<< endl;


        // again print the ith Value or the error message
        if ( ith > LG)
        {
            cout<< " " << ith << " is bigger than 1000!" << endl;
        }
        else
        {
            cout << " Value "<< ith << " is {"<< inputArray[ith - 1] << "}." << endl;
        }
    }

    // if the amount of numbers in the file is larger than LG (the const array size)
    // data printed shows the min, max and value, but lets the user know the value is
    // larger than the constant value
    else
    {
        // Prints first & last
        cout << "\nBefore Sort:" << endl;
        cout << " First is {" << inputArray[0] << "}."<< endl;
        cout << " Last is {" << inputArray[out - 1] << "}."<< endl;

        cout << " WARNING: Only " << out <<" numbers were read into the array!" << endl;

        // prints that ith Value or error message
        if ( ith > out  )
        {
            cout <<" There aren't that many numbers in the array!" << endl;
        }
        else
        {
            cout << " Value "<< ith << " is {"<< inputArray[ith -1] << "}." << endl;
        }

        //call sortArray
        sortArray(inputArray,out);

        //Outputs after sortArray
        // Print min/first, max/last, amount of numbers in the array AFTER sorting
        cout << "\nAfter Sort:" << endl;
        cout << " Min is {" << inputArray[0] << "}."<< endl;
        cout << " Max is {" << inputArray[out - 1] << "}."<< endl;


        cout << " WARNING: Only " << out <<" numbers were read into the array!" << endl;

        // Prints ith Value or error message
        if ( ith > out  )
        {
            cout <<" There aren't that many numbers in the array!" << endl;
        }
        else //(ith < LG)
        {
            cout << " Value "<< ith << " is {"<< inputArray[ith-1] << "}." << endl;
        }
    }

    //Close the input file
    myInfile.close();

    return 0;
}

/** Reads the array from infile
 *
 * @param function takes the user choice as an ifstream (ifile)
 *@param function takes the user choice as a long (arr[])
 *
 */
int readArray(ifstream& ifile, long arr[])
{
    int count = 0;
    for(int i = 0; i < 1000; i ++)
    {
        while(ifile >> arr[i])
        {
            count ++;
            break;
        }

    }
    return count;
}

/** Bubble sort the array
 *
 * @param function takes the user choice as a long (arr[])
 * @param function takes the user choice as an int(numberInTheArray)
 *
 */
void sortArray(long arr[], int numberInTheArray)
{
    //initialize variables
    int temp = 0;


    //for loop sorts array from 0 to numberInTheArray-1
    for (int c = 0; c < (numberInTheArray - 1); c++)
    {
        for (int d = 0; d < (numberInTheArray - c - 1); d++)
        {
            if(arr[d] > arr[d+1])
            {
                temp = arr[d];
                arr[d] = arr[d+1];
                arr[d+1] = temp;

            }

        }
    }

}
