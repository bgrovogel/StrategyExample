#include <iostream>

using namespace std;

char op;
float num1, num2;

class Strategy {
    public:
      virtual int doOperation(int num1, int num2) = 0;
};

class OperationAdd:public Strategy {
    public:
      int doOperation(int num1, int num2) {
        return num1 + num2;
      }
};

class OperationSubstract:public Strategy {

    public:
      int doOperation(int num1, int num2) {
        return num1 - num2;
      }
};

class OperationMultiply:public Strategy {

   public:
      int doOperation(int num1, int num2) {
        return num1 * num2;
      }
};

class OperationDivide:public Strategy {

   public:
      int doOperation(int num1, int num2) {
        return num1 / num2;
      }
};

class Context {
  private:
    Strategy *strategy;

  public:
    Context(Strategy *new_strategy){
      strategy = new_strategy;
    }
   
    void changeStrategy(Strategy *new_strategy){
      strategy = new_strategy;
    }

    int executeStrategy(int num1, int num2){
      return strategy->doOperation(num1, num2);
   }
};

int main() {

  cout << "Here are some exapmles:";
  cout << "\n";

  OperationAdd add_strategy;
  Context context(&add_strategy);		
  cout << "10 + 5 = ";
  cout << context.executeStrategy(10, 5);
  cout << "\n";

  OperationSubstract subtract_strategy;
  context.changeStrategy(&subtract_strategy);
  cout << "10 - 5 = ";
  cout << context.executeStrategy(10, 5);
  cout << "\n";

  OperationMultiply multiply_strategy;
  context.changeStrategy(&multiply_strategy);
  cout << "10 * 5 = ";
  cout << context.executeStrategy(10, 5);
  cout << "\n";

  OperationDivide divide_strategy;
  context.changeStrategy(&divide_strategy);
  cout << "10 / 5 = ";
  cout << context.executeStrategy(10, 5);
  cout << "\n";

  cout << "Enter operator either + or - or * or /: ";
    cout << "\n";
    cin >> op;
    
    cout << "Enter first operand: ";
    cout << "\n";
    cin >> num1;
    cout << "Enter second operand: ";
    cout << "\n";
    cin >> num2;

    switch(op)
    {
        case '+':
            cout << num1+num2;
            break;

        case '-':
            cout << num1-num2;
            break;

        case '*':
            cout << num1*num2;
            break;

        case '/':
            cout << num1/num2;
            break;

        default:
            cout << "Error! operator is not correct";
            break;
    }
  
}

