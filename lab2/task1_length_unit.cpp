#include <string>
#include <vector>
#include <cctype>

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

bool isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='('||ch==')') return true;
    return false;
}

std::vector<std::string> tokenizeLengthExpression(const std::string& expression) {
    // TODO: 将长度表达式拆分为数值、单位、运算符和括号。
    std::vector<std::string> tokens;

    std::size_t i=0;
    while(i<expression.size()){
        char ch=expression[i];
        if(std::isspace(ch)){
            i++;
            continue;
        }
        if(isOperator(ch)){
            tokens.push_back(std::string(1,ch));
            i++;
        }
        else{
            std::size_t start=i;
            while(i<expression.size()&&!std::isspace(expression[i])
                &&!isOperator(expression[i])) i++;
            tokens.push_back(expression.substr(start,i-start));
        }
    }
    return tokens;
}

LengthUnit parseLengthUnit(const std::string& unitText) {
    // TODO: 将 "mm"、"cm"、"dm" 和 "m" 转换为 LengthUnit。
    if(unitText=="mm") return LengthUnit::Millimeter;
    if(unitText=="cm") return LengthUnit::Centimeter;
    if(unitText=="dm") return LengthUnit::Decimeter;
    if(unitText=="m") return LengthUnit::Meter;
    return LengthUnit::None;
}

LengthValue parseLengthLiteral(const std::string& literalText) {
    // TODO: 解析带可选长度单位的数字字面量。
    std::size_t pos=0;
    //std::stod将字符串开头数字转换成double，并返回当前读到的位置
    double value=std::stod(literalText,&pos);
    std::string unitText=literalText.substr(pos);
    if(unitText.empty()) return{value,LengthUnit::None,false};
    return {value,parseLengthUnit(unitText),true};
}

LengthUnit findSmallestUnit(const std::vector<LengthValue>& values) {
    // TODO: 找出表达式中使用的最小单位。
    //这里使用枚举值，举例：
    //static_cast<int>(LengthUnit::Millimeter) // 1
    //static_cast<int>(LengthUnit::Meter)      // 4
    if(values.empty()) return LengthUnit::None;
    LengthUnit min_unit=values[0].unit;
    for(const auto& value:values){
        if(static_cast<int>(value.unit)<static_cast<int>(min_unit)) min_unit=value.unit;
    }
    return min_unit;
}

double convertToUnit(double value, LengthUnit fromUnit, LengthUnit toUnit) {
    // TODO: 将长度数值转换为目标单位。
    int times=static_cast<int>(fromUnit)-static_cast<int>(toUnit);
    for(int i=0;i<times;i++) value*=10;
    return value;
}

bool validateLengthOperands(const std::vector<LengthValue>& values) {
    // TODO: 拒绝混合带单位数值与纯数字的表达式。
    //有单位的操作数
    bool hasUnitOperand=false;
    //无单位的数
    bool hasPlainNumber=false;

    for(const auto& value:values){
        if(value.hasUnit) hasUnitOperand=true;
        else hasPlainNumber=true;
        if(hasPlainNumber&&hasUnitOperand) return false;
    }
    return true;
}

LengthResult evaluateLengthExpression(const std::string& expression) {
    // TODO: 解析表达式、执行校验、统一单位并计算加减运算。
    std::vector<std::string> tokens=tokenizeLengthExpression(expression);
    std::vector<LengthValue> values;
    for(const auto& token:tokens){
        char ch=token[0];
        if(!isOperator(ch)) values.push_back(parseLengthLiteral(token));
    }
    if(!validateLengthOperands(values)) return{false,0.0,LengthUnit::None,"表达式无法计算。"};
    LengthUnit min_unit=findSmallestUnit(values);
    for(auto& it:values){
        it.value=convertToUnit(it.value,it.unit,min_unit);
        it.unit=min_unit;
    }
    return {false, 0.0, LengthUnit::None, ""};
}

std::string formatLengthResult(const LengthResult& result) {
    // TODO: 将结果数值及其单位名称格式化为字符串。
    return {};
}
