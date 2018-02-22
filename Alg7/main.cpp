#include <iostream>
#include <vector>
#include <algorithm>




int main() {

    std::vector <long> Mass;
    std::vector <long> Power;

    long i = 0;
    long j = 0;

    while ( std::cin >> i >> j ){
        Mass.push_back(i);
        Power.push_back(j);
    }

    sort( Mass.begin(), Mass.end() );
    sort( Power.begin(), Power.end() );


    long CurentMass = Mass[0];
    long CurentHigh = 1;


    for (int k = 1; k < Mass.size(); ++k) {

        if( Power[k] >= CurentMass){
            CurentMass += Mass[k];
            CurentHigh++;
        }
    }

    std::cout << std::endl <<  CurentHigh;



    return 0;
}