#E-BANK

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

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1. Introduction:
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


