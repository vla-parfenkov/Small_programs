#include <iostream>

long NumberPiramid (long** table, int blocks)
{


    for (int k = 0; k <= blocks ; ++k) {
        for (int n = 0; n <= blocks ; ++n) {
            if( k == 0 && n == 0 ){
                table[n][k] = 1;
            }else {
                if ( k == 0) {
                    table[n][k] = 0;
                } else {
                    if (n >= k) {
                        table[n][k] = table[n - k][k] + table[n][k - 1];
                    } else {
                        table[n][k] = table [n][n];
                    }
                }
            }
        }
    }



    return table[blocks][blocks];

}


int main() {

    int blocks = 0;

    std::cin >> blocks;


    long** table = new long* [blocks + 1];

    for (int i = 0; i <= blocks; ++i) {

        table[i] = new long[blocks + 1];

    }


    std::cout << NumberPiramid(table, blocks);

    for (int i = 0; i <= blocks; ++i) {

        delete[] table[i];

    }

    delete[] table;
    return 0;
}


