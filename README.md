# Student-Management-System

![Screenshot](https://github.com/tinashetogara68-tech/Student-Management-System/blob/2cdd54391d487fcbf105190591d7dab26d7ce35c/Screenshot%20(4).png)

## Overview

A C++/Qt Student Management System consisting of two independent applications: a student data-entry application and a main application responsible for processing, managing and retrieving student records.

The system uses Qt's `QProcess` to launch the data-entry application as a separate process, validates student information, manages student and module records, calculates academic performance and determines graduation eligibility. Student information is persisted using XML.

## Features

### 1. Student Data Entry and Input Validation

- Separate Qt application for capturing student details.
- Accepts student numbers, module codes and marks.
- Implements input masks and regular expression validation to ensure that submitted information follows the required formats.
- Applies the following input validation rules:
  - **Student Number:** Must consist of exactly four digits.
  - **Module Code:** Must contain three uppercase alphabetic characters, followed by a year digit (`1`, `2` or `3`), two additional digits, and a final character that may be either alphabetic or numeric.
  - **Module Mark:** Must be an integer between 0 and 100.
- Uses validation techniques to minimise incorrect or improperly formatted user input.
- Communicates submitted student information to the main application through standard output.

### 2. Student Record Management

- Creates and maintains student records.
- Uses a Singleton `StudentList` to manage the collection of student records.
- Checks whether a student already exists using their student number.
- Retrieves individual student records and the complete student list.
- Supports adding multiple modules to an existing student's record.
- Prevents duplicate module registrations for a student.

### 3. Academic Performance Processing

- Calculates the average mark across a student's modules.
- Tracks passed modules.
- Determines whether a student meets the graduation eligibility requirements.
- Retrieves and displays student information, including their student number, registered modules, academic average and graduation status.

### 4. XML Data Persistence

- Uses XML to store student information.
- Serialises student records when the application closes.
- Handles XML file creation through a dedicated `FileWriter` class.
- Preserves student records outside the application's runtime.

## Technologies and Concepts

- **Language:** C++
- **Framework:** Qt
- **Build System:** CMake
- **Process Management:** QProcess
- **Input Validation:** Input Masks, QRegularExpression and QRegularExpressionValidator
- **Data Management:** Object-Oriented Programming and Singleton Design Pattern
- **Data Persistence:** XML
- **GUI Development:** Qt Widgets and layouts
