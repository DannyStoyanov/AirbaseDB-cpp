# Airbase database

## Introduction

The program is a database management system for airbase, providing the following basic actions: create, delete, edit, show, update and search aircraft records.

## Architecture

The main idea of the project is based on the architecture which is the command pattern - a behavioral design pattern in which an object is used to encapsulate all information needed to perform an action or trigger an event at a later time.

![architecture image](/doc/architecture.png)

## Requirements

- C++ compiler
- Visual Studio IDE

## Usage

The program is run via the command-line. There are several commands to operate with the database:

create - create record with id, plane, type and number of flights and save it in the database

    create <id> <plane> <type> <flights>

delete - delete record with the given id

    delete <id>

update - update attribute of plane with the given id

    update <id> <attribute> <new_value>

show - display list of records from offset to limit

    show <offset> <limit> 

optimize - sort records

    optimize

search - display whether record with the given id is in the database, whether the  database is optimized - Binary Search (O(log n) time complexity), otherwise Linear Seach (O(n) time complexity)

    search <id>

exit - exit the program

    exit





