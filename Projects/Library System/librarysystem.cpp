#include <bits/stdc++.h>
#include <fstream>
using namespace std;

// Not writing too many features for this.
// The main goal of this is to ensure understanding of WHY to use a data structure.
// Using the same Library system so you can compare codes to some extent.
// Will use maps, arrays, linked lists and will keep using them in all ways possible but not
// using it just because I can, rather will only use it if it is BENEFICIAL in terms of time and space optimization.
// Will try to mark time and space complexity wherever possible. Also using this to revise c++ as I haven't touched it for years


template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

template<typename T> void printElement(T t, const int& width) {
    cout << left << setw(width) << setfill(' ') << t;
}


// Instead of Node, using book as Node class
class book {
	public:
		book *next;
		string title;
		string author;
		string genre;
		unsigned int copies;
		unsigned long int id;

	// Always initialize variables if possible, gets rid of garbage values
		book() {
			next = NULL;
			id = 0;
			title = "";
			author = "";
			genre = "";
			copies = 0;
		}
};

class Library {
	/*
		*	Will use Map as an example for use-case of Maps
				We will have a Map of String -> book
				String will be 'Genre'
				Why maps?
					We KNOW that Genre is unique. And it is unique in a 'one to many' way.

					A book can be many genres, so we do not care for a 'many to many' relationships.
					But one genre represents only itself.

					Let's take a book example.
					Title: 1984
					Author: George Orwell
					Genre: Dystopia, Fiction, Political, Social Science

					Dystopia here represents itself, Fiction represents itself.
					No genre can overlap each other. A 'political genre' cannot describe 'fiction'

					But a book can be a blend of various genres.
					If people search for Dystopia, they should see this book
					Same for Fiction and Political too.

					This book should come under a lot of genres
					But a genre cannot come other ANY other genre

					Hence, maps
					String genre will be KEY. A key needs to be unique
					The value for that key DOES NOT need to be unique.

					In simple terms, Key REPRESENTS the Value.
		*
	*/
	private:
		map<string, book> library;
		vector<string> splitStrings(string, char);
		string trimWhitespaces(string);
		book& copyBookContents(book*);
		void processAndMapBook(book*);

	public:
		void init();
		void addBooks();
		void buildLibraryFromFile();
		void displayAllBooksByGenre();
		void displayAllBooksUnique();
		Library();
};

book& Library :: copyBookContents(book *tempCopy) {
	book *temp = new book();

	temp->id = tempCopy->id;
	temp->author = tempCopy->author;
	temp->title = tempCopy->title;
	temp->copies = tempCopy->copies;
	temp->genre = tempCopy->genre;

	return *temp;
}

Library :: Library() {
	
}

void Library :: init() {
	int choice = INT_MAX;
	do {
		cout << endl << "Select an Operation (Corresponding int): " << endl;
		cout << "1. Add a book manually" << endl;
		cout << "2. Build library by reading a file" << endl;
		cout << "3. Display list of all books" << endl;
		cout << "4. Display list of all books grouped by Genre" << endl;
		cout << "[Input]> ";
		cin  >> choice;

		switch (choice) {
			case 1:
				addBooks();
				break;
			case 2:
				buildLibraryFromFile();
				break;
			case 3:
				displayAllBooksUnique();
				break;
			case 4:
				displayAllBooksByGenre();
				break;
			
			default:
				cout << "Please enter a valid choice";
				break;
		}
	} while(choice != 99);
}

string Library :: trimWhitespaces(string str) {
	const char* typeOfWhitespaces = " \t\n\r\f\v";
	str.erase(str.find_last_not_of(typeOfWhitespaces) + 1);
	str.erase(0, str.find_first_not_of(typeOfWhitespaces));

	return str;
}

vector<string> Library :: splitStrings(string str, char delimiter) {
    vector<string> v;
 
    stringstream ss(str);
 
    while (ss.good()) {
        string substr;
        getline(ss, substr, delimiter);
		
        v.push_back(trimWhitespaces(substr));
    }

	return v;
}

void Library :: processAndMapBook(book* newBook) {
	vector<string> processedGenre = splitStrings(newBook->genre, ',');
	cout << processedGenre;
	book *copiedBook = &copyBookContents(newBook);				
	// bookSet.insert(*copiedBook);
	for (auto genre = processedGenre.begin(); genre != processedGenre.end(); ++genre) {
		if (library.find(*genre) == library.end()) {
			book *emptyHead = new book();
			emptyHead->next = copiedBook;
			library[*genre] = *emptyHead;
		} else {
			book *traverse = &library[*genre];
			while (traverse->next != NULL) traverse = traverse->next;
			traverse->next = copiedBook;
		}
	}
}

