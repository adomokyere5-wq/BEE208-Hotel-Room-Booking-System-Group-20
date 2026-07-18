/*
 * ============================================================
 *  HOTEL ROOM BOOKING SYSTEM
 *  BEE 208: C++ Programming - Mid-Semester Practical Project
 *  Non-Technical Project Question 12
 * ============================================================
 *  This program records guest bookings, calculates total cost,
 *  determines booking status (Confirmed / Pending), and saves
 *  a full booking report to hotel_booking_report.txt
 * ============================================================
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// ------------------------------------------------------------
// HotelBooking class - stores and processes one booking record
// ------------------------------------------------------------
class HotelBooking {
private:
    string guestName;
    string phoneNumber;
    string roomType;
    int roomNumber;
    int numberOfNights;
    double roomRate;
    double totalCost;
    string paymentStatus;
    string bookingStatus;
    bool isValid;

public:
    // Collects guest and booking details from the user
    void setBookingDetails() {
        cout << "Guest Name: ";
        getline(cin, guestName);

        cout << "Phone Number: ";
        getline(cin, phoneNumber);

        cout << "Room Type (Single/Double/Executive): ";
        getline(cin, roomType);

        cout << "Room Number: ";
        cin >> roomNumber;

        cout << "Number of Nights: ";
        cin >> numberOfNights;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Payment Status (Paid/Not Paid): ";
        getline(cin, paymentStatus);

        isValid = validateDetails();
    }

    // Validates number of nights and room type
    bool validateDetails() {
        if (numberOfNights <= 0) {
            cout << ">> Invalid number of nights entered.\n";
            return false;
        }
        if (roomType != "Single" && roomType != "Double" && roomType != "Executive") {
            cout << ">> Invalid room type entered.\n";
            return false;
        }
        return true;
    }

    // Determines rate per night based on room type
    void calculateRoomRate() {
        if (roomType == "Single")
            roomRate = 150.0;
        else if (roomType == "Double")
            roomRate = 250.0;
        else if (roomType == "Executive")
            roomRate = 400.0;
        else
            roomRate = 0.0;
    }

    // Calculates total cost = rate x nights
    void calculateTotalCost() {
        totalCost = roomRate * numberOfNights;
    }

    // Determines booking status from payment status
    void determineBookingStatus() {
        if (paymentStatus == "Paid")
            bookingStatus = "Confirmed Booking";
        else
            bookingStatus = "Pending Payment";
    }

    // Displays booking summary on screen
    void displayBookingReport() const {
        cout << fixed << setprecision(2);
        cout << "\n--- Booking Summary ---\n";
        cout << "Guest Name     : " << guestName << "\n";
        cout << "Phone Number   : " << phoneNumber << "\n";
        cout << "Room Type      : " << roomType << "\n";
        cout << "Room Number    : " << roomNumber << "\n";
        cout << "Nights Booked  : " << numberOfNights << "\n";
        cout << "Room Rate      : GHS " << roomRate << "\n";
        cout << "Total Cost     : GHS " << totalCost << "\n";
        cout << "Payment Status : " << paymentStatus << "\n";
        cout << "Booking Status : " << bookingStatus << "\n";
        cout << "------------------------\n";
    }

    // Writes the booking record to the output file
    void saveBookingReport(ofstream& file) const {
        file << fixed << setprecision(2);
        file << "Guest Name     : " << guestName << "\n";
        file << "Phone Number   : " << phoneNumber << "\n";
        file << "Room Type      : " << roomType << "\n";
        file << "Room Number    : " << roomNumber << "\n";
        file << "Nights Booked  : " << numberOfNights << "\n";
        file << "Room Rate      : GHS " << roomRate << "\n";
        file << "Total Cost     : GHS " << totalCost << "\n";
        file << "Payment Status : " << paymentStatus << "\n";
        file << "Booking Status : " << bookingStatus << "\n";
        file << "------------------------------------\n";
    }

    bool getIsValid() const { return isValid; }
    string getBookingStatus() const { return bookingStatus; }
};

// ------------------------------------------------------------
// Function prototypes
// ------------------------------------------------------------
void displayWelcomeMessage();
int getNumberOfBookings();

// ------------------------------------------------------------
// Main function
// ------------------------------------------------------------
int main() {
    displayWelcomeMessage();

    int numberOfBookings = getNumberOfBookings();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<HotelBooking> bookings;
    int confirmedCount = 0;
    int pendingCount = 0;
    int rejectedCount = 0;

    ofstream reportFile("hotel_booking_report.txt");
    if (!reportFile) {
        cout << "Error: Could not create report file.\n";
        return 1;
    }

    reportFile << "========================================\n";
    reportFile << "     HOTEL ROOM BOOKING SYSTEM REPORT\n";
    reportFile << "========================================\n\n";

    for (int i = 1; i <= numberOfBookings; i++) {
        cout << "\nBooking " << i << "\n";
        cout << "----------------------------------------\n";

        HotelBooking booking;
        booking.setBookingDetails();

        if (!booking.getIsValid()) {
            cout << ">> Booking " << i << " skipped due to invalid input.\n";
            reportFile << "Booking " << i << ": REJECTED (invalid room type or nights)\n";
            reportFile << "------------------------------------\n";
            rejectedCount++;
            continue;
        }

        booking.calculateRoomRate();
        booking.calculateTotalCost();
        booking.determineBookingStatus();
        booking.displayBookingReport();

        reportFile << "Booking " << i << ":\n";
        booking.saveBookingReport(reportFile);

        if (booking.getBookingStatus() == "Confirmed Booking")
            confirmedCount++;
        else
            pendingCount++;

        bookings.push_back(booking);
    }

    cout << "\n========================================\n";
    cout << "Confirmed Bookings: " << confirmedCount << "\n";
    cout << "Pending Bookings  : " << pendingCount << "\n";
    if (rejectedCount > 0)
        cout << "Rejected Entries  : " << rejectedCount << "\n";
    cout << "Report saved as hotel_booking_report.txt\n";
    cout << "========================================\n";

    reportFile << "\n========================================\n";
    reportFile << "Confirmed Bookings: " << confirmedCount << "\n";
    reportFile << "Pending Bookings  : " << pendingCount << "\n";
    if (rejectedCount > 0)
        reportFile << "Rejected Entries  : " << rejectedCount << "\n";
    reportFile << "========================================\n";

    reportFile.close();

    return 0;
}

// ------------------------------------------------------------
// Displays the welcome banner
// ------------------------------------------------------------
void displayWelcomeMessage() {
    cout << "========================================\n";
    cout << "       HOTEL ROOM BOOKING SYSTEM\n";
    cout << "========================================\n";
}

// ------------------------------------------------------------
// Prompts and validates the number of bookings to process
// ------------------------------------------------------------
int getNumberOfBookings() {
    int n;
    do {
        cout << "\nEnter number of bookings to process: ";
        cin >> n;
        if (n <= 0)
            cout << ">> Please enter a positive number.\n";
    } while (n <= 0);


    return n;
}
