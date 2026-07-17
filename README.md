[READMEE.md](https://github.com/user-attachments/files/30128452/READMEE.md)
# Hotel Room Booking System

**BEE 208: C++ Programming — Mid-Semester Practical Project**
**Non-Technical Project Question 12**
Accra Technical University | Faculty of Engineering | Department of Electrical/Electronic Engineering

---

## 1. Group Members and Index Numbers

| Student | Name | Index Number | Responsibility |
| --- | --- | --- | --- |
| Student 1 | *(Mpenuah Jeremiah)* | *(01242910B)* | Project lead |
| Student 2 | *(Simonetta Agyemang-Baisel)* | *(01243742B)* | Algorithm writer |
| Student 3 | *(Chartey Douglas Tetteh Larnor)* | *(01243671B)* | Pseudocode writer |
| Student 4 | *(Kouassi Elysee Josue)* | *(01244546B)* | Flowchart designer |
| Student 5 | *(Kwadamah Saviour)* | *(01244279B)* | C++ programmer |
| Student 6 | *(David Agyapong Adjaye)* | *(01243659B)* | C++ programmer |
| Student 7 | *(Lartey Israel)* | *(01242816B)* | Testing lead |
| Student 8 | *(Okyere Adu-Aboagye)* | *(01245455B)* | GitHub manager |
| Student 9 | *(Boison Emmanuel Tawiah)* | *(01244317B)* | Documentation lead |
| Student 10 | *(Fauster Edudzi Kuebutornye)* | *(01244914B)* | Presentation lead |

---

## 2. Problem Statement

A small hotel needs a basic booking system to record guests, room types, number of nights and payment status. The system should help the receptionist calculate room charges, classify booking status, and save the booking records for future reference.

## 3. Aim of the Project

To develop a C++ Hotel Room Booking System that records guest bookings, calculates total booking cost, checks room booking status, and saves a booking report into a text file.

## 4. Objectives

- Accept guest name, contact number, room type, room number and number of nights.
- Allow the receptionist to process more than one hotel booking record.
- Calculate total booking cost based on room type and number of nights.
- Use conditional statements to classify booking status.
- Validate invalid inputs such as negative number of nights or invalid room type.
- Display a clear booking summary for each guest.
- Save all booking records into `hotel_booking_report.txt`.

---

## 5. How the Booking System Works

1. The programme displays a welcome banner and asks the receptionist how many bookings will be entered.
2. For each booking, the receptionist enters the guest's name, phone number, room type, room number, number of nights, and payment status.
3. The `HotelBooking` class validates the input — the number of nights must be greater than zero, and the room type must be Single, Double, or Executive. Invalid entries are rejected and logged, and the loop moves to the next booking.
4. Valid entries are priced using the room rate guide (Single = GHS 150, Double = GHS 250, Executive = GHS 400), and the total cost is calculated as `Room Rate × Number of Nights`.
5. The booking status is set to **Confirmed Booking** if the guest has paid, or **Pending Payment** if not.
6. Each booking summary is displayed on screen and written to `hotel_booking_report.txt` using `ofstream`.
7. After all bookings are processed, the programme displays and saves a summary count of confirmed and pending bookings.

## 6. Room Rate Guide

| Room Type | Rate per Night | Description |
| --- | --- | --- |
| Single | GHS 150 | One guest room |
| Double | GHS 250 | Two-person room |
| Executive | GHS 400 | Higher comfort room |
| Invalid Room Type | 0 | Rejected — request correction |

---

## 7. Algorithm

See [`algorithm.md`](algorithm.md) for the full step-by-step algorithm.

## 8. Pseudocode

See [`pseudocode.md`](pseudocode.md) for the full pseudocode listing.

## 9. Flowchart

![Hotel Booking System Flowchart](flowchart.png)

The flowchart shows the flow from Start, through input of booking details, validation, room rate selection, total cost calculation, the payment/booking-status decision, report display, file saving, and Stop.

## 10. Screenshots


![alt text](<screenshots report_file_output-1-1.png>)

![alt text](<screenshots report_file_output 3-1.png>)
```
```
1. C++ Concepts Used

- Input and output using `cin` and `cout`.
- Variables and data types: `string`, `int`, `double`, `bool`.
- Arithmetic operators for total cost calculation.
- Conditional statements (`if` / `else if`) for room rate lookup and booking status classification.
- Loops (`for`) for processing multiple booking records.
- Functions for validation, calculation, display, and file saving.
- Classes and objects (`HotelBooking`) for organising booking data with private members and public methods.
- Vectors (`vector<HotelBooking>`) for storing multiple booking records.
- File handling using `ofstream` to save the booking report.

## 12. Sample Output

```
========================================
       HOTEL ROOM BOOKING SYSTEM
========================================

Enter number of bookings to process: 2

Booking 1
----------------------------------------
Guest Name: Ama Mensah
Phone Number: 0240000000
Room Type (Single/Double/Executive): Double
Room Number: 205
Number of Nights: 3
Payment Status (Paid/Not Paid): Paid

--- Booking Summary ---
Guest Name     : Ama Mensah
Phone Number   : 0240000000
Room Type      : Double
Room Number    : 205
Nights Booked  : 3
Room Rate      : GHS 250.00
Total Cost     : GHS 750.00
Payment Status : Paid
Booking Status : Confirmed Booking
------------------------

Booking 2
----------------------------------------
Guest Name: Kojo Addo
Phone Number: 0551234567
Room Type (Single/Double/Executive): Single
Room Number: 108
Number of Nights: 2
Payment Status (Paid/Not Paid): Not Paid

--- Booking Summary ---
Guest Name     : Kojo Addo
Phone Number   : 0551234567
Room Type      : Single
Room Number    : 108
Nights Booked  : 2
Room Rate      : GHS 150.00
Total Cost     : GHS 300.00
Payment Status : Not Paid
Booking Status : Pending Payment
------------------------

========================================
Confirmed Bookings: 1
Pending Bookings  : 1
Report saved as hotel_booking_report.txt
========================================
```

---

## 13. Challenges Faced and Solutions

| Challenge | Solution |
| --- | --- |
| Mixing `cin >>` and `getline()` caused input fields to shift between records. | Removed a redundant buffer-clearing call and instead cleared the input stream only once, right after reading the number of bookings. |
| Handling invalid room types or negative nights without crashing the programme. | Added a `validateDetails()` method that checks input before any calculation runs, and rejected bookings are logged separately rather than terminating the programme. |
| Keeping the screen display and the saved file report consistent. | Used a shared formatting style (`fixed`, `setprecision(2)`) in both `displayBookingReport()` and `saveBookingReport()`. |

---

## 14. Individual Contribution

| Student | Contribution |
| --- | --- |
| Student 1 | *(Project supervision)* |
| Student 2 | *(Algorithm writer)* |
| Student 3 | *(Flowchart writer)* |
| Student 4 | *(Psuedocode writer)* |
| Student 5 | *(C++ programmer 1)* |
| Student 6 | *(C++ programmer 2)* |
| Student 7 | *(Programme tester)* |
| Student 8 | *(Provided account for GitHub)* |
| Student 9 | *(Documentation lead)* |
| Student 10 | *(Presentation lead)* |

---

## 15. Repository Structure

```
BEE208-Hotel-Room-Booking-System/
├── main.cpp
├── README.md
├── algorithm.md
├── pseudocode.md
├── flowchart.png
├── hotel_booking_report.txt
└── screenshots/
    ├── sample_run_1.png
    └── report_file_output.png
```

## 16. How to Compile and Run

```bash
g++ -std=c++17 -o hotel_booking main.cpp
./hotel_booking
```

On Windows (with g++/MinGW):

```bash
g++ -std=c++17 -o hotel_booking.exe main.cpp
hotel_booking.exe
```
