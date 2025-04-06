# Movie Ticket Booking System

## Overview

This is a simple C++ console-based movie ticket booking system. It allows users to select a movie, book seats, and stores booking details in CSV files. It uses basic object-oriented programming concepts and file handling in C++.

## Features

- Add default movies to a file (`movies.csv`)
- Display movie details
- Book tickets for multiple customers
- Store customer details and seat information in `customers.csv`
- Seat availability is updated as bookings are made

## How It Works

1. The program initializes two CSV files: `movies.csv` and `customers.csv`.
2. Default movies are added automatically.
3. The user is prompted to choose a movie.
4. The user enters the number of seats to book and provides customer details.
5. Booked details are saved, and seat numbers are auto-assigned.

## Sample Booking Flow

Select a Movie to Book:

Bahubali

KGF

RRR Enter choice (1-3): 1

Movie Details: Movie ID: 1 Name: Bahubali Genre: Action Time: 6:00 PM Available Seats: 200

Enter number of customers to book: 2

Enter details for Customer 1: Enter Name: John Enter Age: 25

Ticket Booked Successfully! Name: John Age: 25 Movie: Bahubali Seat Number: 1

## Author
Abhay Singh
