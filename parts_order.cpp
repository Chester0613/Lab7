#include <iostream>                                      // Provides cin, cout, and endl
#include <iomanip>                                       // Provides fixed and setprecision
using namespace std;                                     // Allows standard-library names without the std:: prefix

int main() {                                             // Starts the program
    int requestCount;                                    // Stores the known number of part requests
    int partChoice;                                      // Stores one menu selection
    int quantity;                                        // Stores the requested quantity for one part
    int validLineCount = 0;                              // Counts requests that have a valid part and quantity
    double unitPrice;                                    // Stores the price selected by the switch
    double lineCost;                                     // Stores the cost of one valid request
    double orderTotal = 0.0;                             // Accumulates all valid line costs
    bool isValidPartChoice;                              // Tracks whether the switch selected a real part

    cout << "Enter number of part requests from 1 to 5: "; // Prompts for the iteration count
    cin >> requestCount;                                 // Reads the first request-count candidate

    // TODO: Validate requestCount with a while loop before processing requests.
    // Keep asking while the count is below 1 or above 5.
    while (requestCount < 1 || requestCount > 5) {
        cout << "Invalid request count. Try again: ";
        cin >> requestCount;
    }

    // TODO: Write the for loop header that processes request 1 through requestCount.
    for (int request = 1; request <= requestCount; request++) {
        isValidPartChoice = true;                          // Reset the part-choice validity flag

        cout << "\nRequest " << request << "\n";
        cout << "1. Cable set ($3.25)\n";
        cout << "2. Fuse pack ($4.50)\n";
        cout << "3. Connector Kit ($1.75)\n";
        cout << "Enter part choice: ";
        cin >> partChoice;

        while (partChoice < 1 || partChoice > 3) {
            cout << "Invalid part choice. Enter 1, 2, or 3: ";
            cin >> partChoice;
        }

        switch (partChoice) {
            case 1:
                unitPrice = 3.25;
                cout << "Selected Cable set." << endl;
                break;
            case 2:
                unitPrice = 4.50;
                cout << "Selected Fuse pack." << endl;
                break;
            case 3:
                unitPrice = 1.75;
                cout << "Selected Connector Kit." << endl;
                break;
            default:
                unitPrice = 0.0;
                isValidPartChoice = false;
                cout << "Unknown part choice. Request skipped." << endl;
                break;
        }

        if (isValidPartChoice) {
            cout << "Enter quantity for this request (1 to 5): ";
            cin >> quantity;

            if (quantity >= 1 && quantity <= 5) {
                lineCost = unitPrice * quantity;
                orderTotal += lineCost;
                validLineCount++;
                cout << fixed << setprecision(2);
                cout << "Line cost: $" << lineCost << endl;
            } else {
                cout << "Invalid quantity. Request skipped." << endl;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nValid requests: " << validLineCount << endl;
    cout << "Order total: $" << orderTotal << endl;

    return 0;                                            // Ends the program successfully
}                                                         // Ends the main function

/*
 * Test analysis:
 * 1. [Explain why orderTotal starts at 0.0.]
 * 2. [Explain why an invalid part choice asks for another menu selection.]
 * 3. [Explain why isValidPartChoice is reset during every for iteration.]
 * 4. [Explain why an invalid quantity does not change validLineCount.]
 * 1.The order total starts at 0.0 because we need to initialize it like that before we start adding to it.
 * This makes it so that the total cost can be accurately calculated without any issues.
    * 2. An invalid part choice asks for another menu selection because the program is designed
    *  to ensure that the user selects a valid part from the menu.
    * 3. isValidPartChoice is reset during every for iteration because each request is independent,
    *  and we need to check the validity of the part choice for each new request.
    * 4. An invalid quantity does not change validLineCount because the request is considered invalid,
    *  and we only want to count requests that have both a valid part choice and a valid quantity.*/