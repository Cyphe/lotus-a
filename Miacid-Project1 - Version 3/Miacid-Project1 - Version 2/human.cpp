#include "foundation.h"

void PerformHumanTurn(Player &player)
{
	// Variables
	Point2i click = Point2i(-1, -1); //invalid click
	int position1 = 0;
	int position2 = 0;
	PIECE curpiece = player.piece;
	bool skip=0;  //Req105.1 
	// If the player has no possible moves, then they can move any piece OR SKIP THEIR TURN...

	if (!GameData()->board.PossibleMove(player.piece)){
		curpiece = PIECE_BAD;
		skip=1; //a rule based AI will skip their turn if all their pieces are covered Req105.2 
		if (!GameData()->pro) {//Req105.3
			if (GameData()->players.at(GameData()->currentPlayer).isHuman){
				while (true){
				
	
					GameData()->skipoption=1;
					Point2i mousepos;
					GameData()->ResetLastClick();
					do
					mousepos = GameData()->GetLastClick();
					while (mousepos == Point2i(-1,-1));

					if (mousepos.x >= 195 && mousepos.x <= 246 && mousepos.y >= 255 && mousepos.y <= 279){

						skip=1;
						GameData()->skipoption=0;
						break;
					}
					else if (mousepos.x >= 261 && mousepos.x <= 313 && mousepos.y >= 253 && mousepos.y <= 280){

						skip=0;
						GameData()->skipoption=0;
						break;
					}
				}
			}
		}
	}

	if (!skip){ //Req105.1 


		// Loop until a valid move has been completed
		while (true)
		{
			// Get first valid position
			while (true)
			{
				// Reset last click
				GameData()->ResetLastClick();

				// Wait for a click to come through...
				do
				click = GameData()->GetLastClick();
				while (click == Point2i(-1, -1));

				// Check if click is on a piece
				if (GameData()->board.GetLocationFromXY(click.x, click.y, position1))
				{
					PIECE testpiece = GameData()->board.GetTopPiece(position1);

					// Must be a playable piece
					if (testpiece == PIECE_BAD)
						continue;

					// Move allowable pieces
					if (curpiece == PIECE_BAD || curpiece == testpiece)
						break;
				}
			}

			// Get second position
			while (true)
			{
				// Reset last click
				GameData()->ResetLastClick();

				// Wait for a click to come through...
				do
				click = GameData()->GetLastClick();
				while (click == Point2i(-1, -1));



				//deselection of a movable piece Req104.17
				//if (false)
				//	NULL;//GameData()->ResetLastClick();
				//WORKS FOR REQUIREMENT, WAS THERE A SEPARATE VISUAL SELECTION REQUIREMENT?



				// Check if click is on a piece
				//else {
					if (GameData()->board.GetLocationFromXY(click.x, click.y, position2))
					{
						 if (position1==position2){ //if a player selects, the de-selects a piece req104.17
							//this wont move the piece, resets both clicks, breaks from loop to start over
						 //FIXXXXXXXXXXX THISSSSSSSSSS, look at bord
								/*
								if(GameData()->currentPlayer==0)
									GameData()->board.MovePiece(position1,-7);
								else
									GameData()->board.MovePiece(position1,-1);

								GameData()->board.possibleMoves=99;*/
							
							break;
						  }
						else if (position2 >= 0)
							break;
					}
				}
			//}


			// Attempt to move piece
			if (GameData()->board.MovePiece(position1, position2))
				break;
		}
	}
}