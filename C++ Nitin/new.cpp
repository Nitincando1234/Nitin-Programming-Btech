#include <iostream>
#include <fstream>

int main() {
    // Step 2: Open the file for writing
    std::fstream file("example.txt", std::ios::out);

    // Step 3: Check if the file is open
    if (file.is_open()) {
        // Step 4: Write data to the file
        file << "Hello, this is a sample line." << std::endl;
        file << "This is another line." << std::endl;

        // Step 5: Close the file
        file.close();
        std::cout << "File saved successfully." << std::endl;
    } else {
        // Handle the case where the file couldn't be opened
        std::cerr << "Error opening the file!" << std::endl;
    }

    return 0;
}
