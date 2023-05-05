#include "Board.hpp"
#include "BoardWindow.hpp"
//#include "PiecePlacer.hpp"

#include <QApplication>
#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif
#include <iostream>

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.
	
	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
	#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}

int main(int argc, char *argv[])
{	

	////TESTS:
	//Board board;
	//board.addPiecesOnBoard();
	///*board.printPieceAtPosition({ 0,4 });
	//board.printPieceAtPosition({ 7,4 });
	//board.printPieceAtPosition({ 0,6 });
	//board.printPieceAtPosition({ 0,0 });*/
	//
	///*Piece* myPiece = new Knight({1,1}, PieceColor::Black);
	//PiecePlacer placer(board, myPiece, { 2, 3 });*/ // fonctionne!!

	///*board.printPieceAtPosition({ 1,1 });
	//board.printPieceAtPosition({ 2,3 });*/

	////if (board.checkIfAbleToMove({2 , 3}, {1 , 4})) { // fonctionne
	////	std::cout << "Piece able to move\n";
	////}

	////board.movePiece({ 0 , 4 }, { 1, 5 }); //deplacement basique roi fonctionne 
	////board.printPieceAtPosition({ 0, 4 });
	////board.printPieceAtPosition({ 1, 5 });

	////board.movePiece({ 2 , 3 }, {3, 5}); //deplacement basique cavalier fonctionne 
	////board.printPieceAtPosition({ 2, 3 });
	////board.printPieceAtPosition({ 3, 5 });

	////board.movePiece({ 0 , 2 }, {2, 4}); //deplacement basique cavalier fonctionne 
	////board.printPieceAtPosition({ 0, 2 });
	////board.printPieceAtPosition({ 2, 4 });
	//
	////board.printPieceAtPosition(board.findKing(PieceColor::White)); // fonctionne

	//Piece* wBishop = new Bishop({ 3,3 }, PieceColor::Black);
	//Piece* bBishop = new Bishop({ 4,4 }, PieceColor::Black);
	//board.addPiece(wBishop, 3, 3);
	//board.addPiece(bBishop, 4, 4);
	///*PiecePlacer whiteB(board, wBishop, { 3, 3 });
	//PiecePlacer blackB(board, bBishop, { 4, 4 });*/

	//board.movePiece({ 4 , 4 }, { 6, 5 });
	//board.movePiece({ 4 , 4 }, { 2, 2 });
	//board.movePiece({ 4 , 4 }, { 5, 5 });

	//board.printPieceAtPosition({ 4, 4 });
	//board.printPieceAtPosition({ 6, 5 });
	//board.printPieceAtPosition({ 2, 2 }); // fonctionne: fou detecte qu'une piece bloque son passage
	//board.printPieceAtPosition({ 5, 5 }); // fonctionne
	//
	//Piece* myPiece = new Knight({ 1,1 }, PieceColor::Black);
	//board.addPiece(myPiece, 1, 1);
	////PiecePlacer placer(board, myPiece, { 1, 1 }); // fonctionne!!
	//Piece* myPiece2 = new Knight({ 2,3 }, PieceColor::Black);
	//board.addPiece(myPiece2, 2, 3);
	////PiecePlacer placer2(board, myPiece2, { 2, 3 }); // fonctionne!!
	//board.movePiece({ 1 , 1 }, { 2, 3 });
	//board.printPieceAtPosition({ 2, 3 });
	//board.printPieceAtPosition({ 1, 1 });
	//
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	QApplication app(argc, argv);
	initialiserBibliothequeCours(argc, argv);

	GI::BoardWindow boardWindow;
	boardWindow.show();
	return app.exec();
}
