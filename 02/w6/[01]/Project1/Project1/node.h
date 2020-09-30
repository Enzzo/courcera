#pragma once
#include "date.h"
#include <string>

enum class LogicalOperation {
	And,
	Or
};

class Node {
public:
	virtual bool Evaluate(const Date&, const std::string&) const = 0;
};

class EmptyNode : public Node {
public:
	virtual bool Evaluate(const Date&, const std::string&) const override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(Comparison, const Date&);
	virtual bool Evaluate(const Date&, const std::string&) const override;
};

class EventComparisonNode : public Node {
public:
	virtual bool Evaluate(const Date&, const std::string&) const override;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation, const std::shared_ptr<Node>, const std::shared_ptr<Node>);
	virtual bool Evaluate(const Date&, const std::string&) const override;
};