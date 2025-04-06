#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Movie {
public:
    int movie_id;
    string name;
    string genre;
    string time;
    int available_seats;
    int next_seat;

    Movie(int id, string name, string genre, string time, int available_seats) {
        this->movie_id = id;
        this->name = name;
        this->genre = genre;
        this->time = time;
        this->available_seats = available_seats;
        this->next_seat = 1;
    }
};

class Customer {
public:
    string name;
    int age;
    string movie_name;
    int seat_number;
    static int customer_id;

    Customer(string name, int age, string movie_name, int seat_number) {
        this->name = name;
        this->age = age;
        this->movie_name = movie_name;
        this->seat_number = seat_number;
    }
};

int Customer::customer_id = 0;

void book_ticket(Customer c, int movie_id) {
    Customer::customer_id += 1;
    fstream file("customers.csv", ios::app);

    if (!file) {
        cout << " Error opening customers.csv file!\n";
        return;
    }

    file << Customer::customer_id << ","
         << movie_id << ","
         << c.name << ","
         << c.age << ","
         << c.movie_name << ","
         << c.seat_number << "\n";

    file.close();

    cout << "\n Ticket Booked Successfully!\n";
    cout << "Name: " << c.name << "\n";
    cout << "Age: " << c.age << "\n";
    cout << "Movie: " << c.movie_name << "\n";
    cout << "Seat Number: " << c.seat_number << "\n";
}

void search_movie(const string& filename, const string& movie_name) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << " Error opening movies.csv file!\n";
        return;
    }

    string line;
    getline(file, line); // Skip header
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        string cell;

        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        if (row.size() < 5) continue;

        if (row[1] == movie_name) {
            cout << "\n🎬 Movie Details:\n";
            cout << "Movie ID: " << row[0] << endl;
            cout << "Name: " << row[1] << endl;
            cout << "Genre: " << row[2] << endl;
            cout << "Time: " << row[3] << endl;
            cout << "Available Seats: " << row[4] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << " Movie not found!\n";
    }

    file.close();
}

class Admin {
public:
    void add_movie(Movie m) {
        ofstream file("movies.csv", ios::app);

        if (!file) {
            cout << " Error opening movies.csv file!\n";
            return;
        }

        file << m.movie_id << ","
             << m.name << ","
             << m.genre << ","
             << m.time << ","
             << m.available_seats << "\n";

        file.close();
    }
};

int main() {
    // Initialize CSV files with headers
    ofstream movie_file("movies.csv");
    if (!movie_file) {
        cout << " Error creating movies.csv!\n";
        return 1;
    }
    movie_file << "ID,Name,Genre,Time,Available Seats\n";
    movie_file.close();
    cout << " movies.csv created.\n";

    ofstream customer_file("customers.csv");
    if (!customer_file) {
        cout << " Error creating customers.csv!\n";
        return 1;
    }
    customer_file << "Customer ID,Movie ID,Name,Age,Movie Name,Seat Number\n";
    customer_file.close();
    cout << " customers.csv created.\n";

    // Add default movies
    Admin admin;
    Movie m1(1, "Bahubali", "Action", "6:00 PM", 200);
    Movie m2(2, "KGF", "Drama", "8:00 PM", 200);
    Movie m3(3, "RRR", "Historical", "5:00 PM", 200);
    admin.add_movie(m1);
    admin.add_movie(m2);
    admin.add_movie(m3);

    cout << "\n Default Movies Added Successfully!\n";

    // Let user select movie
    int choice;
    cout << "\nSelect a Movie to Book:\n";
    cout << "1. Bahubali\n";
    cout << "2. KGF\n";
    cout << "3. RRR\n";
    cout << "Enter choice (1-3): ";
    cin >> choice;
    cin.ignore(); // Clear buffer

    string movie_name;
    Movie* selected_movie;

    switch (choice) {
        case 1:
            movie_name = "Bahubali";
            selected_movie = &m1;
            break;
        case 2:
            movie_name = "KGF";
            selected_movie = &m2;
            break;
        case 3:
            movie_name = "RRR";
            selected_movie = &m3;
            break;
        default:
            cout << " Invalid movie selection!\n";
            return 0;
    }

    search_movie("movies.csv", movie_name);

    int num_customers;
    cout << "\nEnter number of customers to book: ";
    cin >> num_customers;
    cin.ignore();

    if (num_customers > selected_movie->available_seats) {
        cout << " Not enough seats available!\n";
        return 0;
    }

    for (int i = 0; i < num_customers; i++) {
        string name;
        int age;

        cout << "\nEnter details for Customer " << i + 1 << ":\n";
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();

        int seat_number = selected_movie->next_seat;
        selected_movie->next_seat++;
        selected_movie->available_seats--;

        Customer customer(name, age, movie_name, seat_number);
        book_ticket(customer, selected_movie->movie_id);
    }

    return 0;
}
