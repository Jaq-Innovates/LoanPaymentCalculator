#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main() {
    // Constants
    const int MONTHS_IN_YEAR = 12;

    // Input variables
    string borrowerName, institutionName;
    double loanAmount, annualInterestRate;
    int loanTermYears;

    // Get user input
    cout << "Loan Payment Calculator....." << endl;
    cout << "Please Enter the Following Information: " << endl;
    cout << "Borrower's Name: ";
    getline(cin, borrowerName);
    cout << "Loaning Institution: ";
    getline(cin, institutionName);
    cout << "Loan Amount ($): ";
    cin >> loanAmount;
    cin.ignore(); // Ignore newline character
    cout << "Annual Interest Rate (%): ";
    cin >> annualInterestRate;
    cin.ignore(); // Ignore newline character
    cout << "Term of Loan (years): ";
    cin >> loanTermYears;

    // Get date of report
    string dateOfReport;
    cout << "Date of Report: ";
    getline(cin, dateOfReport);

    // Calculate monthly interest rate and number of monthly payments
    double monthlyInterestRate = (annualInterestRate / 100.0) / MONTHS_IN_YEAR;
    int numberOfPayments = loanTermYears * MONTHS_IN_YEAR;

    // Calculate monthly payment using the formula
    double monthlyPayment = (monthlyInterestRate * loanAmount) /
        (1 - pow(1 + monthlyInterestRate, -numberOfPayments));

    // Calculate total amount to be paid and total interest paid
    double totalAmountPaid = monthlyPayment * numberOfPayments;
    double totalInterestPaid = totalAmountPaid - loanAmount;

    // Output the Loan Payment Summary Report
    cout << fixed << showpoint << setprecision(2);
    cout << "\n---------------------------------------------------\n";
    cout << "Loan Payment Summary Report\n\n";
    cout << setw(30) << left << institutionName << borrowerName << endl;
    cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
    cout << "Date: " << dateOfReport << "\n\n";
    cout << "Loan Amount: " << "$ " << setw(10) << right << loanAmount << endl;
    cout << "Monthly Interest Rate: " << setw(10) << right << monthlyInterestRate * 100 << "%" << endl;
    cout << "Number of Payments: " << setw(10) << right << numberOfPayments << endl;
    cout << "Monthly Payment: " << "$ " << setw(10) << right << monthlyPayment << "\n\n";
    cout << "Total Amount to Pay: " << "$ " << setw(10) << right << totalAmountPaid << endl;
    cout << "Total Interest: " << "$ " << setw(10) << right << totalInterestPaid << "\n\n";
    cout << "---------------------------------------------------\n";

    return 0;
}
