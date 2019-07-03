cargo build
clang++ -std=c++11 test.cpp -lmyrustffi -pthread -ldl -L ./target/debug/ -o ./target/debug/myrustffi
