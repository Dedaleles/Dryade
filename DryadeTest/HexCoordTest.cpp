#include "pch.h"
#include "CppUnitTest.h"
#include "../Dryade/HexCoord.h"
#include <format>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            template<> static std::wstring ToString<HexCoord>(const class HexCoord& t) { return std::format(L"Tile: ({},{})", t.getQ(), t.getR()); }
        }
    }
}

namespace DryadeTest
{
    TEST_CLASS(HexCoordTest)
    {
    public:

        TEST_METHOD(createHexCoord)
        {
            HexCoord t(1, 2);
            // Test
            Assert::AreEqual(1, t.getQ());
            Assert::AreEqual(2, t.getR());

        }

        TEST_METHOD(addHexCoord)
        {
            HexCoord t1(1, 2);
            HexCoord t2(3, -2);
            HexCoord t3(4, 0);
            // Test
            Assert::AreEqual(t3, t1 + t2);

        }

        TEST_METHOD(substractHexCoord)
        {
            HexCoord t1(1, 2);
            HexCoord t2(3, -2);
            HexCoord t3(-2, 4);
            // Test
            Assert::AreEqual(t3, t1 - t2);

        }

        TEST_METHOD(scaleHexCoord)
        {
            HexCoord t1(1, 2);
            int factor = 4;
            HexCoord t3(4, 8);
            // Test
            Assert::AreEqual(t3, t1 * factor);

        }

        TEST_METHOD(distHexCoord) {
            HexCoord t1(1, 1);
            HexCoord t2(0, -3);

            Assert::AreEqual(5, t1.dist(t2));
        }
    };
}