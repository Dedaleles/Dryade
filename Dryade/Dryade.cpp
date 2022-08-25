// Dryade.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Grid.h"
#include "HexCoord.h"

int main()
{
    std::ifstream grid_stream("grid.txt");
    Grid *grid = Grid::parse(grid_stream);

    std::cout << grid->computeRing(grid->getCoord(19), 1);
    grid = Grid::getInstance();
    std::cout << &grid->getCoord(0) << std::endl;
    std::cout << &grid->getTile(0).getCoord();
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
