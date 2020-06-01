#include "common.h"



namespace Expr {

 int Value::Evaluate() const {
     return val_;
 }
 std::string Value::ToString() const {
     return std::to_string(val_);
 }
 int Sum::Evaluate() const {
     return left_->Evaluate() + right_->Evaluate();
 }
 std::string Sum::ToString() const {
     return "(" + left_->ToString() + ")" + "+" + "(" + right_->ToString() + ")";
 }
 int Product::Evaluate() const {
     return left_->Evaluate() * right_->Evaluate();
 }
 std::string Product::ToString() const {
   return "(" + left_->ToString() + ")*(" + right_->ToString() + ")"; 
 }

}







std::unique_ptr<Expression> Value(int value)
{
	return std::make_unique<Expr::Value>(value);
}


ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right)
{
	return std::make_unique<Expr::Sum>(std::move(left), std::move(right));
}


ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right)
{
	return std::make_unique<Expr::Product>(std::move(left), std::move(right));
}