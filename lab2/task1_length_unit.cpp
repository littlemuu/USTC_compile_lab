#include <string>
#include <vector>

enum class LengthUnit {
    None,
    Millimeter,
    Centimeter,
    Decimeter,
    Meter
};

struct LengthValue {
    double value;
    LengthUnit unit;
    bool hasUnit;
};

struct LengthResult {
    bool ok;
    double value;
    LengthUnit unit;
    std::string message;
};

std::vector<std::string> tokenizeLengthExpression(const std::string& expression) {
    // TODO: 将长度表达式拆分为数值、单位、运算符和括号。
    return {};
}

LengthUnit parseLengthUnit(const std::string& unitText) {
    // TODO: 将 "mm"、"cm"、"dm" 和 "m" 转换为 LengthUnit。
    return LengthUnit::None;
}

LengthValue parseLengthLiteral(const std::string& literalText) {
    // TODO: 解析带可选长度单位的数字字面量。
    return {0.0, LengthUnit::None, false};
}

LengthUnit findSmallestUnit(const std::vector<LengthValue>& values) {
    // TODO: 找出表达式中使用的最小单位。
    return LengthUnit::None;
}

double convertToUnit(double value, LengthUnit fromUnit, LengthUnit toUnit) {
    // TODO: 将长度数值转换为目标单位。
    return value;
}

bool validateLengthOperands(const std::vector<LengthValue>& values) {
    // TODO: 拒绝混合带单位数值与纯数字的表达式。
    return false;
}

LengthResult evaluateLengthExpression(const std::string& expression) {
    // TODO: 解析表达式、执行校验、统一单位并计算加减运算。
    return {false, 0.0, LengthUnit::None, ""};
}

std::string formatLengthResult(const LengthResult& result) {
    // TODO: 将结果数值及其单位名称格式化为字符串。
    return {};
}
