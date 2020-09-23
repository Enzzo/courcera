#pragma once

class Node {
public:
	virtual bool Evaluate() = 0;
};

class EmptyNode : public Node {
public:
	virtual bool Evaluate() override;
};

class DateComparisonNode : public Node {
public:
	virtual bool Evaluate() override;
};

class EventComparisonNode : public Node {
public:
	virtual bool Evaluate() override;
};

class LogicalOperationNode : public Node {
public:
	virtual bool Evaluate() override;
};