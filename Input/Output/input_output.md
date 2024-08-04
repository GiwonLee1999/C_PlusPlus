### Streams 

- I/O stream objects cin, cout,cerr
- Defined in the C++ library called <iostream>

```
#incldue<iostream>
using namespace std;

cin;
cout;
cerr;
endl;

cout << fixed << showpoint << setprecision(2);
// Take input from the user;
cin >> num;
```

### Text file is the simplest file read/write mode
- Very similar to cin/cout
- Use << operator to write
- Use >> operator to read
- Can also use C-style functions
- get(): read a single character from a file in input text mode
```
char ch;
ifstream input(“myFile.txt”);
ch = input.get();

- put(): write a single character from a file in output text mode

char ch {‘A’};
ofstream output(“myFile.txt”);
output.put(ch);

- getline(): read a string from a file in input text mode from the current position to a

delimiter character
string str;
ifstream input(“myFile.txt”);
getline(input, str, ‘\t’);


// An fstream object can also be used, but in this case, file modes need to be specified:
fstream filestream;
filestream.open("scores.txt“, ios::out);
...//output operations
filestream.close();
...//do other things
filestream.open("scores.txt“, ios::in);
...//input operations
filestream.close();

ios::in //Opens a file for input.
ios::out //Opens a file for output.
ios::app //Appends all output to the end of the file.
ios::ate //Opens a file for output. If the file already exists, move to the end of the file. Data can be written anywhere in the file.
ios::trunc //Discards the file’s contents if the file already exists. (This is thedefault action for ios:out).
ios::binary //Opens a file for binary input and output.
```

E.g
```
ifstream input("scores.txt");
string firstName, lastName; char mi; int score;
input >> firstName >> mi >> lastName >> score;
cout << firstName << " " << mi << " " << lastName << " " << score << endl;
input >> firstName >> mi >> lastName >> score;
cout << firstName << " " << mi << " " << lastName << " " << score << endl;
input.close();

// OR

string firstName, lastName; char mi; int score;
ifstream input("scores.txt");
input >> firstName >> mi >> lastName >> score;
while (!input.eof()) {
    cout << firstName << " " << mi << " " << lastName << " " << score << endl;
    input >> firstName >> mi >> lastName >> score;
}
input.close();
```

### Stream states functions
- eof() returns true if the eofbit flag is set.
- fail() returns true if the failbit or hardfail flag is set
- bad() returns true if the badbit flag is set
- good() returns true is the goodbit flag is set
- clear() clear all stream state flags

- ios::eofbit set when the end of an input stream is reached
- ios::failbit set when an operation on the stream has failed
- ios::hardfail set when an unrecovered error has occurred
- ios::badbit set when an invalid operation has been attempted
- ios::goodbit set if none of the preceding bits is set