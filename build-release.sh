cargo build --release
clang++-8 -O2 test.cpp -lmyrustffi -pthread -ldl -L ./target/release/ -o ./target/release/myrustffi
