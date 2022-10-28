#include <gtest/gtest.h>

#include "IndexedArray.h"

TEST(IndexedArray, Size) {
    EXPECT_EQ(sizeof(IndexedArray<int, 1>), sizeof(int));
    EXPECT_EQ(sizeof(IndexedArray<int, 1, 1>), sizeof(int));
    EXPECT_EQ(sizeof(IndexedArray<int, 10>), 10 * sizeof(int));
    EXPECT_EQ(sizeof(IndexedArray<int, 1, 7>), 7 * sizeof(int));
    EXPECT_EQ(sizeof(IndexedArray<int, -10, 10>), 21 * sizeof(int));
    EXPECT_EQ(sizeof(IndexedArray<int, 0>), sizeof(std::array<int, 0>));

    enum class Index { A = 1000, B, C, D };
    using enum Index;

    EXPECT_EQ(sizeof(IndexedArray<int, A, D>), 4 * sizeof(int));
}

TEST(IndexedArray, NonZeroIndex) {
    enum class Index {
        AA = -10,
        XX = 0,
        BB = 10
    };
    using enum Index;

    IndexedArray<int, AA, BB> a = {{}};

    EXPECT_EQ(a[AA], 0);
    EXPECT_EQ(a[BB], 0);
    EXPECT_EQ(a[XX], 0);

    for(int &val: a) {
        val = -1;
        break;
    }

    EXPECT_EQ(a[AA], -1);
}

TEST(IndexedArray, MapInit) {
    enum class Index { A, B, C, D };
    using enum Index;

    IndexedArray<int, A, D> a = {
        {A, 0},
        {D, 1},
        {C, 2},
        {B, 3}
    };

    EXPECT_EQ(a[A], 0);
    EXPECT_EQ(a[B], 3);
    EXPECT_EQ(a[C], 2);
    EXPECT_EQ(a[D], 1);
}
