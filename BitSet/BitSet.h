#pragma once

namespace Mycode
{
	template<size_t N>
	class bitset
	{
	public:

		bitset()
		{
			_a.resize(N / 32 + 1);
		}
		//x对应的二进制位掷成1

		void set(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			_a[i] |= (1 << j);

		}

		//x对应的二进制位掷成0
		void reset(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			_a[i] &= (~(1 << j));
		}

		//判断对应的二进制位是0还是1
		bool test(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			return _a[i] & (1 << j);
		}
	private:
		vector<int> _a;
	};

	template<size_t N>
	class twobitset
	{
	public:
		void set(size_t x)
		{
			if (!_bs1.test(x) && !_bs2.test(x))
			{
				_bs2.set(x);
			}
			else if (!_bs1.test(x) && _bs2.test(x))
			{
				_bs1.set(x);
				_bs2.reset(x);
			}
		}

		bool is_once(size_t x)
		{
				return !_bs1.test(x) && _bs2.test(x);
		}
	private:
		bitset<N> _bs1;
		bitset<N> _bs2;
	};
}