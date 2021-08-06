# Airbase database

## Introduction

The program is a database management system for airbase, providing the following basic actions: create, delete, edit, view, update and seach aircraft flights records.

## Architecture

The main idea of the project is based on the architecture which is the command pattern - a behavioral design pattern in which an object is used to encapsulate all information needed to perform an action or trigger an event at a later time.

![architecture image](/doc/architecture.png)

## Requirements

C++ compiler

## Usage

The program is run via the command-line. There are several commands to operate with the database:

create - create record with id, plane, type and number of flights and save it in the database

    create <id> <plane> <type> <flights>

delete - delete record with the given id

    delete <id>

update - update attribute of plane with the given id

    update <id> <attribute> 

show - display list of records from offset to limit

    show <offset> <limit> 

optimize - sort records

    optimize

search - display whether record with the given id is in the database

    search <id>

exit - exit the program

    exit





