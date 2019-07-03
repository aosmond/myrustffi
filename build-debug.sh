cargo build
clang++-8 -O0 test.cpp -lmyrustffi -pthread -ldl -L ./target/debug/ -o ./target/debug/myrustffi
