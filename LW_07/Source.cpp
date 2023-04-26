#include <iostream>
#include <cassert> // assert
#include <cmath>// sqrt и fabs
using namespace std;
struct Expression
{
public:
	virtual double evaluate() const = 0;
	virtual ~Expression() {}
};
struct Number :public Expression
{
	Number(double value) : value_(value) {}
	double value() const { return value_; }
	double evaluate() const override { return value_; }
private:
	double value_;
};
struct BinaryOperation : Expression
{
	enum {
		PLUS = '+',
		MINUS = '-',
		DIV = '/',
		MUL = '*'
	};
	BinaryOperation(Expression const* left, int op, Expression const* right) :left_(left), op_(op), right_(right)
	{
		assert(left_ && right_);
	}
	~BinaryOperation()
	{
		delete left_;
		delete right_;
	}
	Expression const* left() const { return left_; }
	Expression const* right() const { return right_; }
	int operation() const { return op_; }

	double evaluate() const
	{
		double left = left_->evaluate();
		double right = right_->evaluate();
		switch (op_)
		{
		case PLUS: return left + right;
		case MINUS: return left - right;
		case DIV: return left / right;
		case MUL: return left * right;
		}
		assert(0);
		return 0.0;
	}
private:
	Expression const* left_;
	Expression const* right_;
	int op_;
};
struct FunctionCall : Expression
{
	enum {
		SQR = '\|',
		ABS = 'mod'
	};
	FunctionCall(Expression const* chislo, int op) :chislo_(chislo), op_(op)

	{
		assert(chislo_);
	}
	~FunctionCall()
	{
		delete chislo_;
	}
	Expression const* chislo() const { return chislo_; }
	int operation() const { return op_; }
	double evaluate() const
	{
		double chislo = chislo_->evaluate();
		switch (op_)
		{
		case SQR: return sqrt(chislo);
		case ABS: return abs(chislo);
		}
		assert(0);
		return 0.0;
	}
private:
	Expression const* chislo_;
	int op_;
};
int main1()
{
	//1
	Expression* e1 = new Number(1.234);
	Expression* e2 = new Number(-1.234);
	Expression* e3 = new BinaryOperation(e1, BinaryOperation::DIV, e2);
	cout << e1->evaluate() << " /  " << e2->evaluate() << " = " << e3->evaluate() << endl;
	//2
	Expression* n32 = new Number(32.0);
	Expression* n16 = new Number(16.0);
	Expression* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
	Expression* callSqrt = new FunctionCall(minus, FunctionCall::SQR);
	Expression* n2 = new Number(2.0);
	Expression* mult = new BinaryOperation(n2, BinaryOperation::MUL, callSqrt);
	Expression* callAbs = new FunctionCall(callSqrt, FunctionCall::ABS);
	cout << n32->evaluate() << " - " << n16->evaluate() << " = " << minus->evaluate() << endl;
	cout << "\\|" << minus->evaluate() << " = " << callSqrt->evaluate() << endl;
	cout << n2->evaluate() << " * " << callSqrt->evaluate() << " = " << mult->evaluate() << endl;
	cout << "|" << callSqrt->evaluate() << "|" << " = " << callAbs->evaluate() << endl;
	return 0;
}
