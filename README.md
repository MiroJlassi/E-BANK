#E-BANK
 
 _______________________________________________________________________________________
|                                                                                       |
|   oooooooooooo         oooooooooo.        .o.       ooooo      ooo oooo    oooo       |
|   `888'     `8         `888'   `Y8b      .888.      `888b.     `8' `888   .8P'        |
|    888                  888     888     .8"888.      8 `88b.    8   888  d8'          | 
|    888oooo8             888oooo888'    .8' `888.     8   `88b.  8   88888[            |
|    888    "    8888888  888    `88b   .88ooo8888.    8     `88b.8   888`88b.          |
|    888       o          888    .88P  .8'     `888.   8       `888   888  `88b.        |
|   o888ooooood8         o888bood8P'  o88o     o8888o o8o        `8  o888o  o888o       |
|_______________________________________________________________________________________|



~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Table of Contents
	1. Introduction
	2. Getting Started
		Prerequisites
		Installation
	3. Usage
		Menu Structure
		Clients Management
		Transactions
	4. Code Structure
		Main Function
		Menu Functions
		Client Functions
		Transaction Function
	5. Examples
	6. Contributing
	7. License

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Introduction
2. 
	E-Bank is a simple command-line application for managing a bank branch written in the C language.
It allows users to perform banking activities just like in a real bank.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
2. Getting Started

	Installation
		run "app builder.bat" file in order to build the app and update it
		run main.exe

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
3. Usage

you can navigate through the app using your numpad 

	Menu Structure
		the main menu contains 4 options 
			Clients
			Transactions
			About
			Exit

	Clients Management
		clients section 
			display clients
			add new client
			update clients informations
			remove a client

	Transactions
		Transactions section
			Display Transactions History
			Make new Transaction

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
4. Code Structure

	main(){
	   menu(){
	      clients(){clientslist(), Newclient(), updateclient(), removeclient()}
              transactions(){displaytransactions(), maketransaction()}
	      about()		
 	   }
	}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


