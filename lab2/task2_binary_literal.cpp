#include <string>
#include <vector>

struct BinaryToken {
    std::string text;
    bool isBinaryLiteral;
};

struct BinaryResult {
    bool ok;
    int value;
    std::string message;
};

std::vector<BinaryToken> tokenizeBinaryExpression(const std::string& expression) {
    // TODO: 拆分表达式，并标记其中的二进制字面量。
    return {};
}

bool isBinaryLiteral(const std::string& token) {
    // TODO: 检查标记是否以 0b 或 0B 开头，且仅包含 0 和 1。
    return false;
}

int binaryLiteralToDecimal(const std::string& literal) {
    // TODO: 将如 0b1010 的二进制字面量转换为十进制。
    return 0;
}

std::string replaceBinaryLiterals(const std::string& expression) {
    // TODO: 将表达式中的每个二进制字面量替换为十进制形式。
    return {};
}

BinaryResult evaluateBinaryExpression(const std::string& expression) {
    // TODO: 转换二进制字面量，再计算算术表达式。
    return {false, 0, ""};
}

std::string formatBinaryResult(const BinaryResult& result) {
    // TODO: 格式化十进制结果或错误信息。
    return {};
}
