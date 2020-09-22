#pragma once

class Node {
public:
	virtual void Evaluate() = 0;
};

class EmptyNode : public Node {
public:
	virtual void Evaluate() override;
};

