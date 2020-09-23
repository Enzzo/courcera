#pragma once
#include "date.h"
#include <string>

class Node {
public:
	virtual bool Evaluate(const Date&, const std::string&) = 0;
};

class EmptyNode : public Node {
public:
	virtual bool Evaluate(const Date&, const std::string&) override;
};

class DateComparisonNode : public Node {
public:
	virtual bool Evaluate(const Date&, const std::string&) override;
};

class EventComparisonNode : public Node {
public:
	virtual bool Evaluate(const Date&, const std::string&) override;
};

class LogicalOperationNode : public Node {
public:
	virtual bool Evaluate(const Date&, const std::string&) override;
};