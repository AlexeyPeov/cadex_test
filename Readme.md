how to run(tested on windows10 with ninja and g++):

    cmake -DCMAKE_BUILD_TYPE=Release -G "Ninja" -S src -B src/curves_lib_release ;
    cmake --build src/curves_lib_release ;
    cmake -DCMAKE_BUILD_TYPE=Release -G "Ninja" -S . -B build ;
    cmake --build build ;
    build/cadex_test

linux probably:

    cmake -DCMAKE_BUILD_TYPE=Release -G "Ninja" -S src -B src/curves_lib_release &&
    cmake --build src/curves_lib_release &&
    cmake -DCMAKE_BUILD_TYPE=Release -G "Ninja" -S . -B build &&
    cmake --build build &&
    build/cadex_test


