#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <random>
#include <fstream>
#include <string>
#include "to_far.h"

const int M = 12;
const float N = 40;

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(-N, N);

    std::array<float, M> arr;
    std::vector<float> vec;
    std::list<float> lst;
    std::deque<float> dq;

    for (int i = 0; i < M; i++) {
        arr[i] = dist(gen);
        vec.push_back(dist(gen));
        lst.push_back(dist(gen));
        dq.push_back(dist(gen));
    }

    std::vector<long> res_vec;
    std::list<long> res_lst;
    std::deque<long> res_dq;
    std::array<long, M> res_arr;

    for (int i = 0; i < M; i++)
        res_vec.push_back(randik::toFahrenheit<float, long>(arr[i]));

    for (auto it = vec.begin(); it != vec.end(); it++)
        res_lst.push_back(randik::toFahrenheit<float, long>(*it));

    for (float x : lst)
        res_dq.push_back(randik::toFahrenheit<float, long>(x));

    for (int i = 0; i < M; i++)
        res_arr[i] = randik::toFahrenheit<float, long>(dq[i]);

    
    std::vector<std::string> rows;

    auto it_lst = lst.begin();
    auto it_res_lst = res_lst.begin();

    for (int i = 0; i < M; i++) {
    std::string row = "| " + std::to_string(arr[i])  + " | " + std::to_string(res_vec[i])
                    + " | " + std::to_string(vec[i])  + " | " + std::to_string(*it_res_lst)
                    + " | " + std::to_string(*it_lst) + " | " + std::to_string(res_dq[i])
                    + " | " + std::to_string(dq[i])   + " | " + std::to_string(res_arr[i])
                    + " |";
    rows.push_back(row);

    it_lst++;
    it_res_lst++;
    }

    std::ofstream file("table.md");

    file << "| array (float) | vector (long) | vector (float) | list (long) "
            "| list (float) | deque (long) | deque (float) | array (long) |" << std::endl;
    file << "|---|---|---|---|---|---|---|---|" << std::endl;

    for (const std::string &r : rows)
        file << r << std::endl;

    file.close();
    std::cout << "Таблица записана в table.md" << std::endl;

    return 0;
}