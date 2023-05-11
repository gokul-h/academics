package DA1;

import java.io.*;
import java.util.*;

/** 
* Author: Gokul H 
* Registration number: 20BCE1211
* Date: 09/04/2022
* CSE 1007 Digital Assignment - 1
* On my honor, Gokul H , this programming assignment is my own work.
*/

/**
 * Algorithm
 * 1. Input the file name
 * 2. Import the file
 * 3. Readline by line
 * 4. Process data
 * 5. Output result to a file
 */

// Stores all info related to a particular User
class UserInfo {
    // Declare variables
    String name, answers;
    int[][] ans;
    int[] percentOfB = { 0, 1, 2, 3 };
    char[] dimension = { '-', '-', '-', '-' };

    UserInfo() {
        name = "";
        answers = "";
    }

    void AddUserInfo(String name, String answers) {
        this.name = name;
        this.answers = answers;
    }

    void addCount(int[][] ans) {
        this.ans = ans;
    }

    String print() {
        return name + ": [" + percentOfB[0] + ", " + percentOfB[1] + ", " + percentOfB[2] + ", "
                + percentOfB[3] + "] = " + dimension[0] + dimension[1] + dimension[2] + dimension[3] + "\n";
    }

    void setPercentOfB(int[] percentOfB) {
        this.percentOfB = percentOfB;
    }

    void setDimension(char[] dimension) {
        this.dimension = dimension;
    }

    String getAnswer() {
        return answers;
    }
}

// Driver Code
public class PersonalityTest {
    static final int dimensions = 4;

    public static void main(String[] args) {
        // Create array of class objects to store info of alll users
        UserInfo[] User = new UserInfo[10];
        int noOfUsers;
        noOfUsers = readFromFile(User);
        Processing(User, noOfUsers);
        outputToFile(User);
    }

    static int readFromFile(UserInfo[] User) {
        int noOfUsers = 0;
        String str = "";
        FileInputStream inputFile;
        boolean didFileOpen = false;
        // Loop untill correct file name is given
        while (!didFileOpen) {
            try {
                System.out.println("Enter the file name:");
                BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
                str = userInput.readLine();
            } catch (IOException ioe) {
                System.out.println("Wrong Input!");
            }
            // Read from file
            try {
                inputFile = new FileInputStream(str);
                System.out.println("File opened successfully\n");
                didFileOpen = true;
                Scanner userDetails = new Scanner(inputFile);
                int i = 0;
                while (userDetails.hasNextLine()) {
                    User[i] = new UserInfo();
                    User[i].AddUserInfo(userDetails.nextLine(), userDetails.nextLine());
                    i++;
                }
                noOfUsers = i;
                userDetails.close();
                inputFile.close();
            } catch (Exception e) {
                System.out.println("File not found. Try again");
            }
        }
        return noOfUsers;
    }

    static void Processing(UserInfo[] User, int noOfUsers) {
        for (int j = 0; j < noOfUsers; j++) {
            int[][] ans = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
            String temp = User[j].getAnswer();
            // count number of A , B and -
            for (int i = 0; i < 70; i += 7) {
                if (temp.charAt(i) == 'A' || temp.charAt(i) == 'a') {
                    ans[0][0]++;
                } else if (temp.charAt(i) == 'B' || temp.charAt(i) == 'b') {
                    ans[0][1]++;
                } else {
                    ans[0][2]++;
                }
                if (temp.charAt(i + 1) == 'A' || temp.charAt(i + 1) == 'a') {
                    ans[1][0]++;
                } else if (temp.charAt(i + 1) == 'B' || temp.charAt(i + 1) == 'b') {
                    ans[1][1]++;
                } else {
                    ans[1][2]++;
                }
                if (temp.charAt(i + 2) == 'A' || temp.charAt(i + 2) == 'a') {
                    ans[1][0]++;
                } else if (temp.charAt(i + 2) == 'B' || temp.charAt(i + 2) == 'b') {
                    ans[1][1]++;
                } else {
                    ans[1][2]++;
                }
                if (temp.charAt(i + 3) == 'A' || temp.charAt(i + 3) == 'a') {
                    ans[2][0]++;
                } else if (temp.charAt(i + 3) == 'B' || temp.charAt(i + 3) == 'b') {
                    ans[2][1]++;
                } else {
                    ans[2][2]++;
                }
                if (temp.charAt(i + 4) == 'A' || temp.charAt(i + 4) == 'a') {
                    ans[2][0]++;
                } else if (temp.charAt(i + 4) == 'B' || temp.charAt(i + 4) == 'b') {
                    ans[2][1]++;
                } else {
                    ans[2][2]++;
                }
                if (temp.charAt(i + 5) == 'A' || temp.charAt(i + 5) == 'a') {
                    ans[3][0]++;
                } else if (temp.charAt(i + 5) == 'B' || temp.charAt(i + 5) == 'b') {
                    ans[3][1]++;
                } else {
                    ans[3][2]++;
                }
                if (temp.charAt(i + 6) == 'A' || temp.charAt(i + 6) == 'a') {
                    ans[3][0]++;
                } else if (temp.charAt(i + 6) == 'B' || temp.charAt(i + 6) == 'b') {
                    ans[3][1]++;
                } else {
                    ans[3][2]++;
                }
            }
            User[j].addCount(ans);

            // Calculate percentage of b
            int[] percentOfB = { 0, 0, 0, 0 };
            for (int l = 0; l < dimensions; l++) {
                percentOfB[l] = (int) ((ans[l][1] * 100) / (ans[l][0] + ans[l][1]));
            }
            User[j].setPercentOfB(percentOfB);

            // Set charcters
            char[] dimension = { '-', '-', '-', '-' };
            if (percentOfB[0] > 50)
                dimension[0] = 'I';
            else if (percentOfB[0] == 50)
                dimension[0] = 'X';
            else
                dimension[0] = 'E';
            if (percentOfB[1] > 50)
                dimension[1] = 'N';
            else if (percentOfB[1] == 50)
                dimension[1] = 'X';
            else
                dimension[1] = 'S';
            if (percentOfB[2] > 50)
                dimension[2] = 'F';
            else if (percentOfB[2] == 50)
                dimension[2] = 'X';
            else
                dimension[2] = 'T';
            if (percentOfB[3] > 50)
                dimension[3] = 'P';
            else if (percentOfB[3] == 50)
                dimension[3] = 'X';
            else
                dimension[3] = 'J';
            User[j].setDimension(dimension);
            ;

        }

    }

    // Output to file
    static void outputToFile(UserInfo[] u) {
        int no_of_objects = 9;
        // Check if file exist or create a file
        try {
            File fileName = new File("DA1\\result.txt");
            if (fileName.createNewFile()) {
                System.out.println("File created: " + fileName.getName());
            } else {
                System.out.println("File already exists.");
            }
            try {
                // Write to file
                FileWriter outputFile = new FileWriter("DA1\\result.txt");
                for (int i = 0; i < no_of_objects; i++) {
                    outputFile.write(u[i].print());
                }
                outputFile.close();
                System.out.println("Successfully wrote to the file.");
            } catch (IOException e) {
                System.out.println("Could not write to the file.");
            }
        } catch (IOException e) {
            System.out.println("Unable to create file.");
        }
    }
}
