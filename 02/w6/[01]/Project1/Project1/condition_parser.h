#pragma once

#include "node.h"

#include <memory>
#include <iostream>

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation {
    And,
    Or
};

std::shared_ptr<Node> ParseCondition(std::istream&);

void TestParseCondition();