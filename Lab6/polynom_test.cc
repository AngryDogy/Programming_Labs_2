#include <gtest/gtest.h>
#include "polynom.h"
TEST(PolynomTest, First) {

    constexpr int m[4] = {1, 2, 3, 4};
    constexpr Polynom<4> polynom(m, 4);
    constexpr int result = polynom.value(1);
    static_assert(result == 10, "Wrong");
    EXPECT_EQ(result, 10);
}
TEST(PolynomTest, Second) {

    constexpr int m[4] = {0, 0, 0, 0};
    constexpr Polynom<4> polynom(m, 4);
    constexpr int result = polynom.value(10);
    static_assert(result == 0, "Wrong");
    EXPECT_EQ(result, 0);
}
TEST(PolynomTest, Third) {

    constexpr int m[6] = {5, 3, 4, 6, 1, 1};
    constexpr Polynom<6> polynom(m, 6);
    constexpr int result = polynom.value(0);
    static_assert(result == 5, "Wrong");
    EXPECT_EQ(result, 5);
}
TEST(PolynomTest, Fourth) {

    constexpr int m[6] = {5, 3, 4, 6, 1, 1};
    constexpr Polynom<6> polynom(m, 6);
    constexpr int result = polynom.value(2);
    static_assert(result == 123, "Wrong");
    EXPECT_EQ(result, 123);
}
