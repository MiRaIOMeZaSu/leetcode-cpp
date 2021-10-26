//
// Created by timeC on 2021/3/13.
//

#ifndef INC_772_CALCULATE_SOLUTION_H
#define INC_772_CALCULATE_SOLUTION_H


#include <cstring>

using namespace std;

class Solution {
public:
    /**
     * @param s: the expression string
     * @return: the answer
     */
    int solve(string &s, int *i) {
        int size = s.size();
        int result = 0;
        int num = 0;
        int solution = 0;
        char lastOperator = '+';

        while (i[0] < size) {
            if (s[i[0]] == ' ') {
            } else if (s[i[0]] == '(') {
                i[0]++;
                switch (lastOperator) {
                    case '+':
                        solution += +solve(s, i);
                        break;
                    case '-':
                        solution = -solve(s, i);
                        break;
                        // 下一个是数字
                    case '*':
                        solution = solution * solve(s, i);
                        break;
                    case '/':
                        solution =  solution/ solve(s, i);
                        break;
                        // 下一个是数字
                }
            } else if (s[i[0]] == ')') {
                return result + solution;
            } else if (isdigit(s[i[0]])) {
                num = num * 10 + (s[i[0]] - '0');
                if ((i[0] + 1 < size && !isdigit(s[i[0] + 1])) || i[0] + 1 >= size) {
                    // 此时可以开始计算
                    switch (lastOperator) {
                        case '+':
                            solution = num;
                            break;
                        case '-':
                            solution = -num;
                            break;
                            // 下一个是数字
                        case '*':
                            solution = solution * num;
                            break;
                        case '/':
                            solution = solution / num;
                            break;
                            // 下一个是数字
                    }
                    num = 0;
                }
            } else {
                lastOperator = s[i[0]];
                if (lastOperator == '+' || lastOperator == '-') {
                    result += solution;
                    solution = 0;
                }
            }
            i[0]++;
        }
        return result + solution;
    }

    int calculate(string &s) {
        int n[1] = {0};
        int *i = n;
        return solve(s, i);
    }
};


#endif //INC_772_CALCULATE_SOLUTION_H
