#include<iostream>
using namespace std;
class A
{ int a;
  public:
  A(int k)
  { a=k;
  }
  void show()
  { cout<<a;
  }
  A *operator->()
  { return this;
  }
};
int main()
{ A ob1(4);
  ob1.show();
  ob1->show();
  return 0;
}
