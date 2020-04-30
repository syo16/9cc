#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    TK_RESERVED, // Keywords or punctuations
    TK_IDENT, // Identifiers
    TK_NUM, // Integer literals
    TK_EOF, // End-of-file markets
} TokenKind;

typedef struct Token Token;

struct Token {
    TokenKind kind;
    Token *next;
    long val;
    char *str;
    int len;
};

void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);
bool consume(char *op);
Token *consume_ident(void);
void expect(char *op);
long expect_number(void);
bool at_eof(void);
Token *tokenize(void);

extern char *user_input;
extern Token *token;

typedef enum {
    ND_ADD, // +
    ND_SUB, // -
    ND_MUL, // *
    ND_DIV, // /
    ND_EQ,  // ==
    ND_NE,  // !=
    ND_LT,  // <
    ND_LE,  // <=
    ND_ASSIGN, // =
    ND_RETURN, // "return"
    ND_EXPR_STMT, // Expression statement
    ND_VAR, // Variable
    ND_NUM, // Integer
} NodeKind;

typedef struct Node Node;

struct Node {
    NodeKind kind; // Node kind
    Node *next; // Next node
    Node *lhs; // Left-hand side
    Node *rhs; // Right-hand side
    char name; // Used if kind == ND_VAR
    long val; // Used if kind == ND_NUM
};


Node *program(void);

void codegen(Node *node);