void Library :: addBooks() {
	cout << endl;
	book* newBook = new book();
	newBook->next = NULL;
	
	cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "title: \n> ";
	getline(cin, newBook->title);

	cout << "author: \n> ";
	getline(cin, newBook->author);

	cout << "genre (comma seperated multiple entries are allowed): \n> ";
	getline(cin, newBook->genre);

	cin.sync();

	cout << "copies: \n> ";
	cin >> newBook->copies;

	newBook->id = rand() % (9000000 - 1000000 + 1) + 1000000;

	processAndMapBook(newBook);
}

void Library :: displayAllBooksUnique() {
	cout << "\nPrinting all books regardless of genre" << endl;
	printElement("Id", 10);
	printElement("Title", 25);
	printElement("Author", 25);
	printElement("Copies", 8);
	printElement("Genre", 25);

	// Tried using set but could not get it to work, so will try a visited vector and only print if the id isn't in the vector. After printing, add the id 
	// to vector visited

	vector<unsigned long int> printedIds;

	// Printing all books regardless of Genre, once.
	for (auto const& imap: library) {
		book *traverse = &library[imap.first];
		traverse = traverse->next;

		while (traverse != NULL && !(find(printedIds.begin(), printedIds.end(), traverse->id) != printedIds.end())) {
			cout << endl;
			printElement(traverse->id, 10);
			printElement(traverse->title, 25);
			printElement(traverse->author, 25);
			printElement(traverse->copies, 8);
			printElement(traverse->genre, 25);
			printedIds.push_back(traverse->id);
			traverse = traverse->next;
		}

	}

	cout << endl;
}

void Library :: displayAllBooksByGenre() {
	cout << "\nPrinting all genres" << endl;
	for (auto const& imap: library) {
		cout << imap.first << ": " << endl;

		book *traverse = &library[imap.first];
		traverse = traverse->next;

		printElement("Id", 10);
		printElement("Title", 25);
		printElement("Author", 25);
		printElement("Copies", 8);
		printElement("Genre", 25);

		while (traverse != NULL) {
			cout << endl;
			printElement(traverse->id, 10);
			printElement(traverse->title, 25);
			printElement(traverse->author, 25);
			printElement(traverse->copies, 8);
			printElement(traverse->genre, 25);
			traverse = traverse->next;
		}
		cout << endl << endl << endl;
	}
}


/*
	Reads a file 'bookdata.txt' and builds the library. Keys are author, title, copies, genre, id (integer). The file should consist of NEWLINE seperated data.
	The data should also be [type: value]

	Example

	id: 6531461
	title: The Lord of the Rings
	author: J. R. R. Tolkien
	genre: Fantasy Fiction, High fantasy, Adventure Fiction, Chivalric Romance, Heroic Fantasy (comma seperated genre keys)
	copies: 4550
	<empty line for new book entry>
	title: AAA
	...
*/
void Library :: buildLibraryFromFile() {
	ifstream filereader;
	vector<string> lines;
	string line;
	book *newBook;

	string title = "title";

	filereader.open("bookdata.txt");

	while (filereader) {
		getline(filereader, line);
		cout << line << endl;

		lines.push_back(line);
	}

	newBook = new book();

	for (auto i = lines.begin(); i != lines.end(); ++i) {
		if (*i == "") {
			if (newBook->id != 0) {
				processAndMapBook(newBook);
			}

			newBook = new book();
			cout << endl;
		} else {
			vector<string> processedLine = splitStrings(*i, ':');
			cout << "type: " << processedLine[0] << ", value: " << processedLine[1] << endl;

			newBook->next = NULL;
			// Find out why I didn't use switch-case here.
			if (processedLine[0] == "title") {
				newBook->title = processedLine[1];
			} else if (processedLine[0] == "id") {
				newBook->id = stoi(processedLine[1]);
			} else if (processedLine[0] == "author") {
				newBook->author = processedLine[1];
			} else if (processedLine[0] == "genre") {
				newBook->genre = processedLine[1];
			} else if (processedLine[0] == "copies") {
				newBook->copies = stoi(processedLine[1]);
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	Library library;
	library.init();
	return 0;
}

