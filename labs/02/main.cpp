//
//  main.cpp - constructs and starts your media library
//  Lab 02
//
//  Created by Joshua Brody on 9/15/13.
//  Copyright (c) 2013 Joshua Brody. All rights reserved.
//

#include <iostream>
#include "media.h"
#include "picture.h"
#include "video.h"
#include "mediaLibrary.h"
#include <fstream>

using namespace std;


int main() {
    cout << "Welcome to your iSwat Media Library" << endl;

    string fileName;
    cout << "Enter file containing library contents: ";
    cin >> fileName;

    ifstream inputFile(fileName.c_str());
    if(inputFile.is_open() == false){
      cerr << "Error: file does not exist.  Aborting." << endl;
      return 1;
    }
    inputFile.close();    
    
    MediaLibrary* library = new MediaLibrary(fileName);
    library->run();

    cout << "Good day!" << endl;

    return 0;
}

