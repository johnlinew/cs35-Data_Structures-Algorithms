/* ppmEditor.cpp - Program to display images that are changed based on what the user inputs
 * Name: Camden Wagner
 * CS35
 */

#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

bool readLine(ifstream& input, int pixels[], int columns);
void writeLine(ofstream& output, int pixels[], int columns);
//TODO: Add additional function declarations here
void flipHorizontal(int pixels[], int columns);
void greyScale(int pixels[], int columns);
void negateRed(int pixels[], int columns, int maxColorValue);
void negateBlue(int pixels[], int columns, int maxColorValue);
void negateGreen(int pixels[], int columns, int maxColorValue);
void flattenRed(int pixels[], int columns);
void flattenBlue(int pixels[], int columns);
void flattenGreen(int pixels[], int columns);
void extremeContrast(int pixels[], int columns);

int main(){
  string inputFileName, outputFileName; //holds name of input and output image files
  ifstream inFile;  // stream for reading from file
  ofstream outFile; // stream for writing to file

  //TODO: Greet user and ask for input and output image file, storing
  // as the variable inputFileName and outputFileName respectively
  cout << "Welcome User!" << endl;
  while (true) {
    cout << "Enter Input File: ";
    cin >> inputFileName;
    cout << "Enter Output File: ";
    cin >> outputFileName;
    inFile.open(inputFileName.c_str());
    outFile.open(outputFileName.c_str());
    if (inFile.is_open()) {
      break;
    }
    cerr << "Invalid File Name" << endl;
  }
  string garbage;
  int intGarbage;
  int maxColorValue;
  int columns;
  int pixels[3000];
  inFile >> garbage >> columns >> intGarbage >> maxColorValue;
  outFile << garbage << "\n" << columns << " " << intGarbage << "\n" << maxColorValue << "\n";

  string flipH, greyS, negRed, negBlue, negGreen, flatRed, flatBlue, flatGreen, exContrast;
  while (true) {
    cout << "Options: (y/n) 'n' if not 'y' or 'n'\n  Flip Image Horizontally? :: ";
    cin >> flipH;
    if (flipH == "y" || flipH == "n")
      break;
  }
  while (true) {
    cout << "  Grey Scale? :: ";
    cin >> greyS;
    if (greyS == "y" || greyS == "n")
      break;
  }
  while (true) {
    cout << "  Negate Red? :: ";
    cin >> negRed;
    if (negRed == "y" || negRed == "n")
      break;
  }
  while (true) {
    cout << "  Negate Blue? :: ";
    cin >> negBlue;
    if (negBlue == "y" || negBlue == "n")
      break;
  }
  while (true) {
    cout << "  Negate Green? :: ";
    cin >> negGreen;
    if (negGreen == "y" || negGreen == "n")
      break;
  }
  while (true) {
    cout << "  Flatten Red? :: ";
    cin >> flatRed;
    if (flatRed == "y" || flatRed == "n")
      break;
  }
  while (true) {
    cout << "  Flatten Blue? :: ";
    cin >> flatBlue;
    if (flatBlue == "y" || flatBlue == "n")
      break;
  }
  while (true) {
    cout << "  Flatten Green? :: ";
    cin >> flatGreen;
    if (flatGreen == "y" || flatGreen == "n")
      break;
  }
  while (true) {
    cout << "  Extreme Contrast? :: ";
    cin >> exContrast;
    if (exContrast == "y" || exContrast == "n")
      break;
  }

  for (int i = 0; i < columns; i++) {
    readLine(inFile, pixels, columns);
    if (flipH == "y") {
      flipHorizontal(pixels, columns);
    } if (greyS == "y") {
      greyScale(pixels, columns);
    } if (negRed == "y") {
      negateRed(pixels, columns, maxColorValue);
    } if (negBlue == "y") {
      negateBlue(pixels, columns, maxColorValue);
    } if (negGreen == "y") {
      negateGreen(pixels, columns, maxColorValue);
    } if (flatRed == "y") {
      flattenRed(pixels, columns);
    } if (flatBlue == "y") {
      flattenBlue(pixels, columns);
    } if (flatGreen == "y") {
      flattenGreen(pixels, columns);
    } if (exContrast == "y") {
      extremeContrast(pixels, columns);
    }

    writeLine(outFile, pixels, columns);
  }

  cout << "Complete. File created." << endl;

  system(("viewnior " + outputFileName).c_str());

  return 0;
}

/* readLine - loads one line of RGB values from a PPM image into the pixels
 *              array
 * Parameters:
 *      input - the input file stream to read from
 *      pixels - an integer array storing RGB values for each pixel in one
 *              line of the image
 *      columns - the total number of pixels to store in the buffer
 * Return: true if the input was successful
 */
 
bool readLine(ifstream& input, int pixels[], int columns){
  
  for (int i = 0; i < columns*3; i++) {
    input >> pixels[i];
  }

  return true;
}

/* writeLine - outputs one line of pixel RGB values to a PPM image file
 * Parameters:
 *      output - the output file stream for writing image information to
 *      pixels - an integer array of RGB values for each pixel in one
 *              line of the image
 *      columns - the total number of pixels stored in the buffer
 */
void writeLine(ofstream& output, int pixels[], int columns){
  for (int i = 0; i < columns*3; i++) {
    output << pixels[i] << "   ";
  }
  output << "\n";
}

//NEW FUNCTIONS

void flipHorizontal(int pixels[], int columns) {
  int copy[3000];
  for (int i = 0; i < columns*3; i++) {
    copy[i] = pixels[i];
  }
  for (int j = 0; j < columns*3; j++) {
    pixels[j] = copy[(columns*3)-1-j]; 
  }
}

void greyScale(int pixels[], int columns) {
  for (int i = 0; i < columns; i++) {
    int average = (pixels[i*3]+pixels[(i*3)+1]+pixels[(i*3)+2])/3;
    pixels[i*3] = average;
    pixels[(i*3)+1] = average;
    pixels[(i*3)+2] = average;
  }
}

void negateRed(int pixels[], int columns, int maxColorValue) {
  for (int i = 0; i < columns; i++) {
    pixels[i*3] = maxColorValue - pixels[i*3];
  }
}

void negateBlue(int pixels[], int columns, int maxColorValue) {
  for (int i = 0; i < columns; i++) {
    pixels[(i*3)+1] = maxColorValue - pixels[(i*3)+1];
  }
}

void negateGreen(int pixels[], int columns, int maxColorValue) {
  for (int i = 0; i < columns; i++) {
    pixels[(i*3)+2] = maxColorValue - pixels[(i*3)+2];
  }
}

void flattenRed(int pixels[], int columns) {
  for (int i = 0; i < columns; i++) {
    pixels[i*3] = 0;
  }
}

void flattenBlue(int pixels[], int columns) {
  for (int i = 0; i < columns; i++) {
    pixels[(i*3)+1] = 0;
  }
}

void flattenGreen(int pixels[], int columns) {
  for (int i = 0; i < columns; i++) {
    pixels[(i*3)+2] = 0;
  }
}

void extremeContrast(int pixels[], int columns) {
  for (int i = 0; i < columns*3; i++) {
    if (pixels[i] < 128) {
      pixels[i] = 0;
    } else {
      pixels[i] = 255;
    }
  }
}
