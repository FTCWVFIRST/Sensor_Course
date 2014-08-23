


task FigureEight()		//Starts first task, task main()
{

	while(1==1)
		{
			for(int i = 0; i <= 3; i++)  // initialize int 'i' to 0, and run the loop as long as 'i' is less than 3,
                             // incrementing 'i' by 1 after each iteration of the loop

			{
				moveForward(15);
				rightTurn();
			}
			for(int i = 0; i <= 3; i++)  // initialize int 'i' to 0, and run the loop as long as 'i' is less than 3,
                             // incrementing 'i' by 1 after each iteration of the loop

			{
				moveForward(15);
				leftTurn();
			}

	}
}
