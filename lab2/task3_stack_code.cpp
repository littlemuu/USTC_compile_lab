#include <string>
#include <vector>

enum class TokenType {
    Number,
    Plus,
    Minus,
    Multiply,
    Divide,
    LeftParen,
    RightParen
};

struct ArithmeticToken {
    TokenType type;
    std::string text;
};

enum class OpCode {
    Push,
    Add,
    Sub,
    Mul,
    Div
};

struct Instruction {
    OpCode op;
    std::string operand;
};

std::vector<ArithmeticToken> tokenizeArithmeticExpression(const std::string& expression) {
    // TODO: 将表达式拆分为数值、运算符和括号。
    return {};
}

int operatorPrecedence(TokenType tokenType) {
    // TODO: 返回 +、-、* 和 / 的运算优先级。
    return 0;
}

std::vector<ArithmeticToken> toReversePolishNotation(const std::vector<ArithmeticToken>& tokens) {
    // TODO: 将中缀标记序列转换为逆波兰表示法。
    return {};
}

Instruction makePushInstruction(const std::string& value) {
    // TODO: 为操作数生成 PUSH 指令。
    return {OpCode::Push, value};
}

Instruction makeOperatorInstruction(TokenType operatorType) {
    // TODO: 根据运算符标记生成 ADD、SUB、MUL 或 DIV 指令。
    return {OpCode::Add, ""};
}

std::vector<Instruction> generateStackCode(const std::string& expression) {
    // TODO: 根据算术表达式生成栈式虚拟机指令。
    return {};
}

std::string formatInstruction(const Instruction& instruction) {
    // TODO: 将单条指令转换为输出文本。
    return {};
}

std::vector<std::string> formatInstructionList(const std::vector<Instruction>& instructions) {
    // TODO: 将全部指令转换为可打印的文本行。
    return {};
}
