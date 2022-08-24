#include "pch.h"
#include "CppUnitTest.h"
#include "../Dryade/Grid.h"

#include <format>
#include <iostream>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            template<> static std::wstring ToString<Grid>(const class Grid& t) { return L"grid"; }
            template<> static std::wstring ToString<class Grid>( class Grid* t) { return L"grid"; }

            template<> static std::wstring ToString<HexCoord>(const class HexCoord& t) { return std::format(L"Tile: ({},{})", t.getQ(), t.getR()); }

        }
    }
}

namespace DryadeTest
{
    TEST_CLASS(GridTest)
    {
    public:

        TEST_METHOD(gridSingletonTest)
        {
            std::ifstream grid_stream("grid.txt");
            Grid* grid = Grid::parse(grid_stream);
            Grid* second_grid = Grid::getInstance();
            // Test
            Assert::IsTrue(grid == second_grid);

        }

 


    };
}