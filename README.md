# Movie_Ticket_Booking_System

A simple C++ console application to book movie tickets, built using object-oriented programming and basic file handling. This project stores movie and customer data in CSV files and simulates a real-world movie ticket booking experience through the terminal.

---

## About the Project

This is a beginner-friendly project that demonstrates how to build a mini booking system using C++. The idea is to allow users to:

- View available movies
- Choose a movie
- Book seats by entering customer details
- Store the bookings in a CSV file for future reference

---

## Features

- Creates and initializes CSV files (`movies.csv`, `customers.csv`)
- Preloads three popular movies with seat availability
- Allows multiple customer bookings in one go
- Automatically assigns seat numbers
- Saves customer booking data persistently in `customers.csv`
- Simple movie search functionality

---

## How It Works

1. When the program starts, it creates the CSV files if they don’t exist.
2. It adds a few default movies with fixed time slots and 200 available seats each.
3. The user selects a movie and provides the number of people booking tickets.
4. For each person, the program asks for their name and age.
5. The system assigns the next available seat and stores the booking.

---

## Files in the Project

- `Movie_Ticket.cpp` – Main source code
- `movies.csv` – Stores movie information like ID, name, genre, time, and seats
- `customers.csv` – Stores each customer’s name, age, seat number, and booking info

---

## How to Compile and Run

### Windows (using g++):
```bash
g++ Movie_Ticket.cpp -o Movie_Ticket
Movie_Ticket.exe

# **This is a big and bold heading (H1)**

## **This is slightly smaller but bold (H2)**

### **This is even smaller but still bold (H3)**
