#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "exam.h"

#include <vector>
#include <string>

/***
 * -------------------------------------------------------------------------------------------------------------------
 * 题目
 * -------------------------------------------------------------------------------------------------------------------
 * 无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。并将结果按字符串从小到大排序
 * 
 * 示例1:
 * - 输入：S = "qwe"
 * - 输出：["eqw", "ewq", "qew", "qwe", "weq", "wqe"]
 * 
 * 示例2:
 * - 输入：S = "ab"
 * - 输出：["ab", "ba"]
 * 
 * 要求：
 * 1. 使用纯C语言修改exam.h文件，通过所有单元测试。
 * 2. 代码逻辑符合题目要求，判卷评分有更多单元测试项。
 * 3. 输出结果按照字典顺序排序。
 * 4. exam.h以外的文件不得修改，修改会被覆盖。
 */
using testing::ElementsAre;
using namespace std;

class PrepareTest:public testing::Test {
};


TEST_F(PrepareTest, test1){
    auto res = permute_string("qw");
    vector<string> vs;
    auto p = res;
    while (*p) {
        vs.push_back(*p);
        ++p;
    }
    EXPECT_THAT(vs, ElementsAre("qw", "wq"));
}



TEST_F(PrepareTest, test0){
    auto res = permute_string("qwe");
    vector<string> vs;
    auto p = res;
    while (*p) {
        vs.push_back(*p);
        ++p;
    }
    EXPECT_THAT(vs, ElementsAre("eqw", "ewq", "qew", "qwe", "weq", "wqe"));
}
TEST_F(PrepareTest, test2){
    auto res = permute_string("q");
    vector<string> vs;
    auto p = res;
    while (*p) {
        vs.push_back(*p);
        ++p;
    }
    EXPECT_THAT(vs, ElementsAre("q"));
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
