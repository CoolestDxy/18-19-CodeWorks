//P287N02 用C++抽象类定义一个最小堆并给出实现
//P287N03
template <typename T>
class MinPQ
{
  public:
	virtual ~MinPQ();
	virtual bool isEmpty() const = 0;
	virtual const T &top() const = 0;
	virtual push(const T &) = 0;
	virtual void pop() = 0;
};
//P296N01
//P298N02
//P304N01
//P304N04