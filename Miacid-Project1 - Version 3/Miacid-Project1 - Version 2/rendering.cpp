#include "foundation.h"

// Display a "Loading..." message on the screen
void RenderLoading()
{
	static PNG* pngLoading = &(GameData()->LoadingImage);
	pngLoading->displayAt(glutGet(GLUT_WINDOW_WIDTH) - pngLoading->getWidth(), glutGet(GLUT_WINDOW_HEIGHT) - pngLoading->getHeight(), 1);
}

// The screen displayed to select the number of players
// The screen displayed to select the number of players
void RenderSelectPlayers()
{
	GameData()->LotusFrontBoard.displayAt(0, 0);


	//GameData()->LotusRSel.displayAt(50, 50);
	if (!GameData()->selectPlayerType)
		GameData()->LotusPlayers.displayAt(0, 300);
	else
	{
		GameData()->LotusRSel.displayAt(210, 20);
		if (GameData()->pro)
			GameData()->LotusYes.displayAt(228, 49);
		else
			GameData()->LotusNo.displayAt(228, 49);

		GameData()->LotusPlayer1.displayAt(100, 300);
		if (GameData()->players.at(0).isHuman)
			GameData()->LotusHuman.displayAt(100,325);
		else if (GameData()->players.at(0).isRule)
			GameData()->LotusAIRule.displayAt(100,325);
		else
			GameData()->LotusAIState.displayAt(100,325);

		GameData()->LotusPlayer2.displayAt(300, 300);
		if (GameData()->players.at(1).isHuman)
			GameData()->LotusHuman.displayAt(300,325);
		else if (GameData()->players.at(1).isRule)
			GameData()->LotusAIRule.displayAt(300,325);
		else
			GameData()->LotusAIState.displayAt(300,325);

		//code here edited to only display player 3 if 3-4 players have been selected for Req104.9 
		if (GameData()->players.at(2).isPlaying){
			GameData()->LotusPlayer3.displayAt(100, 400);

			if (GameData()->players.at(2).isHuman)
				GameData()->LotusHuman.displayAt(100,425);
			else if (GameData()->players.at(2).isRule)
				GameData()->LotusAIRule.displayAt(100,425);
			else
				GameData()->LotusAIState.displayAt(100,425);
		}


		//code here edited to only display player 4 if 4 players have been selected for Req104.9 
		if (GameData()->players.at(3).isPlaying){
			GameData()->LotusPlayer4.displayAt(300, 400);

			if (GameData()->players.at(3).isHuman)
				GameData()->LotusHuman.displayAt(300,425);
			else if (GameData()->players.at(3).isRule)
				GameData()->LotusAIRule.displayAt(300,425);
			else
				GameData()->LotusAIState.displayAt(300,425);
		}
		GameData()->LotusFinished.displayAt(232, 350);
	}


	if (GameData()->confirmselect==1)
		GameData()->LotusConfirm.displayAt(200, 220);
	if (GameData()->firstoption==1){
		GameData()->LotusPSel.displayAt(171, 190);
		GameData()->LotusWhite.displayAt(186, 240);
		GameData()->LotusBlack.displayAt(231, 240);
		if (GameData()->numplayers>2){
			GameData()->LotusRed.displayAt(276, 240);
			if (GameData()->numplayers>3)
				GameData()->LotusBlue.displayAt(321, 240);
		}


	}
}

// The main render function (can be used to call other rendering functions)
void RenderMainBoard()
{
	// Render the board
	GameData()->board.Render();

	// Render player scores?
}

// Shown when the game has been finished. Who won?
void RenderResults()
{
	GameData()->LotusBoard.displayAt(0, 0);
}

