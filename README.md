<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body style="font-family: Arial, sans-serif; line-height: 1.6; margin: 20px; background-color: #f4f4f4;">

<h1 style="color: #333;">Student Management System</h1>

<p>A console-based student management system written in C. This program allows users to add, show, delete, update, and search student records.</p>

<h2 style="color: #333;">Features</h2>
<ul>
    <li>Add student records with roll number, name, and marks</li>
    <li>Show all student records</li>
    <li>Delete a student record by roll number</li>
    <li>Update a student record by roll number</li>
    <li>Search for a student record by name or roll number</li>
</ul>

<h2 style="color: #333;">Building and Running</h2>
<p>To build and run the project, follow these steps:</p>
<ol>
    <li>Open a terminal and navigate to the project directory</li>
    <li>Run <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">make</code> to build the project</li>
    <li>Run <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">./student_management</code> to run the program</li>
</ol>
<p>Note: The program requires the <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">Student_Datbase.txt</code> file to be present in the project directory. The file is created automatically if it does not exist.</p>

<h2 style="color: #333;">Code Overview</h2>
<p>The program consists of a single source file, <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">student_management.c</code>, which contains the <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">main</code> function and the <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">Student_data</code> struct definition.</p>
<p>The <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">main</code> function implements the main logic of the program, including the user interface and the file I/O operations.</p>
<p>The <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">Student_data</code> struct represents a student record and contains the following fields:</p>
<ul>
    <li><code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">roll</code>: the roll number of the student</li>
    <li><code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">name</code>: the name of the student</li>
    <li><code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">remark</code>: a remark indicating whether the student passed or failed</li>
    <li><code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">paper_1</code>, <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">paper_2</code>, <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">paper_3</code>: the marks obtained by the student in three papers</li>
    <li><code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">result</code>: the total marks obtained by the student</li>
</ul>

<h2 style="color: #333;">File I/O</h2>
<p>The program uses the <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">fopen</code>, <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">fscanf</code>, <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">fprintf</code>, and <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">fclose</code> functions to read and write student records to the <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">Student_Datbase.txt</code> file.</p>
<p>The file is opened in "r" mode for reading and in "w" mode for writing. When the file is opened in "w" mode, any existing data in the file is truncated.</p>
<p>When reading student records from the file, the program uses the <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">feof</code> function to detect the end of the file.</p>

<h2 style="color: #333;">User Interface</h2>
<p>The program uses the <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">printf</code> and <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">scanf</code> functions to display messages and prompts to the user and to read input from the user.</p>
<p>The user interface consists of a main menu that allows the user to choose from the following options:</p>
<ul>
    <li>Add student</li>
    <li>Show students</li>
    <li>Delete student</li>
    <li>Update student</li>
    <li>Search student</li>
    <li>Exit</li>
</ul>
<p>When the user chooses an option, the program displays a sub-menu or performs the corresponding action.</p>

<h2 style="color: #333;">Example Use Case</h2>
<p>Here's an example of how a user might interact with the Student Management System:</p>
<pre style="background-color: #e8e8e8; padding: 10px; border-radius: 4px;">
Welcome to the Student Management System!
1. Add student
2. Show students
3. Delete student
4. Update student
5. Search student
6. Exit
Enter your choice: 1

Enter roll number: 101
Enter name: Alice Smith
Enter marks for Paper 1: 85
Enter marks for Paper 2: 90
Enter marks for Paper 3: 80

Student record added successfully!

1. Add student
2. Show students
3. Delete student
4. Update student
5. Search student
6. Exit
Enter your choice: 2

Showing all students:
Roll No: 101
Name: Alice Smith
Marks: Paper 1: 85, Paper 2: 90, Paper 3: 80
Remark: Passed

1. Add student
2. Show students
3. Delete student
4. Update student
5. Search student
6. Exit
Enter your choice: 6

Exiting the system. Thank you!
</pre>

<h2 style="color: #333;">Conclusion</h2>
<p>This project demonstrates how to implement a simple console-based student management system in C. The program uses file I/O operations and a struct to represent student records. The user interface is implemented using the <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">printf</code> and <code style="background-color: #e8e8e8; padding: 2px 4px; border-radius: 4px;">scanf</code> functions.</p>
<p>I hope you find this project helpful and informative. If you have any questions or feedback, please let me know.</p>

<div style="background-color: #ffe9c5; padding: 10px; border-left: 4px solid #ffcc00; margin: 20px 0;">
    <strong>Note:</strong> This project is a demonstration of basic file handling and data structures in C.
</div>


</body>
</html>
