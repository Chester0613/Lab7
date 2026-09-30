#include <iostream>                                      // Provides cin, cout, and endl
#include <iomanip>                                       // Provides fixed and setprecision
using namespace std;                                     // Allows standard-library names without the std:: prefix

int main() {                                             // Starts the program
    int deviceCount;                                     // Stores the known number of devices in the batch
    int passingDeviceCount = 0;                          // Counts devices with a passing quality score
    double qualityScore;                                 // Stores one device score per iteration
    double totalScore = 0.0;                             // Accumulates all quality scores

    cout << "Enter number of devices from 1 to 10: ";  // Prompts for the batch size
    cin >> deviceCount;                                  // Reads the first batch-size candidate

    while (deviceCount < 1 || deviceCount > 10) {        // Repeats while the batch size is outside the allowed range
        cout << "Invalid device count. Try again: ";    // Explains why another batch size is required
        cin >> deviceCount;                              // Reads a replacement batch size
    }                                                     // Ends after a valid batch size is entered


    /*Escribe un for que empiece con device = 1, continúe mientras device <= deviceCount y aumente device de uno en uno.*/
    for (int device = 1; device <= deviceCount; device++) {
        cout << "Enter quality score for device " << device << ": ";
        cin >> qualityScore;
        totalScore += qualityScore;
        if (qualityScore >= 70.0) {
            passingDeviceCount++;
            cout << "Device passed inspection." << endl;
        } else {
            cout << "Device requires review." << endl;
        }
    }
    double averageScore = totalScore / deviceCount;
    cout << fixed << setprecision(2);
    cout << "Total quality score: " << totalScore << endl;
    cout << "Average quality score: " << averageScore << endl;
    cout << "Number of passing devices: " << passingDeviceCount << endl;


    return 0;                                            // Ends the program successfully
}                                                         // Ends the main function

/*
 * Analysis:
 * 1. [Explain why totalScore starts at 0.0.]
 * 2. [Explain why passingDeviceCount changes for 70 but not for 69.]
 * 3. [Explain why averageScore is calculated after the for loop.]
 * 1. The totalScore starts at 0.0 because we need to initialize the accumulator 
 * variable to zero before we start adding to it. This ensures 
 * that the total score accurately reflects the sum of all scores entered by the user.
 * 2. The passingDeviceCount changes for a quality score of 70 but not for 69 because 
 * the program is designed to consider a score of 70 or higher as good. Therefore, 
 * when a device receives a score of 70, it means its in good condition, 
 * while a score of 69 does not meet the good condition mark and does not affect the count.
 3.The averageScore is calculated after the for loop because we need to 
 accumulate all the quality scores first before we can compute the average. */