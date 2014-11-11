READ ME!

Grant Harris
Steve Neet
David Palmiter
Anders Stadum

Team JockNerds presents:  Court Master, a recreational sport team managing application.

This project utilizes the QT Creator GUI IDE.

*TO RUN*
To run, open ix-saucy and compile the program with qmake.
Then execute ./Court_Master 

*OPERATION*
Once the main gui window pops up, there will be a variety of text boxes.
The process begins with a player's registration and appendation to the wait list.
In order to register a player to the game wait list, type the user's name into the
"Name" text box in the upper right hand corner and click "Join wait list". 
At this time, if the player has already used this application, then their statistics such as wins, losses, and time played have been previously recorded in a library text file. If the player has not used the application before, then their name
will be registered for their next appearance.
Whether or not the player has registered beforehand, they will be added to a wait list that operates
as a queue in a first-in first-out manner. Once the correct number of players are within the 
wait list, 

		   IF the Home team is empty: 
					* Home team will be populated with players from the wait list.
		   IF the Home team is full:
		   			* Away team will be populated with players from the wait list.

Note: The default team size is set to 5. This is because the game of basketball was kept in mind,
where each team may have a maximum of 5 players at one time.

If the Home team is full and the Away team is not, then the waiting players will be added to the Away
team until the size restriction has been met.

Once both teams are full, the game may begin. Players press the "start" button on the game clock to
begin recording the length of time that the game will take. Once play has stopped, the game clock 
"stop" button should be clicked. The winning team should then be declared using the drop-down menu
underneath the Home and Away team list. 

Once a winning team has been declared, the losing team's stats will be updated inside the library, and
the winning team will be moved to the Home team. If the Home team won, then they will remain where they are.

*FUTURE FUNCTIONALITY*
Like many software development teams, we were unable to implement every idea
that we originally desired. It would be possible to further improve this application in the following ways:

	*Make it possible for the application to "guess" a winner by creating a rank for each player
		depending upon their wins, losses, and total time played.
	*Create another menu to display the team size (usable for soccer, volleyball, etc)
	*Implement a counter for the number of points that each team scores -> save these values
	    and add them to each player's statistics.