#include "9cc.c"

int main(int argc, char **argv) {
    if (argc != 2) {
        error("引数の個数が不正です");
    }

    user_input = argv[1];
    token = tokenize();
    Node *node = program();

    codegen(node);
    return 0;
}
