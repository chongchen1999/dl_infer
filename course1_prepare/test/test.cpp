// Created by fss on 23-6-4.
//
#include <glog/logging.h>
#include <gtest/gtest.h>

#include <armadillo>
TEST(test_prepare, prepare1) {
    using namespace arma;
    arma::fmat a1 = "1,2,3;"
                    "4,5,6;"
                    "7,8,9;";
    arma::fmat a2 = a1;
    std::cout << a2 * a1 << std::endl;
}

TEST(test_prepare, prepare2) {
    using namespace arma;
    arma::fmat a1 = "1,1,1;"
                    "1,1,1;"
                    "1,1,1;";
    // Multiply matrix a1 by 2
    a1 *= 2;
    for (int i = 0; i < a1.size(); ++i) {
        ASSERT_EQ(a1.at(i), 2);
    }
}

TEST(test_prepare, prepare3) {
    using namespace arma;
    arma::fmat a1 = "1,1,1;"
                    "2,2,2;"
                    "3,3,3;";

    arma::fmat a2 = "1,2,3;"
                    "4,5,6;"
                    "7,8,9;";

    arma::fmat a3;
    // Perform element-wise multiplication of a1 and a2
    a3 = a1 % a2;

    arma::fmat a4 = "1,2,3;"
                    "8,10,12;"
                    "21,24,27;";

    for (int i = 0; i < a3.size(); ++i) {
        ASSERT_EQ(a3.at(i), a4.at(i));
    }
}